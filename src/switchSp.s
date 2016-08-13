					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  taskSp
taskSp		DCD     1

					AREA		MyCode, CODE, READONLY
switchSp	PROC
					EXPORT  switchSp
					IMPORT	switchTask
					IMPORT	curSp
					IMPORT 	vSp
				
					ldr			r9, = curSp					;save current sp value to curSp
					str			r13, [r9]
					
					ldr			r13, = vSp					;load vSp value to r13
					ldr			r13, [r13]					
						
					BX			lr									; Return to caller
								
					ENDP
								
					END