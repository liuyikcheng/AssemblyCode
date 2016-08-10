					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  taskSp
taskSp		DCD     1

					AREA		MyCode, CODE, READONLY
switchSp	PROC
					EXPORT  switchSp
					IMPORT	vSpNext
					IMPORT	vSp
					
					
					ldr			r13, = vSpNext
					ldr			r13, [r13]
						
					BX			lr									; Return to caller
								
					ENDP
								
					END