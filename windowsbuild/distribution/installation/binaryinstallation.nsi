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
#   Kathleen Biagas, Friday January 20, 2020
#   Shorten default install path for single-users to simply the profile dir.
#   Added test for OpenGL version, Mesa3D's opengl32.dll used as drop-in
#   replacement if system OpenGL not sufficient.
#   Put firewall message on Finish page, along with a Mesa warning if needed.
#
#   Kathleen Biagas, Thu Feb 18, 2021
#   Create the Uninstaller first, codesign it if requested by CODESIGN_HASH
#   being defined, and add it to the installer via File command.  Required
#   special logic to call this installer script with the magic flag for
#   creating the uninstaller: "CREATING_UNINSTALLER".
#   Also fixed uninstaller logic to simply remove the folder, as previous logic
#   could leave .pyc files remaining the in the installation folder.
#
#   Kathleen Biagas, Fri July 1, 2022
#   Removed most sections, replaced with ExtractTarball which has logic to
#   install the 7zip file containing everything, and extract to the install
#   location everything except items allowed to be skipped (like specific
#   database plugins).  Retained optional sections, so that user has the
#   ability to choose not to install them (data, help, etc).
#   Removed the space in the install name 'VisIt <version>'->'VisIt<verison>'.
#
#   Kathleen Biagas, Fri Mar 22, 2024
#   Fix bad installation when a lot of DB plugins de-selected. Modified to
#   write the exclusions list to a text file in the temporary directory and
#   pass that to 7z instead of a long list.
#
###############################################################################

!addPluginDir ".\VIkit"
!addPluginDir ".\NSISPlugins"
!addIncludeDir ".\NSISPlugins"


!define PRODUCT_NAME "VisIt"
!define PRODUCT_VERSION ${VisItVersion}
!define PRODUCT_PUBLISHER "LLNL"
!define PRODUCT_WEB_SITE "http://www.llnl.gov/visit"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\visit${PRODUCT_VERSION}_x64.exe"

!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}${PRODUCT_VERSION}"
!define PRODUCT_UNINST_ROOT_KEY "SHCTX"

!define PRODUCT_INST "${PRODUCT_PUBLISHER}\${PRODUCT_NAME}${PRODUCT_VERSION}"
!define V_INSTDIR_USER  "$Profile"

!define V_INSTDIR_ADMIN "$ProgramFiles64"
!define VISITINSTDIR "$INSTDIR\${PRODUCT_INST}"
!define V_UNINSTALLER "${VISITINSTDIR}\uninstall_visit.exe"

RequestExecutionLevel user
Name "${PRODUCT_NAME}${PRODUCT_VERSION}_x64"

!ifdef CREATING_UNINSTALLER
  OutFile "$%TEMP%\tempinstaller.exe"
  SetCompress OFF
  ShowUnInstDetails show
  !include "LogicLib.nsh"
  !include "MUI2.nsh"
  !include "StrFunc.nsh"
  !include "X64.nsh"
  !include "nsDialogs.nsh"
  !include "FileFunc.nsh"
  !include "VisItMisc.nsh"
  !include "StrSplice.nsh"
  !include "ReplaceInFile.nsh"
!else
  !define VISIT_DIST_DIR "${VISIT_WINDOWS_DIR}\distribution"
  SetCompressor /SOLID /FINAL lzma
  !system '$\"${NSISDIR}\makensis$\" /DCREATING_UNINSTALLER /DVisItVersion=${VisItVersion} /DVISIT_DIST_DIR=${VISIT_DIST_DIR} "${__FILE__}"' = 0
  !system "$%TEMP%\tempinstaller.exe" = 2

  ; This should be conditional, based on a var passed in from cmake
  !ifdef CODESIGN_HASH
    !system "signtool sign /tr http://timestamp.digicert.com /td sha256 /fd sha256 /a /sha1 ${CODESIGN_HASH} $%TEMP%\uninstall_visit.exe" = 0
  !endif
  OutFile "${BIN_DIR}\visit${PRODUCT_VERSION}_x64.exe"

  !include "LogicLib.nsh"
  !include "MUI2.nsh"
  !include "StrFunc.nsh"
  !include "X64.nsh"
  !include "nsDialogs.nsh"
  !include "FileFunc.nsh"
  !include "VisItMisc.nsh"
  !include "StrSplice.nsh"
  !include "ReplaceInFile.nsh"

  !ifndef BCM_SETSHIELD
    !define BCM_SETSHIELD 0x0000160c
  !endif


  ; MUI Settings
  !define MUI_ABORTWARNING
  !define MUI_ICON   "${VISIT_DIST_DIR}\resources\visit.ico"

  ShowInstDetails show


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
  # useful for debuggin, uncomment as necessary
  #!define MUI_FINISHPAGE_NOAUTOCLOSE
  !define MUI_FINISHPAGE_TEXT ""
  !define MUI_PAGE_CUSTOMFUNCTION_SHOW FinishPageShow
  !insertmacro MUI_PAGE_FINISH

  ; Language files
  !insertmacro MUI_LANGUAGE "English"
  XPStyle off

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
  Var RequiresMesaAsGL


  #############################################################################
  #
  # Sections with IDS   (for those that can be optional)
  #
  #############################################################################

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
  SectionEnd

  Section HelpFiles SEC_HELP
  SectionEnd

  Section /o "Plugin development" SEC_DEV
    ${If} $InstallUsers == "all"
      WriteRegExpandStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITARCHHOME "%VISITLOC%"
      WriteRegExpandStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITPLUGININSTPUB "%VISITLOC%"
    ${Else}
      WriteRegStr HKCU "Environment" VISITARCHHOME "%VISITLOC%"
      WriteRegStr HKCU "Environment" VISITPLUGININSTPRI "%USERPROFILE%\LLNL\VisIt"
      WriteRegStr HKCU "Environment" VISITPLUGININSTPUB "%VISITLOC%"
    ${EndIf}
    ; propagate the changes so a reboot won't be necessary
    SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000
    ${IfNot} ${SectionIsSelected} ${SEC_PAR}
       !insertmacro _ReplaceInFile "${VISITINSTDIR}\include\PluginVsInstall.cmake" "SET(VISIT_PARALLEL               ON)" "SET(VISIT_PARALLEL               OFF)"
    ${EndIf}
  SectionEnd

  Section /o "LibSIM" SEC_LIBSIM
  SectionEnd

  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SEC_PAR} "Parallel components. Currently requires mpiexec."

    !insertmacro MUI_DESCRIPTION_TEXT ${SEC_DP} "Removing un-needed database plugins may help improve startup performance of some components, but you will need to re-run the installer to get them back."

    !insertmacro MUI_DESCRIPTION_TEXT ${SEC_DATA} "Sample data files"
    !insertmacro MUI_DESCRIPTION_TEXT ${SEC_HELP} "VisIt's help files"
    !insertmacro MUI_DESCRIPTION_TEXT ${SEC_DEV} "Plugin development components. Note that you must have Microsoft Visual Studio 2022 to develop plugins compatible with this binary VisIt distribution."

    !insertmacro MUI_DESCRIPTION_TEXT ${SEC_LIBSIM} "VisIt's libsim files"
  !insertmacro MUI_FUNCTION_DESCRIPTION_END

  #############################################################################
  #
  # Functions
  #
  #############################################################################

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
!endif ;if CREATING_UNINSTALLER else

Function .onInit

!ifdef CREATING_UNINSTALLER
    WriteUninstaller "$%TEMP%\uninstall_visit.exe"
    Quit
!else

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
!endif
FunctionEnd

!ifndef CREATING_UNINSTALLER
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
  # Allow the user to choose whether python script files and/or curve
  # files will be associated with VisIt.
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

  Function FinishPageShow
    # firewall message
    ${NSD_CreateLabel} 120u 50u 60% 40% "Depending on the settings for Windows Firewall, communication between local VisIt processes and remote VisIt processes may be blocked. If you are not an admin, you may need assistance adding VisIt's processes to the firewall's exception list."
    Pop $0
    SetCtlColors $0 0x000000 transparent

    ${If} $RequiresMesaAsGL == true
        ${NSD_CreateLabel} 120u 110u 60% 40% "!!! VisIt detected that the OpenGL version on this system is insufficient, so Mesa3D is being substituted for the system OpenGL. Rendering performance may be negatively impacted. We recommended that you update the graphics card and/or drivers if possible (uninstall and reinstall VisIt in that case). !!!"
        Pop $0
        SetCtlColors $0 0xFF0000 transparent
    ${EndIf}
  FunctionEnd


  #############################################################################
  #
  # Sections
  #
  #############################################################################

  Section -ExtractTarball
    !insertmacro UpdateShellVarContext "$InstallUsers"
    SetOutPath "${VISITINSTDIR}"
    File "${VISIT_DIST_DIR}\installation\xml2plugin.bat"
    File "$%TEMP%\uninstall_visit.exe"

    File "/oname=$PLUGINSDIR\visit${PRODUCT_VERSION}.7z" "${BIN_DIR}\visit${PRODUCT_VERSION}.7z"
    File "/oname=$PLUGINSDIR\7z.exe" "${VISIT_WINDOWS_DIR}\${COMPILER}\p7zip\18.05\7z.exe"
    File "/oname=$PLUGINSDIR\7z.dll" "${VISIT_WINDOWS_DIR}\${COMPILER}\p7zip\18.05\7z.dll"

    # create a var to hold exclusions
    FileOpen $4 "$PLUGINSDIR\7zExclusions.txt" w
    strcpy $0 ""
    ${IfNot} ${SectionIsSelected} ${SEC_PAR}
        FileWrite $4 "*_par.*$\r$\n"
        FileWrite $4 "*\plots\*_par.*$\r$\n"
        FileWrite $4 "*\operators\*_par.*$\r$\n"
        strcpy $0 "yes"
    ${EndIf}
    ${IfNot} ${SectionIsSelected} ${SEC_DEV}
        FileWrite $4 "*lib\*.lib$\r$\n"
        FileWrite $4 "*include\$\r$\n"
        strcpy $0 "yes"
    ${EndIf}
    ${IfNot} ${SectionIsSelected} ${SEC_HELP}
        FileWrite $4 "*\resources\help\$\r$\n"
        strcpy $0 "yes"
    ${EndIf}
    ${IfNot} ${SectionIsSelected} ${SEC_DATA}
        FileWrite $4 "data\$\r$\n"
        strcpy $0 "yes"
    ${EndIf}
    ${IfNot} ${SectionIsSelected} ${SEC_LIBSIM}
        FileWrite $4 "libsim\$\r$\n"
        strcpy $0 "yes"
    ${EndIf}

    StrCpy $9 ${SEC_DP_0}
    StrCpy $8 ${NumDBPlugins}
    IntOp $8 $8 - 1
    ${For} $R0 0 $8
        ${IfNot} ${SectionIsSelected} $9
            SectionGetText $9 $R2
            FileWrite $4 "*databases\?$R2*.dll$\r$\n"
            strcpy $0 "yes"
        ${EndIf}
        IntOp $9 $9 + 1
    ${Next}
    FileClose $4

    ${If} $0 == "yes"
        ExecWait '"$PLUGINSDIR\7z.exe" x -spe -xr@"$PLUGINSDIR\7zExclusions.txt" -o"${VISITINSTDIR}" $PLUGINSDIR\visit${PRODUCT_VERSION}.7z' $7
    ${Else}
        ExecWait '"$PLUGINSDIR\7z.exe" x -spe -o"${VISITINSTDIR}" $PLUGINSDIR\visit${PRODUCT_VERSION}.7z' $7
    ${EndIf}
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

  #Section -TestOpenGLVersion
  #  # Run a small program to test if the OpenGL Version is sufficent on the
  #  # system being installed. If not, Mesa3D's openg32.dll will be put in
  #  # VisIt's root dir, and a RegKey flag will be set notifying VisIt to set
  #  # MESA_GL_VERSION_OVERRIDE=3.3 in the environment for VisIt processes.
  #  File "/oname=$PLUGINSDIR\vtkTestOpenGLVersion.exe" "${INSTALL_PREFIX}\vtkTestOpenGLVersion.exe"
  #  ExecWait '"$PLUGINSDIR\vtkTestOpenGlVersion.exe"' $0
  #  ${If} $0 == 1
  #      SetOutPath "${VISITINSTDIR}"
  #      FILE "/oname=opengl32.dll" "${INSTALL_PREFIX}\mesagl\opengl32.dll"
  #      StrCpy $RequiresMesaAsGL true
  #  ${Else}
  #      StrCpy $RequiresMesaAsGL false
  #  ${Endif}
  #SectionEnd

  #
  # This section installs the VISIT<version> key, which tells visit.exe where
  # to find the rest of the VisIt components. Note that we put keys in
  # HKEY_LOCAL_MACHINE or in HKEY_CURRENT_USER.
  #
  Section -AddVisItRegKeys
    SetRegView 64

    ; our regular registry entries
    WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "" ""
    WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "VISITHOME" "${VISITINSTDIR}"

  ${If} $RequiresMesaAsGL == true
      WriteRegStr SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "VISITNEEDSMESA" "true"
  ${EndIf}
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
    Strcpy $R0 "$SMPROGRAMS\VisIt${PRODUCT_VERSION}"
    CreateDirectory "$R0"
    CreateShortCut "$R0\VisIt${PRODUCT_VERSION}.lnk"  \
       "${VISITINSTDIR}\visit.exe" ""      \
       "" 0  \
       SW_SHOWMINIMIZED  \
       ""  \
       "VisIt allows you to visualize simulation data."
    CreateShortCut "$R0\VisIt${PRODUCT_VERSION} in stereo.lnk"  \
        "${VISITINSTDIR}\visit.exe" "-stereo"      \
        "" 0  \
        SW_SHOWMINIMIZED  \
        ""  \
        "VisIt allows you to visualize simulation data in stereo."
    CreateShortCut "$DESKTOP\VisIt${PRODUCT_VERSION}.lnk" \
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
      CreateShortCut "$R0\Plugin development\Documentation\Database plugins.lnk" \
           "https://visit-sphinx-github-user-manual.readthedocs.io/en/develop/data_into_visit/CreatingDatabasePlugin.html"
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
   Strcpy $R0 "$R0///LLNL///VisIt${PRODUCT_VERSION}"
   WriteRegStr SHCTX "SOFTWARE\JavaSoft\Prefs\llnl\visit" "/V/I/S/I/T/H/O/M/E" $R0
  SectionEnd

  Section -AdditionalIcons
    ${DisableX64FSRedirection}
    WriteIniStr "${VISITINSTDIR}\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
    CreateShortCut "$SMPROGRAMS\VisIt${PRODUCT_VERSION}\VisIt Home Page.lnk" "${VISITINSTDIR}\${PRODUCT_NAME}.url"
    CreateShortCut "$SMPROGRAMS\VisIt${PRODUCT_VERSION}\Uninstall VisIt${PRODUCT_VERSION}.lnk" "${V_UNINSTALLER}"
  SectionEnd

  Section -Post
    SetOutPath -
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
!else ; ndef CREATING_UNINSTALLER

  ; now CREATING_UNINSTALLER
  ${UnStrStrAdv}
  ${UnStrTrimNewLines}
  !define MUI_UNICON "${VISIT_DIST_DIR}\resources\visit.ico"
  !define MUI_WELCOMEPAGE_TEXT "The entire VisIt folder at $INSTDIR $\r$\nwill be removed. $\r$\n$\r$\nIf this is NOT okay, press Cancel." 
  !insertmacro MUI_UNPAGE_WELCOME
  !insertmacro MUI_UNPAGE_INSTFILES
  !insertmacro MUI_LANGUAGE "English"

  Section
     ; do nothing, just here to satisfy the requirement that there must
     ; be sections
  SectionEnd

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
    ;MessageBox MB_OKCANCEL|MB_ICONSTOP "VisIt's uninstaller will be removing the entire directory at $INSTDIR, if this is NOT okay, press CANCEL." /SD IDOK IDOK +1 IDCANCEL +1
    RMDir /r $INSTDIR
    ReadRegStr $0    HKLM "Software\Classes\VISIT${PRODUCT_VERSION}" "InstalledAllUsers"
    ${If} $0 == "all"
       !insertmacro UpdateShellVarContext "all"
    ${Else}
       !insertmacro UpdateShellVarContext "current"
    ${EndIf}
    # Read in saved value to know whether VisIt was installed for AllUsers or
    # current user.
    # Remove all of the VisIt software components

    ReadRegStr $1 SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "AssociatedPythonWithVisIt"
    ReadRegStr $2 SHCTX "Software\Classes\VISIT${PRODUCT_VERSION}" "AssociatedCurvesWithVisIt"
    # Remove the desktop shortcut
    Delete "$DESKTOP\VisIt${PRODUCT_VERSION}.lnk"
    SetRegView 64
    ${DisableX64FSRedirection}

    # Remove the Start menu program group
    Strcpy $R9 "$SMPROGRAMS\VisIt${PRODUCT_VERSION}"
    Delete "$R9\VisIt${PRODUCT_VERSION}.lnk"
    Delete "$R9\VisIt${PRODUCT_VERSION} in stereo.lnk"
    Delete "$R9\VisIt Command Line Interface.lnk"
    Delete "$R9\VisIt with Debug logging.lnk"
    Delete "$R9\VisIt parallel.lnk"
    Delete "$R9\Silex.lnk"
    Delete "$R9\VisIt Home Page.lnk"
    Delete "$R9\Uninstall VisIt${PRODUCT_VERSION}.lnk"
    Delete "$R9\Plugin development\XML Edit.lnk"
    Delete "$R9\Plugin development\Documentation\Database plugins.lnk"
    RmDir "$R9\Plugin development\Documentation"
    RmDir "$R9\Plugin development"
    RMDir "$R9"


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
    DeleteRegKey SHCTX "Software\Microsoft\Windows\CurrentVersion\Uninstall\VisIt${PRODUCT_VERSION}"

    ${If} $0 == "all"
        DeleteRegValue HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITLOC
        DeleteRegValue HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" VISITARCHHOME
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
!endif

