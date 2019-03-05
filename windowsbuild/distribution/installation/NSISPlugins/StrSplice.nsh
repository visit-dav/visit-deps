; String Splice header, taken from NSIS website Splice, and macro-tized.
 
!macro StrSplice output string index separator
    Push "${string}"
    Push "${index}"
    Push "${separator}"
    !ifdef __UNINSTALL__
        Call un.StrSplice
    !else
        Call StrSplice
    !endif
    Pop ${output}
!macroend
    

!macro Func_StrSplice un
    Function ${un}StrSplice
        Exch $R0 ; seperator character
        Exch
        Exch $R1 ; chunk to slice
        Exch
        Exch 2
        Exch $R2 ; string
        Push $R3
        Push $R4
        Push $R5
        Push $R6
        Push $R7
        Push $R8
 
        StrCpy $R3 0
        StrCpy $R5 -1
        StrCpy $R2 "$R0$R2$R0"
 
        Loop1:
            IntOp $R3 $R3 + 1
            StrCpy $R4 $R2 1 $R3
            StrCmp $R4 "" +5
            StrCmp $R4 $R0 0 Loop1
            StrCpy $R8 $R3
            IntOp $R5 $R5 + 1
            StrCmp $R5 $R1 0 Loop1
        StrLen $R4 $R2
        IntOp $R8 $R4 - $R8
        StrCpy $R6 $R2 "" -$R8 ; right side
        StrCpy $R7 $R2 -$R8 ; left side + slice
 
        StrCpy $R3 0
 
        Loop2:
            IntOp $R3 $R3 - 1
            StrCpy $R4 $R7 1 $R3
            StrCmp $R4 $R0 0 Loop2

        StrCpy $R0 $R7 $R3 ; left side
        IntOp $R3 $R3 + 1
        StrCpy $R1 $R7 "" $R3 ; slice
        StrCpy $R0 "$R0$R6"
 
        StrCpy $R0 $R0 -1
        StrLen $R2 $R0
        IntOp $R2 $R2 - 1
        StrCpy $R0 $R0 "" -$R2
 
        Pop $R8
        Pop $R7
        Pop $R6
        Pop $R5
        Pop $R4
        Pop $R3
        Pop $R2
        Exch $R1 ; slice
        Exch
        Exch $R0 ; new string
    FunctionEnd
!macroend
!insertmacro Func_StrSplice ""
!insertmacro Func_StrSplice "un."

