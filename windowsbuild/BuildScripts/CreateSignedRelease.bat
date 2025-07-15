@echo off
Rem This script will configure and build a signed release of VisIt
Rem Signing requires that the correct certificate has been installed.

Rem CMake and msbuild are each called twice, due to use of a hacked
Rem cmake version which does not create the ALL_BUILD project.
Rem If not using the hacked CMake, can reduce the calls to CMake and msbuild.

Rem This script assumes visit and visit-deps are peer to each other.

@echo off

Rem Get the location of this script
set ScriptDir=%~dp0

Rem set a root dir, relative to this Script
Rem should end up being the parent of 'visit' and 'visit-deps'
set VRootDir=%ScriptDir%..\..\..\

Rem normalizing the path makes reading the output easier
call :normalize "%VRootDir%"


Rem Set the location of windowsbuild dir
set VWinDir=%VRootDir%\visit-deps\windowsbuild

Rem Set the location of visit's src dir
set VSrcDir=%VRootDir%\visit\src

Rem Set the location of the build
set VBldDirName=signed-rel
set VBldDir=%VRootDir%\%VBldDirName%

Rem Get the version being built
<%VsrcDir%\VERSION set /p VVERS=

cd %VRootDir%

Rem Keep current working directory after call to vcvars.
set "VSCMD_START_DIR=%CD%"
call "%PROGRAMFILES%\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"

Rem This is the hash for the current certificate, will need to be updated
Rem if the certificate changes. The certificate needs to be properly
Rem installed on the machine where this script is being run.
Rem set CSHash=0c5beb375cde202ffa7e143a313cbd470aaafe9a
set CSHash=57455396D6BD848A2E9CE47E153A71EF8F266D8A

Rem Going to start with a fresh build directory.
Rem Deleting takes awhile, so move it instead and delete later
Rem Can comment out the next two lines if don't want a fresh build dir.
if EXIST %VBldDirName% move %VBldDirName% delme-%VBldDirName%
mkdir %VBldDirName%

cd %VBldDirName%

"%PROGRAMFILES%\CMake\bin\cmake.exe" ^
-G "Visual Studio 17 2022" ^
-A "x64" ^
-T "host=x64" ^
-DCODESIGN_HASH:STRING=%CSHash% ^
-DVISIT_ENABLE_DATA_MANUAL_EXAMPLES:BOOL=true ^
-DVISIT_PARALLEL:BOOL=true ^
-DVISIT_WINDOWS_DIR:PATH=%VWinDir% ^
-DVISIT_WINDOWS_APPLICATION:BOOL=true ^
%VSrcDir%

"%PROGRAMFILES%\CMake\bin\cmake.exe" ^
-G "Visual Studio 17 2022" ^
-A "x64" ^
-T "host=x64" ^
-DCODESIGN_HASH:STRING=%CSHash% ^
-DVISIT_ENABLE_DATA_MANUAL_EXAMPLES:BOOL=true ^
-DVISIT_PARALLEL:BOOL=true ^
-DVISIT_WINDOWS_DIR:PATH=%VWinDir% ^
-DVISIT_WINDOWS_APPLICATION:BOOL=true ^
%VSrcDir%

Rem build the windev package
msbuild _WINDEV_Package.vcxproj /p:Configuration=Release /m:4 /flp1:warningsonly;logfile=srcpackage.warn /flp2:errorsonly;logfile=srcpackage.error

Rem build the manuals
msbuild doc\manuals.vcxproj /p:Configuration=Release /m:4 /flp1:warningsonly;logfile=manuals.warn /flp2:errorsonly;logfile=manuals.error

Rem build the source
msbuild visit.sln /p:Configuration=Release /m:4 /flp1:warningsonly;logfile=visit.warn /flp2:errorsonly;logfile=visit.error

msbuild visit.sln /p:Configuration=Release /m:4 /flp1:warningsonly;logfile=visit2.warn /flp2:errorsonly;logfile=visit2.error


Rem create the install dir that will be packaged
msbuild INSTALL.vcxproj /p:Configuration=Release /m:4 /flp1:warningsonly;logfile=package.warn /flp2:errorsonly;logfile=package.error

Rem sign the executables that will be packaged
signtool sign /q /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a /sha1 %CSHash% "VisIt%VVERS%"\*.exe "VisIt%VVERS%"\*.dll "VisIt%VVERS%"\databases\*.dll "VisIt%VVERS%"\operators\*.dll "VisIt%VVERS%"\plots\*.dll 

rem signtool sign /q /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a /sha1 %CSHash% "VisIt%VVERS%"\*.dll 

rem signtool sign /q /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a /sha1 %CSHash% "VisIt%VVERS%"\databases\*.dll 
rem signtool sign /q /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a /sha1 %CSHash% "VisIt%VVERS%"\operators\*.dll 
rem signtool sign /q /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a /sha1 %CSHash% "VisIt%VVERS%"\plots\*.dll
 
Rem Create the installer 
msbuild _Package.vcxproj /p:Configuration=Release /m:4 /flp1:warningsonly;logfile=package.warn /flp2:errorsonly;logfile=package.error

Rem Sign the installer 
signtool sign /q /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a /sha1 %CSHash% "visit%VVERS%_x64.exe 


cd %VRootDir%

Rem delete the previous build dir
rd /q /s delme-%VBldDirName%


EXIT /B %ERRORLEVEL%

:normalize
set "VRootDir=%~f1"
EXIT /B 0
