@echo off
Rem This script will configure and build a minimal subset of VisIt,
Rem which can be useful when debugging, as it reduces build time

Rem This script uses VISIT_SELECTED_[DATABASE/PLOT/OPERATOR]_PLUGINS to
Rem determine which plugins to build.

Rem Turning off windows-style application is very helpful for debugging

Rem This script also turns off examples, manuals, data, libsim

Rem Modify these settings according to need. See the CMake command below

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
set VWINDIR=%VRootDir%\visit-deps\windowsbuild

Rem Set the location of visit's src dir
set VSRCDIR=%VRootDir%\visit\src

Rem Set the location of the build
set VBldDirName=reduceBuild
set VBldDir=%VRootDir%\%VBldDirName%

cd %VROOTDIR%

Rem Keep current working directory after call to vcvars.
set "VSCMD_START_DIR=%CD%"
call "%PROGRAMFILES(X86)%\\Microsoft Visual Studio\\2017\\Professional\\VC\\Auxiliary\\Build\\vcvars64.bat"

Rem Going to start with a fresh build directory.
Rem Deleting takes awhile, so move it instead and delete later
Rem Can comment out the next two lines if don't want a fresh build dir.
if EXIST %VBldDirName% move %VBldDirName% delme-%VldDirName%
mkdir %VBldDirName%

cd %VBldDirName%

Rem A simpler cmake command line can be used, if config-site file is
Rem configured correctly. Just need to add -DUSE_REDUCED_BUILD:BOOL=true
REM See steppenwolf.cmake and it's USE_REDUCED_BUILD section

Rem Configure with CMake, may need to edit path to cmake
"%PROGRAMFILES%\CMake\bin\cmake.exe" ^
-G "Visual Studio 15 2017 Win64" ^
-T "host=x64" ^
-DVISIT_ENABLE_ANNOTATION_TOOLS:BOOL=OFF ^
-DVISIT_ENABLE_DATAGEN:BOOL=OFF ^
-DVISIT_ENABLE_DATA_MANUAL_EXAMPLES:BOOL=OFF ^
-DVISIT_ENABLE_DIAGNOSTICS:BOOL=OFF ^
-DVISIT_ENABLE_EXAMPLES:BOOL=OFF ^
-DVISIT_ENABLE_LIBSIM:BOOL=OFF ^
-DVISIT_ENABLE_MANUALS:BOOL=OFF ^
-DVISIT_ENABLE_SILO_TOOLS:BOOL=OFF ^
-DVISIT_BUILD_ALL_PLUGINS:BOOL=OFF ^
-DVISIT_CREATE_XMLTOOLS_GEN_TARGETS:BOOL=OFF ^
-DVISIT_PARALLEL:BOOL=OFF ^
-DVISIT_WINDOWS_APPLICATION:BOOL=OFF ^
-DVISIT_SELECTED_DATABASE_PLUGINS:STRING="VTK;Silo" ^
-DVISIT_SELECTED_PLOT_PLUGINS:STRING="Pseudocolor;Curve" ^
-DVISIT_SELECTED_OPERATOR_PLUGINS:STRING="Slice;Lineout" ^
%VSrcDir%

"%PROGRAMFILES%\CMake\bin\cmake.exe" ^
-G "Visual Studio 15 2017 Win64" ^
-T "host=x64" ^
-DVISIT_ENABLE_ANNOTATION_TOOLS:BOOL=OFF ^
-DVISIT_ENABLE_DATAGEN:BOOL=OFF ^
-DVISIT_ENABLE_DATA_MANUAL_EXAMPLES:BOOL=OFF ^
-DVISIT_ENABLE_DIAGNOSTICS:BOOL=OFF ^
-DVISIT_ENABLE_EXAMPLES:BOOL=OFF ^
-DVISIT_ENABLE_LIBSIM:BOOL=OFF ^
-DVISIT_ENABLE_MANUALS:BOOL=OFF ^
-DVISIT_ENABLE_SILO_TOOLS:BOOL=OFF ^
-DVISIT_BUILD_ALL_PLUGINS:BOOL=OFF ^
-DVISIT_CREATE_XMLTOOLS_GEN_TARGETS:BOOL=OFF ^
-DVISIT_PARALLEL:BOOL=OFF ^
-DVISIT_WINDOWS_APPLICATION:BOOL=OFF ^
-DVISIT_SELECTED_DATABASE_PLUGINS:STRING="VTK;Silo" ^
-DVISIT_SELECTED_PLOT_PLUGINS:STRING="Pseudocolor;Curve" ^
-DVISIT_SELECTED_OPERATOR_PLUGINS:STRING="Slice;Lineout" ^
%VSrcDir%


msbuild visit.sln /p:Configuration=Debug /m:4 /flp1:warningsonly;logfile=visit.warn /flp2:errorsonly;logfile=visit.error

msbuild visit.sln /p:Configuration=Debug /m:4 /flp1:warningsonly;logfile=visit2.warn /flp2:errorsonly;logfile=visit2.error


cd %VRootDir%

rd /q /s delme-%VBldDirName%

EXIT /B %ERRORLEVEL%

:normalize
set "VRootDir=%~f1"
EXIT /B 0
