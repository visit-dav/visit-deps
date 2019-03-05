##############################################################################
#
# File: libsim_installation.nsi
#
# Purpose: This script creates an installer for 32bit and 64bit VisIt sim 
#          libraries. It adds the install location to then enviroment as
#          the variable VISITSIM.
#
# Programmer: Kathleen Biagas 
# Date:       January 27, 2012
#
# Modifications:
#
##############################################################################


; The location of the 64-bit 'INSTALL' of VisIt 
; (from building the INSTALL project)
!define V64DIR "D:\A_VisIt\2.13RC\build-vc15\VisIt 2.13.1"


!define PRODUCT_NAME "VisIt's sim libraries"
!define PRODUCT_VERSION  2.13.1
!define PRODUCT_PUBLISHER "LLNL"
!define PRODUCT_WEB_SITE "http://www.llnl.gov/visit"

SetCompressor /SOLID /FINAL lzma
RequestExecutionLevel user

!include "MUI2.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "..\resources\visit.ico"

; License page
!insertmacro MUI_PAGE_LICENSE "..\..\..\src\COPYRIGHT"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile ".\visitsim${PRODUCT_VERSION}.exe"
InstallDir "C:\visitsim${PRODUCT_VERSION}"
ShowInstDetails show


Section "LibSimFiles" SEC01
  # includes
  SetOutPath "$INSTDIR\include"
  File "${V64DIR}\libsim\V2\include\*.h"
  File "${V64DIR}\libsim\V2\include\*.inc"

  # 64 bit libs
  SetOutPath "$INSTDIR\lib\x64"
  File "${V64DIR}\libsim\V2\lib\*.lib"

  # create environment var of install location
  WriteRegStr HKCU "Environment" VISITSIM "$INSTDIR"

  ; propagate the changes so a reboot won't be necessary
  SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000
SectionEnd
