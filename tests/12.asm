.data                          
sum DWORD 0                    
.code                          
main PROC
    mov eax,5                 
    add eax,6                  
    mox sum,eax
    INVOKE ExitProcess,0      
main ENDP