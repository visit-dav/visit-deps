;;; CompileTimeIfFileExists ;;;

!macro CompileTimeIfFileExists path define
  !tempfile tmpinc
  !system 'IF EXIST "${path}" echo !define ${define} > "${tmpinc}"'
  !include "${tmpinc}"
  !delfile "${tmpinc}"
  !undef tmpinc
!macroend


;;; UpdateShellVarContext ;;;;
!macro UpdateShellVarContext allUsers
    ${If} ${allUsers} == "all" 
        SetShellVarContext all
    ${Else}
        SetShellVarContext current
    ${EndIF}
!macroend



;;; DumpLog ;;;;
!ifndef LVM_GETITEMCOUNT
!define LVM_GETITEMCOUNT 0x1004
!endif
!ifndef LVM_GETITEMTEXT
!define LVM_GETITEMTEXT 0x102D
!endif

Function DumpLog
  Exch $5
  Push $0
  Push $1
  Push $2
  Push $3
  Push $4
  Push $6

  FindWindow $0 "#32770" "" $HWNDPARENT
  GetDlgItem $0 $0 1016
  StrCmp $0 0 error
  FileOpen $5 $5 "w"
  StrCmp $5 0 error
    SendMessage $0 ${LVM_GETITEMCOUNT} 0 0 $6
    System::Alloc ${NSIS_MAX_STRLEN}
    Pop $3
    StrCpy $2 0
    System::Call "*(i, i, i, i, i, i, i, i, i) i \
      (0, 0, 0, 0, 0, r3, ${NSIS_MAX_STRLEN}) .r1"
    loop: StrCmp $2 $6 done
      System::Call "User32::SendMessageA(i, i, i, i) i \
        ($0, ${LVM_GETITEMTEXT}, $2, r1)"
      System::Call "*$3(&t${NSIS_MAX_STRLEN} .r4)"
      FileWrite $5 "$4$\r$\n"
      IntOp $2 $2 + 1
      Goto loop
    done:
      FileClose $5
      System::Free $1
      System::Free $3
      Goto exit
  error:
    MessageBox MB_OK error
  exit:
    Pop $6
    Pop $4
    Pop $3
    Pop $2
    Pop $1
    Pop $0
    Exch $5
FunctionEnd

;;ShellExecEx

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Gets the parent directory
;; P1 :out: Parent dir
;; P2 :in:  File/Dir
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
!define PathPath "!insertmacro _PathPath"
!macro _PathPath _RetVal_ _Path_
   Push "${_Path_}"
   !ifdef __UNINSTALL__
      Call un.PathPath
   !else
      Call PathPath
   !endif
   Pop "${_RetVal_}"
!macroend

!macro Func_PathPath un
  Function ${un}PathPath
   Exch $0  ;; Path
   Push $1  ;; Strlen / Counter
   Push $2  ;; Curchar
   StrLen $1 '$0'
   IntCmp $1 0 +6
      IntOp $1 $1 - 1
      StrCpy $2 "$0" 1 $1
      StrCmp "$2" '\' +3
      StrCmp "$2" ":" 0 -4
         IntOp $1 $1 + 1
   StrCpy $0 "$0" $1 0
   Pop $2
   Pop $1
   Exch $0
 FunctionEnd
!macroend
!insertmacro Func_PathPath ""
!insertmacro Func_PathPath "un."
 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Executes a file with the ShellExecuteEx api
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; P1 :out: Return value, depends on the mode (P7). On error returns -1 and sets the error flag
;; P2 :in:  Verb. if="" then it opens with default associated app
;; P3 :in:  File
;; P4 :in:  File parameters
;; P5 :in:  Working directory. if="" then its set to the same dir as the file
;; P6 :in:  Show flag. if="" then SH_SHOW is used (http://msdn.microsoft.com/en-us/library/bb762153(v=VS.85).aspx)
;; P7 :in:  Mode: 1=Nowait, Return Process Id
;;                2=Nowait, Return Process Handle (must close the handle yourself)
;;                3=Wait, Return Process Exit Code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
!define ShellExecEx '!insertmacro _ShellExecEx'
!macro _ShellExecEx  _RetVal_ _Verb_ _File_ _Params_ _WorkDir_ _Show_ _Mode_  
   Push `${_Mode_}`
   Push `${_Show_}`
   Push `${_WorkDir_}`
   Push `${_Params_}`
   Push `${_File_}`
   Push `${_Verb_}`
   !ifdef __UNINSTALL__
       Call un.sShellExecEx
   !else
       Call sShellExecEx
   !endif
   Pop ${_RetVal_}
!macroend

!macro Func_ShellExecEx un
 Function ${un}sShellExecEx
   Exch $0  ;; Verb
   Exch
   Exch $1  ;; File
   Exch 2
   Exch $2  ;; Params / process handle
   Exch 3
   Exch $3  ;; WorkDir
   Exch 4
   Exch $4  ;; Show / return value
   Exch 5
   Exch $5  ;; Mode
   Push "$9"  ;; shellexecuteinfo struct
 
   ClearErrors
   StrCmpS "" "$3" 0 wdok
      ${PathPath} $3 "$1"
   wdok:
   StrCmpS "" "$4" 0 +2  ;; if show mode is undefined, then
      StrCpy $4 0x05    ; = SH_SHOW
   System::Call '*(&i60) i .r9' ;; allocate the structure
   System::Call '*$9(i 60, i 0x140, i $HWNDPARENT, t r0, t r1, t r2, t r3, i r4) i .r9'  ;; assign the values to the struct
   System::Call 'shell32::ShellExecuteEx(i r9) i .r1'  ;; execute the file
   StrCmpS 0 $1 0 +4  ;; if there was errors, then
      StrCpy $4 -1  ; return -1 and set the error flag
      SetErrors
      Goto end
 
   System::Call '*$9(i, i, i, i, i, i, i, i, i, i, i, i, i, i, i .r2)'  ;; get the process handle
   IntCmp $5 2 +4 0 +6  ;; 1:nowait-pid, 2:nowait-handle, 3:wait-exitcode
      System::Call 'kernel32::GetProcessId(i r2) i .r4'
      System::Call 'kernel32::CloseHandle(i r2)'
      Goto end
;      handle:
      StrCpy $4 "$2"
      Goto end
;      wait:
      System::Call 'kernel32::WaitForSingleObject(i r2, i -1)'  ;;  wait indefinitely for the process to exit
      System::Call 'kernel32::GetExitCodeProcess(i r2,*i .r4)'
      System::Call 'Kernel32::CloseHandle(i r2)'
 
   end:
   System::Free $9
   Pop $9
   Pop $5
   Pop $0
   Pop $1
   Pop $2
   Pop $3
   Exch $4
 FunctionEnd
!macroend

!insertmacro Func_ShellExecEx ""
!insertmacro Func_ShellExecEx "un."

