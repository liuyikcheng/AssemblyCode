					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  task1Sp
task1Sp		DCD     1

					AREA		MyCode, CODE, READONLY
saveRegs	PROC
					EXPORT  saveRegs
					IMPORT	switchTask
					IMPORT	virtualSp
					
					ldr			r13, = virtualSp
					ldr			r13, [r13]
					
					
					ldr     r0, = 0x02000000
					ldr			r1, = 0xFFFFFFF9 
					ldr			r2, = 0x02020202
					ldr			r3, = 0x03030303
					ldr			r4, = 0x04040404
					ldr			r5, = 0x05050505
					ldr			r6, = 0x06060606
					ldr			r7, = 0x07070707
					ldr			r8, = switchTask
					ldr			r8,	[r8]
					ldr			r9, = 0x01000000

					push		{r0-r9}
					
					ldr			r9, = virtualSp
					str			r13, [r9]
					

					BX			lr									; Return to caller
								
					ENDP
								
					END