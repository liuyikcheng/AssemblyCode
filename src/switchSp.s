					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  taskSp
taskSp		DCD     1

					AREA		MyCode, CODE, READONLY
switchSp	PROC
					EXPORT  switchSp
					IMPORT	switchTask
					IMPORT	vSpNext
					
				;	ldr			r9, = vSp						
				;	str			r13, [r9]
						
					ldr			r13, = vSpNext			;load sp value to r13
					ldr			r13, [r13]
						
					BX			lr									; Return to caller
								
					ENDP
								
					END