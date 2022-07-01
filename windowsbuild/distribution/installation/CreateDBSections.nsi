##############################################################################
#
# File: CreateDBSections.nsi
#
# Purpose: This script compares database names with build database dlls to
#          create a list of database plugins that can be installed. They are
#          then stored in their own NSIS sections, so that they can be
#          selectively chosen to be installed or not, one by one.
#
# Notes:  Expects VISIT_SOURCE_DIR and INSTALL_PREFIX to be defined on
#         command line. (makensis.exe /DVISIT_SOURCEDIR= ... etc)
#
# Modifications:
#   Kathleen Biagas, Thu Sep 15 12:33:15 PDT 2011
#   Add logic to exclude parallel files if necessary.
#
#   Kathleen Biagas, Wed Jun 29, 2022
#   Modified to simply create empty section for each avaialable DB plugin.
#   Having the sections allows user to unselect DB plugins for install.
#   No copy logic needed, as the entire Install is now in a compressed 7z.
#
##############################################################################


!include "LogicLib.nsh"

RequestExecutionLevel user

OutFile "${BIN_DIR}\CreateDBSections.exe"
SilentInstall silent

var NumDBPlugins
var DBInPath

Section DBS
    StrCpy $NumDBPlugins 0
    StrCpy $DBInPath "${INSTALL_PREFIX}\databases\"

    FileOpen $0 "${BIN_DIR}\DBSections.txt" w #open file
    FileWrite $0 `SectionGroup "Database Plugins" SEC_DP$\r$\n`

    FindFirst $R1 $R2 "${VISIT_SOURCE_DIR}\databases\*"

    ${Unless} ${Errors}
      ${Do}
        ${If} ${FileExists} "$DBInPathI$R2Database.dll"
            # create empty section, simply to add ability for user to
            # unselect database plugins
            FileWrite $0 `    Section "$R2"  SEC_DP_$NumDBPlugins$\r$\n`
            FileWrite $0 `    SectionEnd$\r$\n`
            IntOp $NumDBPlugins $NumDBPlugins + 1
        ${EndIf}
        FindNext $R1 $R2
      ${LoopUntil} ${Errors}
      FindClose $R1
    ${EndUnless}
    FileWrite $0 `SectionGroupEnd$\r$\n`
    FileWrite $0 `!define NumDBPlugins "$NumDBPlugins"$\r$\n`
    FileClose $0
SectionEnd

