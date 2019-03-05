##############################################################################
#
# File: binaryinstallation.nsi
#
# Purpose: This file contains the instructions that the NSIS installer needs
#          in order to create an installation program for VisIt.
#
# Notes:  Copied from binaryinstallation-MSVC8.Net.nsi on August 28, 2009.
#
# Programmer: Kathleen Bonnell 
# Date:       August 28, 2009.
#
# Modifications:
#   Modified to use a defined var (COMPILER) to choose which dlls to install 
#   (MSVC8 or MSVC7).
# 
#   Kathleen Bonnell, Thu April  1 19:10:57 MST 2010
#   Modified to work with install target of new cmake build system.
#   Expects VisItVersion, COMPILER, VISIT_SOURCE_DIR and INSTALL_PREFIX to be 
#   defined on command line. (makensis.exe /DCOMILER= ... etc). 
#
#   Added RequestExecutionLevel so that admin privileges not needed when 
#   installing on Vista and Windows 7.
# 
#   Kathleen Bonnell, Thu Jun 17 20:31:45 MST 2010
#   Change registry keys to HKLM for all-user install (admin required) or HKCU
#   for single-user install.  Makes windows versions > XP happier.
#
#   Kathleen Bonnell, Thu Jul 22 20:00:00 MST 2010
#   Wrap installer and uninstaller in UAC code, requests elevation to admin if
#   user wants to install for all users. Write AppCompat flags to registry if 
#   installing on Vista.
#
#   Kathleen Bonnell, Thu Sep 2 15:47:22 PDT 2010 
#   Add support for 64 bit installs.
#
#   Kathleen Bonnell, Fri Nov 5 16:13:02 PDT 2010 
#   Add Section PythonFilterModules so that PythonFilters will be installed.
#
#   Kathleen Bonnell, Thu Dec 2 10:53:55 MST 2010
#   Re-enable installation of plugin development files. Add links to plugin
#   pages on the WIKI.
#
#   Eric Brugger, Wed Dec 22 10:14:38 PST 2010
#   I corrected a typo in the firewall message.
#
#   Kathleen Bonnell, Fri Jan 14 11:30:53 MST 2011 
#   Corrected a typo in setting of VISITPLUGININSTPUB and VISITPLUGINSTPRI.
#
#   Kathleen Bonnell, Tue Jan 18 22:58:02 MST 2011 
#   Use data from data dir if it is available, otherwise use data found in
#   path determined by environment variable VISIT_DATA_DIR, otherwise error.
#
#   Kathleen Bonnell, Mon Feb 7 16:30:41 MST 2011 
#   Added LibSim.
#
#   Kathleen Bonnell, Wed Apr 20 10:52:15 MST 2011
#   Added .pyd extension files (visit_writer, visitmodule, etc).
#
#   Kathleen Bonnell, Tue Apr 26 09:16:04 MST 2011
#   Added ability to associate curve (.curve, .ultra, .ult, .u) files. 
#
#   Kathleen Bonnell, Wed May 25 08:20:44 MST 2011
#   Modifications to get command-line options working correctly. Changed how
#   INSTDIR is handled so that "LLNL\VisIt <version>" is always appended.
#   Fixed Silo association so that double-clicking works properly again,
#   using silex is now a context-menu option "open with silex".
#
#   Brad Whitlock, Thu Jun  9 22:06:53 PDT 2011
#   I made the "make movie" command for movies made by session files generate
#   MPEG movies. I also added options for PNG frames.
#
#   Kathleen Biagas, Sun Aug 28 23:47:06 MST 2011
#   Do a delete/remove dir component-wise only on installed components based
#   on visit_install.log.  Revert to recursive RMDIR if this file not present,
#   but prompt user to agree. 
#
#   Kathleen Biagas, Wed Aug 31 10:45:11 MST 2011
#   Delete shortcuts one-by-one, instead of recursive delete on directory.
#
#   Kathleen Biagas, Thu Sep 22 18:14:52 MST 2011
#   Fix replacement of 'bdivp' in host profiles. 
#
#   Kathleen Biagas, Thu Sep 15 12:35:55 PDT 2011
#   Added logic to exclude parallel files when necessary, and to install
#   MSMPI redistributable package if not already installed.
#
#   Kathleen Biagas, Fri Sep 23 16:32:10 MST 2011
#   Create a host profile if parallel components installed.
#
#   Brad Whitlock, Thu Dec 1 12:31:34 PST 2011
#   Adding MSVC 2010 support.
#
#   Brad Whitlock, Mon Apr 30 15:02:23 PST 2012
#   Make sure the resources directory gets installed.
#
#   Brad Whitlock, Fri Jun  8 12:02:44 PDT 2012
#   Change which profiles get used for RZ machines since they have 2 versions
#   of their profiles now (one with rzgw, one without).
#
#   Eric Brugger, Wed Jun 13 11:42:55 PDT 2012
#   I added the host profile for rzthriller.
#
#   Kathleen Biagas, Thu Jun 21 15:27:12 MST 2012
#   If plugin-development support is installed, but Parallel components are 
#   not, then turn off VISIT_PARALLEL in PluginVsInstall.cmake
#
#   Brad Whitlock, Tue Sep 24 12:11:23 PDT 2013
#   Add Visual Studio 2012 support.
#
#   Kathleen Biagas, Wed Sep 25 15:24:27 MST 2013
#   Account for new structure of windowsbuild directory.
#
#   Kathleen Biagas, Friday April 4 09:55:27 PDT 2014
#   Remove use of UAC:: in favor of more MS-approved ShellExecEx.
#
#   Kathleen Biagas, Friday April 4 13:13:43 PDT 2014
#   Fix creation of default host-profile to include full host.domain name
#   as hostAlias.
#
#   Kathleen Biagas, Friday March 20 17:34 MST 2015
#   Fix Java preferences registry key to include full path to vist. 
#
#   Kathleen Biagas, Wednesday July 1st, 2015
#   Change 'bdivp' to 'wbronze'.
#
#   Kathleen Biagas, Tuesday June 14, 2016
#   Remove support for compilers older than MSVC 2012. 
#
#   Kathleen Biagas, Tuesday March 20, 2018
#   Remove support for compilers older than MSVC 2017. 
#
###############################################################################

!addPluginDir ".\VIkit"
!addPluginDir ".\NSISPlugins"
!addIncludeDir ".\NSISPlugins"
#!searchparse /noerrors '${MPI_VERSION}' '8' MSMPI8

!define PRODUCT_NAME "VisIt"
!define PRODUCT_VERSION ${VisItVersion}
!define PRODUCT_PUBLISHER "LLNL"
!define PRODUCT_WEB_SITE "http://www.llnl.gov/visit"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\visit${PRODUCT_VERSION}_x64.exe"

!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME} ${PRODUCT_VERSION}"
!define PRODUCT_UNINST_ROOT_KEY "SHCTX"

!define PRODUCT_INST "${PRODUCT_PUBLISHER}\${PRODUCT_NAME} ${PRODUCT_VERSION}"
!define V_INSTDIR_USER  "$LocalAppData\Programs"

!define V_INSTDIR_ADMIN "$ProgramFiles64"
!define VISITINSTDIR "$INSTDIR\${PRODUCT_INST}"
!define V_UNINSTALLER "${VISITINSTDIR}\uninstall_visit.exe"

SetCompressor /SOLID /FINAL lzma

RequestExecutionLevel user

!include "MUI2.nsh"
!include "LogicLib.nsh"
!include "nsDialogs.nsh"
!include "FileFunc.nsh"
!include "VisItMisc.nsh"
!include "X64.nsh"
!include "StrFunc.nsh"
!include "StrSplice.nsh"
!include "ReplaceInFile.nsh"

!ifndef BCM_SETSHIELD
!define BCM_SETSHIELD 0x0000160c
!endif

!define VISIT_DIST_DIR "${VISIT_WINDOWS_DIR}\distribution"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON   "${VISIT_DIST_DIR}\resources\visit.ico"
!define MUI_UNICON "${VISIT_DIST_DIR}\resources\visit.ico"


Name "${PRODUCT_NAME} ${PRODUCT_VERSION}_x64"
OutFile "${INSTALL_PREFIX}\visit${PRODUCT_VERSION}_x64.exe"
ShowInstDetails show
ShowUnInstDetails show


;;;;;;;;;;;;;;; INSTALLER ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
${StrStr}
${StrTrimNewLines}
; Welcome page
!define MUI_PAGE_CUSTOMFUNCTION_PRE "WelcomePre"
!insertmacro MUI_PAGE_WELCOME
; License page
!define MUI_PAGE_CUSTOMFUNCTION_PRE "LicensePre"
!insertmacro MUI_PAGE_LICENSE "${VISIT_SOURCE_DIR}\..\LICENSE"

page custom ChooseUsers ChooseUsersLeave

; Directory page

!define MUI_PAGE_CUSTOMFUNCTION_PRE "DisableBack"
!define MUI_PAGE_CUSTOMFUNCTION_LEAVE "DirectoryLeave"
!define MUI_DIRECTORYPAGE_TEXT_TOP "VisIt will be installed to the following folder with \${PRODUCT_INST} appended to the path.$\r$\n To install to a different base folder, click Browse and select another folder.$\r$\nClick Next to continue."
!insertmacro MUI_PAGE_DIRECTORY

!insertmacro MUI_PAGE_COMPONENTS

; Custom
page custom CheckForMPI CheckForMPILeave
page custom ChooseDefaultDatabasePlugin ChooseDefaultDatabasePluginLeave
page custom ChooseNetworkConfig ChooseNetworkConfigLeave
page custom ChooseParallelBank ChooseParallelBankLeave
page custom ChooseFileAssociations

; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages

; Language files
!insertmacro MUI_LANGUAGE "English"


; MUI end ------


Var UserInstallSet

Var DefaultDatabase
Var DefaultDatabaseSet

Var InstallUsers
Var InstallUsersSet
Var UserPrivilege

Var AssociatePython
Var AssociatePythonSet
Var AssociateCurves
Var AssociateCurvesSet
Var NetConfig
Var UserConfigSet
Var UserParBank
Var UserParBankSet
Var AcceptLicense
Var SkipWelcome
Var InstallMPI
Var MPIExec
Var NCPUs
Var ParCompSet
Var IsInnerInstance


###############################################################################
#
# Sections with IDS   (for those that can be optional)
#
###############################################################################

Section /o ParallelComponents SEC_PAR
    ; make sure that the wrapper for the MSMPI R2 redist gets compiled
    ; this line happens during compilation of this script, it is included here
    ; rather than the top of the file, for clarity as this is where the wrapper
    ; is needed / used
    ${If} $InstallMPI == 1
      ClearErrors
      Push $9
      StrCpy $9 "$ProgramFiles64"
 
      ; Check for newer mpi (8 and above)
      ${If} ${FileExists} "C:\Program Files\Microsoft MPI\Redist\MSMpiSetup.exe"
          File "/oname=$PLUGINSDIR\MSMpiSetup.exe" "C:\Program Files\Microsoft MPI\Redist\MSMpiSetup.exe"
          ${ShellExecEx} $2 '' '$PLUGINSDIR\MSMpiSetup.exe' '-unattend -minimal' '' 'SW_NORMAL' 3
      ${Else}
          ; extract the 2008 wrapper
          File "/oname=$PLUGINSDIR\ms_mpi.msi" ".\MSMPI_R2\mpi_x64.msi"
          ${ShellExecEx} $2 'runas' 'msiexec' '/qn /i "$PLUGINSDIR\ms_mpi.msi"' '' 'SW_NORMAL' 3
      ${EndIf}
 
      ${If} ${FileExists} "$9\Microsoft MPI\Bin\mpiexec.exe"
          StrCpy $MPIExec "$9\Microsoft MPI\Bin\mpiexec.exe"
      ${ElseIf} ${FileExists} "$9\Microsoft HPC Pack 2008 R2\Bin\mpiexec.exe"
          StrCpy $MPIExec "$9\Microsoft HPC Pack 2008 R2\Bin\mpiexec.exe"
      ${Else}
          StrCpy $MPIExec ""
          MessageBox MB_OK "MSMPI could not be installed."
          !insertmacro UnSelectSection "${SEC_PAR}"
      ${EndIf}
      Pop $9
    ${ElseIf} $InstallMPI == 0
      !insertmacro UnSelectSection "${SEC_PAR}"
    ${EndIf}
    ; if we are still doing parallel
    ${If} ${SectionIsSelected} "${SEC_PAR}"
        ; get full name, stored in $0
        System::Call 'kernel32.dll::GetComputerNameExW(i 3,w .r0,*i ${NSIS_MAX_STRLEN} r1)i.r2'
        ; get short name, stored in $3
        System::Call 'kernel32.dll::GetComputerNameExW(i 4,w .r3,*i ${NSIS_MAX_STRLEN} r1)i.r2'
        ${If} $2 = 1
            SetOutPath "${VISITINSTDIR}\hosts"
            FILE "/oname=host_$3.xml" "host_template.xml"
            !insertmacro _ReplaceInFile "${VISITINSTDIR}\hosts\host_$3.xml" "tempfullhost" "$0"
            !insertmacro _ReplaceInFile "${VISITINSTDIR}\hosts\host_$3.xml" "temphost" "$3"
            !insertmacro _ReplaceInFile "${VISITINSTDIR}\hosts\host_$3.xml" "tempNumProcs" "$NCPUs"
        ${EndIf}
    ${EndIf}
SectionEnd

!system "${BIN_DIR}\CreateDBSections.exe"
!include "${BIN_DIR}\DBSections.txt"

Section DataFiles SEC_DATA
  SetOutPath "${VISITINSTDIR}\data"
  #!insertmacro CompileTimeIfFileExists "${INSTALL_PREFIX}\data\globe.silo" haveVisItDistData
  #!insertmacro CompileTimeIfFileExists "$%VISIT_DATA_DIR%" haveVisItDataDir

#!ifdef haveVisItDistData
  #DetailPrint "using visit dist data " 
  File "${INSTALL_PREFIX}\data\*"
#!else
#  !ifdef haveVisItDataDir
#    DetailPrint "using visit data dir " 
#    File "$%VISIT_DATA_DIR%\*.silo"
#    File "$%VISIT_DATA_DIR%\wave.visit"
#    File "$%VISIT_DATA_DIR%\PDB\db*.pdb"
#    File /nonfatal "$%VISIT_DATA_DIR%\ANALYZE_test_data\*.hdr"
#    File /nonfatal "$%VISIT_DATA_DIR%\ANALYZE_test_data\*.img"
#    File /nonfatal "$%VISIT_DATA_DIR%\ANALYZE_test_data\*.visit"
#    File /nonfatal "$%VISIT_DATA_DIR%\FVCOM\*.nc"
#    File /nonfatal "$%VISIT_DATA_DIR%\molecules\crotamine.pdb"
#    File /nonfatal "$%VISIT_DATA_DIR%\molecules\1NTS.pdb"
#    File /nonfatal "$%VISIT_DATA_DIR%\molecules\1UZ9.pdb"
#  !else
#    File "${VISIT_DIST_DIR}\visit_dist_data\*.silo"
#    File "${VISIT_DIST_DIR}\visit_dist_data\*.pdb"
#  !endif
#!endif
  SetOutPath "${VISITINSTDIR}"
SectionEnd

Section HelpFiles SEC_HELP
  SetOutPath "${VISITINSTDIR}"
  File /r "${INSTALL_PREFIX}\help"
SectionEnd

Section /o "Plugin development" SEC_DEV
  SetOutPath "${VISITINSTDIR}"
  File /r "${INSTALL_PREFIX}\lib"
  File /r "${INSTALL_PREFIX}\include"
  ${If} $InstallUsers == "all"
    WriteRegExpandStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITARCHHOME "%VISITLOC%"
    WriteRegExpandStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITPLUGININSTPRI "%APPDATA%\LLNL\VisIt"
    WriteRegExpandStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITPLUGININSTPUB "%VISITLOC%"
  ${Else}
    WriteRegStr HKCU "Environment" VISITARCHHOME "%VISITLOC%"
    WriteRegStr HKCU "Environment" VISITPLUGININSTPRI "%APPDATA%\LLNL\VisIt"
    WriteRegStr HKCU "Environment" VISITPLUGININSTPUB "%VISITLOC%"
  ${EndIf}
  ; propagate the changes so a reboot won't be necessary
  SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000
  ${IfNot} ${SectionIsSelected} ${SEC_PAR}
       !insertmacro _ReplaceInFile "${VISITINSTDIR}\include\PluginVsInstall.cmake" "SET(VISIT_PARALLEL               ON)" "SET(VISIT_PARALLEL               OFF)" 
  ${EndIf}
SectionEnd

Section /o "LibSIM" SEC_LIBSIM
  SetOutPath "${VISITINSTDIR}"
  File /nonfatal /r "${INSTALL_PREFIX}\libsim"
SectionEnd

!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC_PAR} "Parallel components. Currently requires mpiexec."

  !insertmacro MUI_DESCRIPTION_TEXT ${SEC_DP} "Removing un-needed database plugins may help improve startup performance of some components, but you will need to re-run the installer to get them back."

  !insertmacro MUI_DESCRIPTION_TEXT ${SEC_DATA} "Sample data files"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC_HELP} "VisIt's help files"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC_DEV} "Plugin development components. Note that you must have Microsoft Visual Studio 2017 to develop plugins compatible with this binary VisIt distribution."

  !insertmacro MUI_DESCRIPTION_TEXT ${SEC_LIBSIM} "VisIt's libsim files"
!insertmacro MUI_FUNCTION_DESCRIPTION_END




###############################################################################
#
# Functions
#
###############################################################################

Function ParseCommandLine
  ;Read command line options
  ${GetParameters} $R0

  ${GetOptions} $R0 "-INNERINSTANCE" $R1
  ${If} ${Errors}
      StrCpy $IsInnerInstance false
  ${Else}
      StrCpy $IsInnerInstance true
  ${EndIf}

  ; Help with this installer
  ;${GetOptions} $R0 "/help" $R1
  ;${IfNot} ${Errors}
  ; Need to figure out how to display usage information.
  ;${EndIf}

  ; installation directory
  StrCpy $UserInstallSet false
  ${GetOptions} $R0 "/D" $R1
  ${IfNot} ${Errors}
      DetailPrint "Command line option /D used with value: $R1"
      StrCpy $UserInstallSet true
      StrCpy $INSTDIR $R1
  ${EndIf}

  ; site-config file
  ${GetOptions} $R0 "-SITE" $R1
  ${If} ${Errors}
      StrCpy $UserConfigSet false
      StrCpy $NetConfig "None"
  ${Else}
      DetailPrint "Command line option -SITE used with value: $R1"
      StrCpy $NetConfig $R1
      ${If} $NetConfig == "llnl_open"
          StrCpy $NetConfig "llnl"
      ${EndIf}
      StrCpy $UserConfigSet true
  ${EndIf}

  ; ParallelBank
  ${GetOptions} $R0 "-PB" $R1
  ${If} ${Errors}
      StrCpy $UserParBankSet false
      StrCpy $UserParBank ""
  ${Else}
      DetailPrint "Command line option -PB used with value: $R1"
      StrCpy $UserParBank $R1
      StrCpy $UserParBankSet true
  ${EndIf}

  ; default DatabasePlugin
  ${GetOptions} $R0 "-DB" $R1
  ${If} ${Errors}
      StrCpy $DefaultDatabaseSet false
      Strcpy $DefaultDatabase "None"
  ${Else}
      DetailPrint "Command line option -DB used with value: $R1"
      StrCpy $DefaultDatabaseSet true
      Strcpy $DefaultDatabase $R1
  ${EndIf}

  ; current users

  ; all users
  ${GetOptions} $R0 "-ALLUSERS" $R1
  ${If} ${Errors}
      ${GetOptions} $R0 "-CURRENTUSER" $R1
      ${If} ${Errors}
          StrCpy $InstallUsers "current"
          StrCpy $InstallUsersSet "false"
      ${Else}
          DetailPrint "Command line option -CURRENTUSER used"
          StrCpy $InstallUsers "current"
          StrCpy $InstallUsersSet "true"
      ${EndIf}
  ${Else}
      DetailPrint "Command line option -ALLUSERS used"
      StrCpy $InstallUsers "all"
      StrCpy $InstallUsersSet "true"
  ${EndIf}

  ; plugin development libs
  ${GetOptions} $R0 "-DEV" $R1
  ${IfNot} ${Errors}
      DetailPrint "Command line option -DEV used"
      SectionSetFlags ${SEC_DEV} 1
  ${EndIf}

  ; associate .py files with VisIt
  ${GetOptions} $R0 "-AssociatePython" $R1
  ${If} ${Errors}
      StrCpy $AssociatePythonSet false
      StrCpy $AssociatePython 0 
  ${Else}
      DetailPrint "Command line option -AssociatePython used"
      StrCpy $AssociatePython 1 
      StrCpy $AssociatePythonSet true
  ${EndIf}

  ; associate .curve,.ultra,.ult,.u files with VisIt
  ${GetOptions} $R0 "-AssociateCurves" $R1
  ${If} ${Errors}
      StrCpy $AssociateCurvesSet false
      StrCpy $AssociateCurves 0 
  ${Else}
      DetailPrint "Command line option -AssociateCurves used"
      StrCpy $AssociateCurves 1 
      StrCpy $AssociateCurvesSet true
  ${EndIf}

  ; add lib sim
  ${GetOptions} $R0 "-LIBSIM" $R1
  ${IfNot} ${Errors}
      DetailPrint "Command line option -LIBSIM used"
      SectionSetFlags ${SEC_LIBSIM} 1
  ${EndIf}

  ; do not add parallel components
  StrCpy $ParCompSet "false"
  ${GetOptions} $R0 "-NOPAR" $R1
  ${IfNot} ${Errors}
      DetailPrint "Command line option -NOPAR used"
      StrCpy $ParCompSet "true"
      SectionSetFlags ${SEC_PAR} 0
  ${EndIf}

  ; These options were created for another project that includes VisIt's
  ; installer inside theirs, they don't want to show a second Welcome
  ; and License page 

  ; skip the license page when not in SILENT mode
  ${GetOptions} $R0 "-ACCEPT" $R1
  ${If} ${Errors}
      StrCpy $AcceptLicense false
  ${Else}
      DetailPrint "Command line option -ACCEPT used"
      StrCpy $AcceptLicense true
  ${EndIf}

  ; skip the welcome page when not in SILENT mode
  ${GetOptions} $R0 "-SKIP" $R1
  ${If} ${Errors}
      StrCpy $SkipWelcome false
  ${Else}
      DetailPrint "Command line option -SKIP used"
      StrCpy $SkipWelcome true
  ${EndIf}

  ClearErrors
  ;EnumRegKey $0 SHCTX "Software\Python\PythonCore\2.5\InstallPath" 0
  ;${If} ${Errors} 
  ;    Strcpy $CreatePythonRegKeys "yes"
  ;    ClearErrors
  ;${Else}
  ;    Strcpy $CreatePythonRegKeys "no"
  ;${EndIf}
FunctionEnd

Function ElevatePrivilege
    ${If} $InstallUsers == "all"
        ${IfNot} $UserPrivilege == "Admin"
            GetDlgItem $9 $HWNDParent 1
            System::Call user32::GetFocus()i.s
            EnableWindow $9 0 ;disable next button
            ClearErrors
            ${ShellExecEx} $2 'runas' $EXEPATH '-INNERINSTANCE -SKIP -ALLUSERS -ACCEPT' '' 'SW_NORMAL' 1
            ${If} $2 <> -1
                EnableWindow $9 1
                System::Call user32::SetFocus(is)
            ${Else}
                MessageBox mb_iconExclamation "Unable to elevate"
                Abort
            ${EndIf}
            Quit ;We now have a new process, the install will continue 
                 ;there, we have nothing left to do here
        ${EndIf}
    ${EndIf}
FunctionEnd

Function InstallUsersChanged
    ${If} $InstallUsers == "all"
        SetShellVarContext all
        ${IfNot} ${Silent} 
          ${If} $UserInstallSet == false
          ${OrIf} $INSTDIR == ""
              StrCpy $INSTDIR "${V_INSTDIR_ADMIN}"
          ${EndIf}
        ${EndIf}
    ${Else}
        SetShellVarContext current
        ${IfNot} ${Silent} 
          ${If} $UserInstallSet == false
          ${OrIf} $INSTDIR == ""
              StrCpy $INSTDIR "${V_INSTDIR_USER}"
          ${EndIf}
        ${EndIf}
    ${EndIf}
FunctionEnd

Function .onInit
    ${IfNot} ${RunningX64}
        MessageBox MB_OK "This setup is for installing on 64bit systems only."
        Abort
    ${EndIf}

    call ParseCommandLine
    ClearErrors
    UserInfo::GetAccountType
    Pop $UserPrivilege

    ${If} $IsInnerInstance == true
    ${AndIfNot} $UserPrivilege == "Admin"
        SetErrorLevel 0x666666 ;special return value for outer instance so it 
                               ; knows we did not have admin rights
        Quit
    ${EndIf}

    ${If} $InstallUsersSet == false
      StrCpy $InstallUsers "current"
      ${IfThen} $UserPrivilege == "Admin" ${|} StrCpy $InstallUsers "all" ${|}
    ${EndIf}
    call InstallUsersChanged

    ${If} ${Silent}
    ${AndIf} $INSTDIR == "" ;defaults (for silent installs)
        SetSilent normal
        call InstallUsersChanged
        SetSilent silent
    ${EndIf}
    ${If} ${Silent}
        Call ElevatePrivilege
    ${EndIf}

    ; find out how many cpus there are
    cpudesc::tell
    Pop $0
    ; get the part of the output string describing the number of cpus
    StrCpy $NCPUs $0 2 73
    ; convert it to an integer (ignore leading zeroes, it's not octal)
    IntOp $NCPUs 1$NCPUs - 100
    ${If} $ParCompSet == "false"
        ${If} $NCPUs > 1
            !insertmacro SelectSection "${SEC_PAR}"
        ${Else}
            !insertmacro UnSelectSection "${SEC_PAR}"
      ${EndIf}
    ${EndIf}
FunctionEnd

Function DisableBack
    ${If} $UserInstallSet == true
        ; still need to call the leave function so that write permissions 
        ; are tested.
        call DirectoryLeave
        Abort
    ${EndIf}
    ${If} $IsInnerInstance == true
        GetDlgItem $0 $HWNDParent 3
        EnableWindow $0 0
    ${EndIf}
FunctionEnd

Function RemoveNextBtnShield
    GetDlgItem $0 $hwndParent 1
    SendMessage $0 ${BCM_SETSHIELD} 0 0
FunctionEnd


Function WelcomePre
  ${If} $SkipWelcome == true
    Abort
  ${EndIf}
FunctionEnd

Function LicensePre
  ${If} $AcceptLicense == true
  ${OrIf} $AcceptLicense == "yes"
    Abort
  ${EndIf}
FunctionEnd


# This is called when user exits the Installation path page (directory page)
# We want to test if the user has access privileges to write to the directory
Function DirectoryLeave
      Push $0
      Push $1
      ClearErrors
      ${If} ${FileExists} "${VISITINSTDIR}"
          ClearErrors
          FileOpen $0 "${VISITINSTDIR}\test.txt" w
          ${If} ${Errors}
              Strcpy $1 "error"
          ${Else}
              FileWrite $0 "hello"
              ${If} ${Errors}
                  Strcpy $1 "error"
              ${EndIf}
          ${EndIf}
      ${Else}
          CreateDirectory "${VISITINSTDIR}"
          ${If} ${Errors}
              Strcpy $1 "error"
          ${EndIf}
      ${EndIf}
  
      ${If} $1 == "error"
          MessageBox MB_OK 'Cannot write to "${VISITINSTDIR}", please choose a different directory'
          Pop $1
          Pop $0
          Abort
      ${Else}
         #MessageBox MB_OK 'Write to "${VISITINSTDIR}" okay, proceeding'
          FileClose $0
          Delete "${VISITINSTDIR}\test.txt"
          Pop $1
          Pop $0
      ${EndIf}
FunctionEnd


#
# This function is called when we show the Choose users screen.
#
Function ChooseUsers
    ${If} $InstallUsersSet == true
        Call ElevatePrivilege
        Abort ; so that the Leave function isn't called
    ${EndIf}

    !insertmacro MUI_HEADER_TEXT "User selection" "Select the desired user configuration."
    nsDialogs::Create /NOUNLOAD 1018
    Pop $9

    ${NSD_OnBack} RemoveNextBtnShield
    ${NSD_CreateLabel} 5u 5u 90% 24u "Do you want VisIt installed for all users or only for the Current user?"
    Pop $0

    System::Call "advapi32::GetUserName(t.r0,*i${NSIS_MAX_STRLEN})i"
    ${NSD_CreateRadioButton} 22u 39u 40% 12u "Single User ($0)"
    Pop $0
    nsDialogs::SetUserData $0 "current"
    ${NSD_OnClick} $0 UsersClicked
    ${NSD_Check} $0

    ${NSD_CreateRadioButton} 22u 54u 40% 12u "All Users"
    Pop $2 
    nsDialogs::SetUserData $2 "all"
    ${NSD_OnClick} $2 UsersClicked
    Push $2 ; store allusers radio hwnd on stack
    nsDialogs::show 
    Pop $2
FunctionEnd

Function UsersClicked
    Pop $1
    nsDialogs::GetUserData $1
    Pop $1
    GetDlgItem $0 $hwndParent 1
    SendMessage $0 ${BCM_SETSHIELD} 0 $1
FunctionEnd

Function ChooseUsersLeave 
    ${If} $InstallUsersSet == false
        ; get info from the ChooseUsers dialog
        pop $0  ;get hwnd
        push $0 ;and put it back
        ${NSD_GetState} $0 $9
        ${If} $9 = 0
            StrCpy $InstallUsers "current"
            Call InstallUsersChanged
        ${Else}
            StrCpy $InstallUsers "all"
            Call InstallUsersChanged
        ${EndIf}
    ${EndIf}

    Call ElevatePrivilege
FunctionEnd

#
# This function is called when we show the Network configuration screen.
#
Function ChooseNetworkConfig
   ${If} $UserConfigSet == false
       File "/oname=$PLUGINSDIR\networks.dat" "${VISIT_SOURCE_DIR}\resources\hosts\networks.dat"
       !insertmacro MUI_HEADER_TEXT "Network configuration" "Select the desired network configuration."

       Var /GLOBAL NetConfigLB
       Var /GLOBAL Datfile
       Var /GLOBAL Line
       Var /GLOBAL Desc
       Var /GLOBAL Tag
       Var /GLOBAL Tags
       nsDialogs::Create 1018
       Pop $0
       ${If} $0 == error
           Abort 
       ${EndIf}


       ${NSD_CreateListBox} 15u 0u 85% 99% $R4
       Pop $NetConfigLB
      
       ${NSD_LB_AddString} $NetConfigLB "None"
       ; parse all network options from networks.dat
       FileOpen $DatFile "$PLUGINSDIR\networks.dat" r
       FileRead $DatFile $Line
       StrCpy $Tags ""
       ClearErrors
       ${DoUntil} ${Errors} 
           !insertmacro StrSplice "$Desc" "$Line" "1" ":"
            Pop $Tag
            ${StrTrimNewLines} $Tag $Tag
            StrCpy $Tags "$Tags:$Tag"
            ${StrStr} $1 $Desc "RZ only"
            ${If} $1 == ``
                ${NSD_LB_AddString} $NetConfigLB $Desc
            ${EndIf}
            FileRead $DatFile $Line
       ${LoopUntil} 1 = 0
       FileClose $DatFile
       ${NSD_LB_SelectString} $NetConfigLB "None"
       nsdialogs::show
   ${EndIf}
FunctionEnd

Function ChooseNetworkConfigLeave
   ${If} $UserConfigSet == false
       SendMessage $NetConfigLB ${LB_GETCURSEL} 0 0 $1
       !insertmacro StrSplice $5 "$Tags" "$1" ":"
       Pop $4 ; the selected tag
       StrCpy $NetConfig $4
   ${EndIf}
FunctionEnd


#
# This function is called when we show the Choose parallel bank screen.
#
Function ChooseParallelBank
  ${If} $UserParBankSet == false
      ${If} $NetConfig == "llnl"
      ${OrIf} $NetConfig == "llnl_closed"
    !insertmacro MUI_HEADER_TEXT "Parallel bank selection" \
      "Select the desired parallel bank."
    Var /GLOBAL ParallelBankText
    Var /GLOBAL ParallelBank
    nsDialogs::Create 1018
    Pop $0
    ${If} $0 == error
        Abort
    ${EndIf}

    ${NSD_CreateLabel} 5u 5u 90% 34u "If you use a batch system that requires you to use a bank when submitting parallel jobs, enter the name of the bank now." 
    Pop $0

    ${NSD_CreateText} 46u 46u 40% 12u "wbronze"
    Pop $ParallelBankText
    ; prevents stack corruption since we aren't using a notify function
    GetFunctionAddress $0 OnStackSpam

    nsDialogs::Show
     ${EndIf}
  ${EndIf}
FunctionEnd

Function ChooseParallelBankLeave
    ${NSD_GetText} $ParallelBankText $ParallelBank
FunctionEnd


Function ChooseDefaultDatabasePlugin
    ${If} $DefaultDatabaseSet == "false"
        !insertmacro MUI_HEADER_TEXT "Select default database reader plugin" \
          "Select the database reader plugin that VisIt will try first when opening a database."

    Var /GLOBAL DefaultDatabaseLB
        nsDialogs::Create 1018
        Pop $0
        ${If} $0 == error
            Abort
        ${EndIf}

        ${NSD_CreateLabel} 5u 5u 90% 48u "A default database reader plugin is the first plugin that VisIt will use when trying to open a database.  In most cases, it is not necessary to specify a default database reader plugin but it can help VisIt pick the right database reader plugin when there are mulitple database reader plugins that are associated with a given file extension."
        Pop $0

        ${NSD_CreateListBox} 20u 62u 60% 100 $R4
        Pop $DefaultDatabaseLB

        ${NSD_LB_AddString} $DefaultDatabaseLB "None"

    ; find all selected db's 

    StrCpy $9 ${SEC_DP_0}
    StrCpy $8 ${NumDBPlugins}
    IntOp $8 $8 - 1
    ${For} $R0 0 $8
        ${If} ${SectionIsSelected} $9
            SectionGetText $9 $R2
            ${NSD_LB_AddString} $DefaultDatabaseLB $R2
        ${EndIf}
        IntOp $9 $9 +  1
    ${Next}

        ${NSD_LB_SelectString} $DefaultDatabaseLB "None"

        nsdialogs::show
    ${EndIf}
FunctionEnd

Function ChooseDefaultDatabasePluginLeave
    ${If} $DefaultDatabaseSet == "false"
        ${NSD_LB_GetSelection} $DefaultDatabaseLB $DefaultDatabase
    ${EndIf}
FunctionEnd

Function OnStackSpam
    Pop $0
FunctionEnd

#
# Allow the user to choose whether python script files will be associated 
# with VisIt.
#
Function ChooseFileAssociations
  ${If} $AssociatePythonSet == false 
  ${OrIf} $AssociateCurvesSet == false
    !insertmacro MUI_HEADER_TEXT "Associate File types with VisIt" \
      "Associating file types with VisIt allows you to double click the file which will start VisIt and open the file"

    nsDialogs::Create 1018
    Pop $0
    ${If} $0 == error
      Abort
    ${EndIf}

    ${NSD_CreateCheckBox} 22u 48u 90% 12u "Python (*.py)  -- will start VisIt's cli and run the script."
    Pop $0
    ${If} $AssociatePythonSet == true
    ${AndIf} $AssociatePython == 1
        ${NSD_Check} $0
    ${EndIf}
    ${NSD_OnClick} $0 PythonAssocChecked

    ${NSD_CreateCheckBox} 22u 78u 90% 12u "Curve files (*.curve, *.ultra, *.ult, *.u) -- will start VisIt and open the file"
    Pop $0
    ${If} $AssociateCurvesSet == true
    ${AndIf} $AssociateCurves == 1
        ${NSD_Check} $0
    ${EndIf}
    ${NSD_OnClick} $0 CurveAssocChecked

    nsDialogs::show
  ${EndIf}
FunctionEnd

Function PythonAssocChecked
  Pop $0
  ${NSD_GetState} $0 $AssociatePython
FunctionEnd

Function CurveAssocChecked
  Pop $0
  ${NSD_GetState} $0 $AssociateCurves
FunctionEnd

Function CheckForMPI
    StrCpy $InstallMPI 2

    Push $9
    StrCpy $9 "$ProgramFiles64"
    ${If} ${SectionIsSelected} ${SEC_PAR}
    ${AndIf} $NCPUs > 1
       ${If} ${FileExists} "$9\Microsoft HPC Pack 2008 R2\Bin\mpiexec.exe"
          StrCpy $MPIExec "$9\Microsoft HPC Pack 2008 R2\Bin\mpiexec.exe"
       ${ElseIf} ${FileExists} "$9\Microsoft MPI\Bin\mpiexec.exe"
          StrCpy $MPIExec "$9\Microsoft MPI\Bin\mpiexec.exe"
       ${Else}
          StrCpy $MPIExec ""
          StrCpy $InstallMPI 0 
          ${If} $UserPrivilege == "Admin"
            StrCpy $InstallMPI 1 
            Call CheckForMPILeave
          ${Else}
            !insertmacro MUI_HEADER_TEXT "MSMPI R2 installation" "Installation of files necessary to VisIt's parallel engine"

            nsDialogs::Create 1018
            Pop $0
            ${If} $0 == error
              Abort
            ${EndIf}

            ${NSD_CreateLabel} 5u 5u 90% 24u "Files needed to run VisIt's parallel engine (MSMPI from HPC PACK 2008 R2) do not appear to be installed on this machine.  Your options are:"

            ${NSD_CreateRadioButton} 22u 45u 90% 12u "Skip install of VisIt's parallel components"
            Pop $0
            nsDialogs::SetUserData $0 0
            ${NSD_OnClick} $0 InstallMPIClicked
            ${NSD_Check} $0

            ${NSD_CreateRadioButton} 22u 60u 90% 12u "Attempt the install of MSMPI as Admin "
            Pop $0
            nsDialogs::SetUserData $0 1
            ${NSD_OnClick} $0 InstallMPIClicked

            ${NSD_CreateRadioButton} 22u 75u 90% 12u "Skip install of MSMPI, but still install VisIt's parallel components."
            Pop $0
            nsDialogs::SetUserData $0 2
            ${NSD_OnClick} $0 InstallMPIClicked
            nsDialogs::show
          ${EndIf}
       ${EndIf}
    ${Else}
        StrCpy $MPIExec ""
        !insertmacro UnSelectSection "${SEC_PAR}"
    ${EndIF}
    Pop $9
FunctionEnd

Function InstallMPIClicked
    Exch $0
    nsDialogs::GetUserData $0
    Pop $InstallMPI
    Pop $0
FunctionEnd
 
Function CheckForMPILeave
    ${If} $InstallMPI == 0
      !insertmacro UnSelectSection "${SEC_PAR}"
    ${EndIf}
FunctionEnd


###############################################################################
#
# Sections
#
###############################################################################

Section -PlotPlugins 
  SetOutPath "${VISITINSTDIR}\plots"
  ${If} ${SectionIsSelected} ${SEC_PAR}
      File "${INSTALL_PREFIX}\plots\*.dll"
  ${Else}
      File /x "*_par.dll" "${INSTALL_PREFIX}\plots\*.dll"
  ${EndIf}
SectionEnd

Section -OperatorPlugins 
  SetOutPath "${VISITINSTDIR}\operators"
  ${If} ${SectionIsSelected} ${SEC_PAR}
      File "${INSTALL_PREFIX}\operators\*.dll"
  ${Else}
      File /x "*_par.dll" "${INSTALL_PREFIX}\operators\*.dll"
  ${EndIf}
SectionEnd

Section -ExecutableComponents
  !insertmacro UpdateShellVarContext "$InstallUsers"
  SetOutPath "${VISITINSTDIR}"
  SetOverwrite ifnewer
  ${If} ${SectionIsSelected} ${SEC_PAR}
      File "${INSTALL_PREFIX}\*.dll"
  ${Else}
      File /x "*_par.dll" "${INSTALL_PREFIX}\*.dll"
  ${EndIf}
  ${If} ${SectionIsSelected} ${SEC_PAR}
      File /x visit${VisItVersion}_x64.exe "${INSTALL_PREFIX}\*.exe"
  ${Else}
      File /x visit${VisItVersion}_x64.exe /x "*_par.exe" "${INSTALL_PREFIX}\*.exe"
  ${EndIf}
  File "${VISIT_DIST_DIR}\installation\xml2plugin.bat"
  File "${INSTALL_PREFIX}\makemovie.py"
  File "${INSTALL_PREFIX}\makemoviemain.py"
  File "${INSTALL_PREFIX}\visitcinema.py"
  File "${INSTALL_PREFIX}\visitcinemamain.py"
  File "${INSTALL_PREFIX}\visitdiff.py"

  File /r "${INSTALL_PREFIX}\qtplugins"
  File "${INSTALL_PREFIX}\qt.conf"

  # Silex file
  File /nonfatal "${INSTALL_PREFIX}\silex.exe" 
  # browser file
  File /nonfatal "${INSTALL_PREFIX}\browser.exe" 

  # Icon files
  File "${VISIT_DIST_DIR}\resources\*.ico"

SectionEnd

Section -PythonModules
  SetOutPath "${VISITINSTDIR}\lib"
  File /r "${INSTALL_PREFIX}\lib\python"
  File /nonfatal "${INSTALL_PREFIX}\lib\*.pyd"
  SetOutPath "${VISITINSTDIR}"
SectionEnd

Section -PythonFilterModules
  SetOutPath "${VISITINSTDIR}\lib"
  File /r "${INSTALL_PREFIX}\lib\site-packages"
  SetOutPath "${VISITINSTDIR}"
SectionEnd

Section -UltraWrapper
  SetOutPath "${VISITINSTDIR}"
  File /r "${INSTALL_PREFIX}\ultrawrapper"
SectionEnd

Section -Resources
  SetOutPath "${VISITINSTDIR}"
  File /r /x CMakeLists.txt "${INSTALL_PREFIX}\resources"
SectionEnd

Section -AllHosts
  ${IfNot} $NetConfig == "None"
      StrCpy $0 "${VISITINSTDIR}\resources\hosts\$NetConfig"
      StrCpy $1 "${VISITINSTDIR}\hosts"
      CreateDirectory $1
      ${If} $NetConfig == "anag"
          StrCpy $2 "${VISITINSTDIR}\resources\hosts\nersc"
          CopyFiles $2\*.xml $1
      ${Else}
          CopyFiles $0\*.xml $1
      ${EndIf}
   
      CopyFiles "$0\config"    "${VISITINSTDIR}"
      CopyFiles "$0\guiconfig" "${VISITINSTDIR}"
      CopyFiles "$0\visitrc"   "${VISITINSTDIR}"

      ; config, guiconfig, or visitrc may not have existed.
      ClearErrors

      ${If}   $NetConfig == "llnl"
      ${OrIf} $NetConfig == "llnl_closed"
          ${IfNot} $ParallelBank == "wbronze"
              FindFirst $R1 $R2 "${VISITINSTDIR}\hosts\host_llnl*.xml"
              ${Unless} ${Errors}
                ${Do}
                    !insertmacro _ReplaceInFile "${VISITINSTDIR}\hosts\$R2" "wbronze" "$ParallelBank"
                    FindNext $R1 $R2
                ${LoopUntil} ${Errors}
                FindClose $R1
              ${EndUnless}
          ${EndIf}
      ${EndIf}
      StrCpy $UserConfigSet true
      SetOutPath "${VISITINSTDIR}"
  ${EndIf}
  SetOutPath "${VISITINSTDIR}"
SectionEnd

Section -PlatformsDLL
  SetOutPath "${VISITINSTDIR}"
  File /nonfatal /r "${INSTALL_PREFIX}\platforms"
SectionEnd

Section -AddVisItRegKeys
#
# This section installs the VISIT<version> key, which tells visit.exe where
# to find the rest of the VisIt components. Note that we put keys in 
# HKEY_LOCAL_MACHINE or in HKEY_CURRENT_USER.
#
  SetRegView 64

  ; our regular registry entries 
  WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "" ""
  WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "VISITHOME" "${VISITINSTDIR}"
  

  ${IfNot} $DefaultDatabase == "None"
    Strcpy $0 "-assume_format $DefaultDatabase"
    WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" \
                      "VISITARGS" \
                      $0
  ${EndIf}
 
  # Store a flag in the registry to aid in Uninstall
  WriteRegStr HKLM "Software\Classes\VISIT${PRODUCT_VERSION}" "InstalledAllUsers" "$InstallUsers"

  ${IfNot} $MPIExec == ""
    ${If} $InstallUsers == "all"
      WriteRegExpandStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISIT_MPIEXEC "$MPIExec"
    ${Else}
      WriteRegStr HKCU "Environment" VISIT_MPIEXEC "$MPIExec"
    ${EndIf}
   ${EndIf}
SectionEnd

Section -CreateLinks
  Strcpy $R0 "$SMPROGRAMS\VisIt ${PRODUCT_VERSION}"
  CreateDirectory "$R0"

  CreateShortCut "$R0\VisIt ${PRODUCT_VERSION}.lnk"  \
     "${VISITINSTDIR}\visit.exe" ""      \
     "" 0  \
     SW_SHOWMINIMIZED  \
     ""  \
     "VisIt allows you to visualize simulation data."

  CreateShortCut "$R0\VisIt ${PRODUCT_VERSION} in stereo.lnk"  \
      "${VISITINSTDIR}\visit.exe" "-stereo"      \
      "" 0  \
      SW_SHOWMINIMIZED  \
      ""  \
      "VisIt allows you to visualize simulation data in stereo."

  CreateShortCut "$DESKTOP\VisIt ${PRODUCT_VERSION}.lnk" \
      "${VISITINSTDIR}\visit.exe" ""      \
      "" 0  \
      SW_SHOWMINIMIZED  \
      ""  \
      "VisIt allows you to visualize simulation data."

  CreateShortCut "$R0\VisIt Command Line Interface.lnk"  \
      "${VISITINSTDIR}\visit.exe" "-cli"  \
      "" 0  \
      SW_SHOWNORMAL     \
      ""  \
      "VisIt's command line interface allows you to visualize simulation data via Python scripting."

  CreateShortCut "$R0\VisIt with Debug logging.lnk"  \
      "${VISITINSTDIR}\visit.exe" "-debug 5"  \
      "" 0  \
      SW_SHOWNORMAL     \
      ""  \
      "VisIt allows you to visualize simulation data."

  ${If} ${SectionIsSelected} ${SEC_PAR}
      CreateShortCut "$R0\VisIt parallel.lnk"  \
          "${VISITINSTDIR}\visit.exe" "-np $NCPUs"  \
          "" 0  \
          SW_SHOWNORMAL     \
          ""  \
          "VisIt with a parallel engine."
  ${EndIf}

  CreateShortCut "$R0\Silex.lnk"                         \
      "${VISITINSTDIR}\silex.exe"  \
      ""      \
      ""  \
      0  \
      SW_SHOWNORMAL     \
      ""  \
      "Silex allows you to browse the contents of Silo files."

  # Optionally add a link for xmledit.
  ${If} ${SectionIsSelected} ${SEC_DEV}
      CreateDirectory "$R0\Plugin development" 
      CreateShortCut "$R0\Plugin development\XML Edit.lnk"  \
          "${VISITINSTDIR}\xmledit.exe"  \
          ""  \
          ""  \
          0  \
          SW_SHOWNORMAL     \
          ""  \
          "XMLEdit allows you to edit the XML files that describe VisIt's plugins."
      CreateDirectory "$R0\Plugin development\Documentation"
      CreateShortCut "$R0\Plugin development\Documentation\Plot plugins.lnk" \
           "http://www.visitusers.org/index.php?title=Adding_a_new_plot"
      CreateShortCut "$R0\Plugin development\Documentation\Operator plugins.lnk" \
           "http://www.visitusers.org/index.php?title=Adding_a_new_operator"
      CreateShortCut "$R0\Plugin development\Documentation\Building plugins.lnk" \
           "http://www.visitusers.org/index.php?title=Building_plugins_using_CMake"
      CreateShortCut "$R0\Plugin development\Documentation\VTK classes.lnk" \
          "http://www.vtk.org/doc/release/5.0/html/classes.html"
      CreateShortCut "$R0\Plugin development\Documentation\Qt classes.lnk" \
          "http://doc.trolltech.com/4.6/classes.html"
      CreateShortCut "$R0\Plugin development\Documentation\Python library.lnk" \
          "http://docs.python.org/lib/lib.html"
      CreateShortCut "$R0\Plugin development\Documentation\VisIt and HDF5.lnk" \
           "http://www.visitusers.org/index.php?title=VisIt_and_HDF5"
    ${EndIf}
SectionEnd

Section -AddFileAssociations
  # Associate the Silo file format with VisIt and Silex.
  SetRegView 64
  WriteRegStr SHCTX "Software\Classes\.silo" "" "siloFile"
  WriteRegStr SHCTX "Software\Classes\siloFile" "" "Silo File"
  WriteRegStr SHCTX "Software\Classes\siloFile\DefaultIcon" "" "${VISITINSTDIR}\silo.ico"
  WriteRegStr SHCTX "Software\Classes\siloFile\shell\open\command" "" '${VISITINSTDIR}\visit.exe -o "%1"'
  WriteRegStr SHCTX "Software\Classes\siloFile\shell\open with Silex\command" "" '${VISITINSTDIR}\silex.exe "%1"'

  # Associate the VisIt file format with VisIt.
  WriteRegStr SHCTX "Software\Classes\.visit" "" "visitFile"
  WriteRegStr SHCTX "Software\Classes\visitFile" "" "VisIt File"
  WriteRegStr SHCTX "Software\Classes\visitFile\DefaultIcon" "" "${VISITINSTDIR}\visitfile.ico"
  WriteRegStr SHCTX "Software\Classes\visitFile\shell\open\command" "" '${VISITINSTDIR}\visit.exe -o "%1"'

  # Associate the VisIt session file format with VisIt.
  WriteRegStr SHCTX "Software\Classes\.vses" "" "visitSessionFile"
  WriteRegStr SHCTX "Software\Classes\.session" "" "visitSessionFile"
  WriteRegStr SHCTX "Software\Classes\visitSessionFile" "" "VisIt Session File"
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\DefaultIcon" "" "${VISITINSTDIR}\visitsessionfile.ico"
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make movie\command"          "" '${VISITINSTDIR}\visit.exe -movie -format mpeg -sessionfile "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 480x480 movie\command"  "" '${VISITINSTDIR}\visit.exe -movie -format mpeg -geometry 480x480 -sessionfile "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 640x480 movie\command"  "" '${VISITINSTDIR}\visit.exe -movie -format mpeg -geometry 640x480 -sessionfile "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 800x600 movie\command"  "" '${VISITINSTDIR}\visit.exe -movie -format mpeg -geometry 800x600 -sessionfile "%1\'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 1024x768 movie\command" "" '${VISITINSTDIR}\visit.exe -movie -format mpeg -geometry 1024x768 -sessionfile "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 480x480 PNG frames\command"  "" '${VISITINSTDIR}\visit.exe -movie -format png -geometry 480x480 -sessionfile "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 640x480 PNG frames\command"  "" '${VISITINSTDIR}\visit.exe -movie -format png -geometry 640x480 -sessionfile "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 800x600 PNG frames\command"  "" '${VISITINSTDIR}\visit.exe -movie -format png -geometry 800x600 -sessionfile "%1\'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Make 1024x768 PNG frames\command" "" '${VISITINSTDIR}\visit.exe -movie -format png -geometry 1024x768 -sessionfile "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\Edit\command" "" 'notepad.exe "%1"'
  WriteRegStr SHCTX "Software\Classes\visitSessionFile\shell\open\command" "" '${VISITINSTDIR}\visit.exe -sessionfile "%1"'
 
  # Python files 
  # save the value for uninstall
  WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "AssociatedPythonWithVisIt" "$AssociatePython"
  ${If} $AssociatePython == 1
    # Associate python files with VisIt.
    WriteRegStr SHCTX "Software\Classes\.py" "" "visitPythonFile"
    WriteRegStr SHCTX "Software\Classes\visitPythonFile" "" "VisIt Python File"
    WriteRegStr SHCTX "Software\Classes\visitPythonFile\DefaultIcon" "" "${VISITINSTDIR}\visitfile.ico"
    WriteRegStr SHCTX "Software\Classes\visitPythonFile\shell\Edit\command" "" 'notepad.exe "%1"'
    WriteRegStr SHCTX "Software\Classes\visitPythonFile\shell\open\command" "" '${VISITINSTDIR}\visit.exe -cli -s "%1"'
  ${EndIf}

  # Curve files 
  # save the value for uninstall
  WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "AssociatedCurvesWithVisIt" "$AssociateCurves"
  ${If} $AssociateCurves == 1 
    # Associate python files with VisIt.
    WriteRegStr SHCTX "Software\Classes\.curve" "" "visitCurveFile"
    WriteRegStr SHCTX "Software\Classes\.ultra" "" "visitCurveFile"
    WriteRegStr SHCTX "Software\Classes\.ult" "" "visitCurveFile"
    WriteRegStr SHCTX "Software\Classes\.u" "" "visitCurveFile"
    WriteRegStr SHCTX "Software\Classes\visitCurveFile" "" "VisIt Curve File"
    WriteRegStr SHCTX "Software\Classes\visitCurveFile\DefaultIcon" "" "${VISITINSTDIR}\visitfile.ico"
    WriteRegStr SHCTX "Software\Classes\visitCurveFile\shell\Edit\command" "" 'notepad.exe "%1"'
    WriteRegStr SHCTX "Software\Classes\visitCurveFile\shell\open\command" "" '${VISITINSTDIR}\visit.exe -o "%1"'
  ${EndIf}
SectionEnd

Section -AddVisItToPath
  ; save value in $R0
  Push $R0

  ; Find out if we want to remove old VisIt versions from path
  Push "${VISITINSTDIR}"
  Push $InstallUsers
  VIkit::FindVisItInPath
  Pop $R0
  ${IfNot} $R0 == ""
      MessageBox MB_YESNO $R0 /SD IDNO IDYES 0 IDNO AddToPath
      Push "${VISITINSTDIR}"
      Push $InstallUsers
      VIkit::RemoveAllVisItInPath
  ${EndIf}

AddToPath:
  Push "${VISITINSTDIR}"
  Push $InstallUsers
  VIkit::AddVisItToPath
  Pop $R0
  Pop $R0
  ${If} $InstallUsers == "all"
    WriteRegStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITLOC "${VISITINSTDIR}"
  ${Else}
    WriteRegStr HKCU "Environment" VISITLOC "${VISITINSTDIR}"
  ${EndIf}
  ; propagate the changes so a reboot won't be necessary
  SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000
SectionEnd

Section -AddJavaInstallPath
   # Call our VIkit DLL to get the ${VISITINSTDIR} variable formatted as a Java preference.
   VIkit::GetInstallPathFormattedForJava
   Pop $R0
   # Write the reformatted string as a Java preference.
   
   Strcpy $R0 "$R0///LLNL///VisIt ${PRODUCT_VERSION}"
   WriteRegStr SHCTX "SOFTWARE\JavaSoft\Prefs\llnl\visit" "/V/I/S/I/T/H/O/M/E" $R0
SectionEnd

Section -FirewallMessage
   ; doesn't work in silent mode, so don't try it :)
   ${IfNot} ${SILENT}
       Push "${VISITINSTDIR}\\visit_install.log"
       Call DumpLog   
   ${EndIf}

    MessageBox MB_ICONINFORMATION|MB_OK "Depending on the settings for Windows Firewall, communication between local VisIt processes and remote VisIt processes may be blocked. If you are not an admin, you may need assistance adding VisIt's processes to the firewall's exception list." /SD IDOK

SectionEnd

Section -AdditionalIcons
  ${DisableX64FSRedirection}
  WriteIniStr "${VISITINSTDIR}\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\VisIt ${PRODUCT_VERSION}\VisIt Home Page.lnk" "${VISITINSTDIR}\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\VisIt ${PRODUCT_VERSION}\Uninstall VisIt ${PRODUCT_VERSION}.lnk" "${V_UNINSTALLER}"
SectionEnd

Section -Post
  SetOutPath -
  WriteUninstaller '${VISITINSTDIR}\uninstall_visit.exe'
  SetRegView 64
  WriteRegStr SHCTX "${PRODUCT_DIR_REGKEY}" "" "${VISITINSTDIR}\visit.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "UninstallString" "${V_UNINSTALLER}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "NoModify" "1"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "NoRepair" "1"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "DisplayIcon" "${VISITINSTDIR}\visit.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" \
      "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


${UnStrStrAdv}
${UnStrTrimNewLines}
  !insertmacro MUI_UNPAGE_INSTFILES

Function un.onUninstSuccess
    HideWindow
    MessageBox MB_ICONINFORMATION|MB_OK \
        "$(^Name) was successfully removed from your computer." /SD IDOK
FunctionEnd

Function un.onInit
    SetRegView 64
    ${DisableX64FSRedirection}

    ReadRegStr $0    HKLM "Software\Classes\VISIT${PRODUCT_VERSION}" "InstalledAllUsers"
    ${If} $0 == "all"
       ClearErrors
       UserInfo::GetAccountType
       Pop $1
       ${IfNot} $1 == "Admin"
           ${ShellExecEx} $3 'runas' '$INSTDIR\uninstall_visit.exe' '' '' 'SW_NORMAL' 1
           ${If} $3 == -1
               MessageBox MB_OK 'Need Admin privileges to uninstall.'
           ${Endif}
           Quit
       ${EndIf}
    ${EndIf}
FunctionEnd


Section Uninstall
    # Read in saved value to know whether VisIt was installed for AllUsers or 
    # current user.
    ReadRegStr $0    HKLM "Software\Classes\VISIT${PRODUCT_VERSION}" "InstalledAllUsers"
    ${If} $0 == "all"
       !insertmacro UpdateShellVarContext "all"
    ${Else}
       !insertmacro UpdateShellVarContext "current"
    ${EndIf}

    ReadRegStr $1 SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "AssociatedPythonWithVisIt"
    ReadRegStr $2 SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "AssociatedCurvesWithVisIt"

    # Remove the desktop shortcut
    Delete "$DESKTOP\VisIt ${PRODUCT_VERSION}.lnk"

    SetRegView 64
    ${DisableX64FSRedirection}

    # Remove the Start menu program group
    Strcpy $R9 "$SMPROGRAMS\VisIt ${PRODUCT_VERSION}"
    Delete "$R9\VisIt ${PRODUCT_VERSION}.lnk"
    Delete "$R9\VisIt ${PRODUCT_VERSION} in stereo.lnk"
    Delete "$R9\VisIt Command Line Interface.lnk"
    Delete "$R9\VisIt with Debug logging.lnk"
    Delete "$R9\VisIt parallel.lnk"
    Delete "$R9\Silex.lnk"
    Delete "$R9\VisIt Home Page.lnk"
    Delete "$R9\Uninstall VisIt ${PRODUCT_VERSION}.lnk"
    Delete "$R9\Plugin development\XML Edit.lnk"
    Delete "$R9\Plugin development\Documentation\Plot plugins.lnk"
    Delete "$R9\Plugin development\Documentation\Operator plugins.lnk"
    Delete "$R9\Plugin development\Documentation\Building plugins.lnk"
    Delete "$R9\Plugin development\Documentation\VTK classes.lnk"
    Delete "$R9\Plugin development\Documentation\Qt classes.lnk" 
    Delete "$R9\Plugin development\Documentation\Python library.lnk" 
    Delete "$R9\Plugin development\Documentation\VisIt and HDF5.lnk"
    RmDir "$R9\Plugin development\Documentation"
    RmDir "$R9\Plugin development" 
    RMDir "$R9"

    # Remove all of the VisIt software components
    ${If} ${FileExists} "$INSTDIR\visit_install.log"
        var /global line2
        var /global delpath
        var /global parsedline
        FileOpen $R0 "$INSTDIR\visit_install.log" r
        FileRead $R0 $line2
        StrCpy $delpath ""
        StrCpy $R9 0
       ${DoUntil} $line2 == ""
           ${UnStrTrimNewLines} $R1 "$line2"
           ${UnStrStrAdv} $parsedline $R1 "Output folder: " ">" ">" "0" "0" "0"
           ${If} $parsedline != ""
               ${If} $delpath != ""
                   IntOp $R9 $R9 + 1
                   push $delpath
               ${EndIf}
               StrCpy $delpath "$parsedline"
           ${Else}
               ${UnStrStrAdv} $R2 $R1 "Extract: " ">" ">" "0" "0" "0"
               ${If} $R2 != ""
                   ${UnStrStrAdv} $R3 $R2 "..." ">" "<" "0" "0" "0" 
                   ${If} $R3 != ""
                       StrCpy $parsedline $R3
                   ${Else}
                       StrCpy $parsedline $R2
                   ${EndIF}
               ${Else}     
                   StrCpy $parsedline ""
               ${EndIF}
               ${If} $parsedline != ""
                   Delete "$delpath\$parsedline"
               ${EndIf}
           ${EndIf} 
           FileRead $R0 $line2
       ${Loop}
       FileClose $R0
       Delete "$INSTDIR\visit_install.log"
       Delete "$INSTDIR\config"
       Delete "$INSTDIR\guiconfig"
       Delete "$INSTDIR\visitrc"
       Delete "$INSTDIR\hosts\*.xml"
       RmDir  "$INSTDIR\hosts"
       ClearErrors
       ${ForEach} $R8 $R9 1 - 1
           Pop $delpath
           ${If} $delpath != "${VISITINSTDIR}"
               RmDir "$delpath"
           ${EndIf} 
           ClearErrors
       ${Next}
       delete "$INSTDIR\uninstall_visit.exe"
       delete "$INSTDIR\VisIt.url"
       RmDir /REBOOTOK "$INSTDIR"
       ${UnStrStrAdv} $R9 "$INSTDIR" "LLNL\VisIt ${PRODUCT_VERSION}" ">" "<" "0" "0" "0"
       ${If} ${FileExists} "$R9\LLNL"
           RmDir /REBOOTOK  "$R9\LLNL"
       ${EndIf}
    ${Else}        
        MessageBox MB_OKCANCEL|MB_ICONSTOP "VisIt's uninstaller will be removing the entire directory at $INSTDIR, if this is NOT okay, press CANCEL." /SD IDOK IDOK +1 IDCANCEL +1
        RMDir /r $INSTDIR
    ${EndIf} 

    # Delete the Silo file type from the registry.
    DeleteRegKey SHCTX "Software\Classes\.silo"
    DeleteRegKey SHCTX "Software\Classes\siloFile"
    # Delete the VisIt session file type from the registry.
    DeleteRegKey SHCTX "Software\Classes\.vses"
    DeleteRegKey SHCTX "Software\Classes\.session"
    DeleteRegKey SHCTX "Software\Classes\visitSessionFile"
    # Delete the VisIt file type from the registry.
    DeleteRegKey SHCTX "Software\Classes\.visit"
    DeleteRegKey SHCTX "Software\Classes\visitFile"
    ${If} $1 == 1 
      DeleteRegKey SHCTX "Software\Classes\visitPythonFile"
      DeleteRegKey /ifempty SHCTX "Software\Classes\.py"
    ${EndIf}
    ${If} $2 == 1 
      DeleteRegKey SHCTX "Software\Classes\visitCurveFile"
      DeleteRegKey /ifempty SHCTX "Software\Classes\.curve"
      DeleteRegKey /ifempty SHCTX "Software\Classes\.ultra"
      DeleteRegKey /ifempty SHCTX "Software\Classes\.ult"
      DeleteRegKey /ifempty SHCTX "Software\Classes\.u"
    ${EndIf}

    # Delete the VisIt <version> key registry.
    DeleteRegKey SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}"

    DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
    DeleteRegKey SHCTX "${PRODUCT_DIR_REGKEY}"

    DeleteRegKey SHCTX "SOFTWARE\JavaSoft\Prefs\llnl"
    DeleteRegKey SHCTX "Software\Microsoft\Windows\CurrentVersion\Uninstall\VisIt ${PRODUCT_VERSION}"

    ${If} $0 == "all"
        DeleteRegValue HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITLOC
        DeleteRegValue HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITARCHHOME
        DeleteRegValue HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITPLUGININSTPRI
        DeleteRegValue HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITPLUGININSTPUB
        DeleteRegValue HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISIT_MPIEXEC
    ${Else}
        DeleteRegValue HKCU "Environment" VISITLOC
        DeleteRegValue HKCU "Environment" VISITARCHHOME
        DeleteRegValue HKCU "Environment" VISITPLUGININSTPRI
        DeleteRegValue HKCU "Environment" VISITPLUGININSTPUB
        DeleteRegValue HKCU "Environment" VISIT_MPIEXEC
    ${EndIf}
    Push "$INSTDIR"
    Push $0
    VIkit::RemoveVisItFromPath
    Pop $R0
    SetAutoClose true
    SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000
  SectionEnd


