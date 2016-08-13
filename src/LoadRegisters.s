					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
task1Sp		DCD     1

					AREA		MyCode, CODE, READONLY
loadRegs 	PROC
					EXPORT  loadRegs
					
					
					
					BX			lr									; Return to caller
								
					ENDP
								
					END