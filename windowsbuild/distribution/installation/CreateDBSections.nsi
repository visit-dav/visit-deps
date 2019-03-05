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
##############################################################################


!include "LogicLib.nsh"

RequestExecutionLevel user

OutFile "${BIN_DIR}\CreateDBSections.exe"
SilentInstall silent

var NumDBPlugins
var DBOutPath
var DBInPath
var tmpfile
var myesc

Section DBS
    StrCpy $NumDBPlugins 0
    StrCpy $DBOutPath "${VISITINSTDIR}\databases"
    StrCpy $DBInPath "${INSTALL_PREFIX}\databases\"
    StrCpy $myesc "$$"

    FileOpen $0 "${BIN_DIR}\DBSections.txt" w #open file
    FileWrite $0 `SectionGroup "Database Plugins" SEC_DP$\r$\n`

    FindFirst $R1 $R2 "${VISIT_SOURCE_DIR}\databases\*"
   
    ${Unless} ${Errors}
      ${Do}
        StrCpy $tmpfile "$DBInPathI$R2Database.dll" 
        ${If} ${FileExists} "$DBInPathI$R2Database.dll" 
            FileWrite $0 `    Section "$R2"  SEC_DP_$NumDBPlugins$\r$\n`
            FileWrite $0 `        SetOutPath "$DBOutPath"$\r$\n`
            FileWrite $0 `        $myesc{If} $myesc{SectionIsSelected} "${SEC_PAR}"$\r$\n`
            FileWrite $0 `            File "$DBInPath*$R2*.dll"$\r$\n`
            FileWrite $0 `        $myesc{Else}$\r$\n`
            FileWrite $0 `            File /x "*_par.dll" "$DBInPath*$R2*.dll"$\r$\n`
            FileWrite $0 `        $myesc{EndIf}$\r$\n`
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

