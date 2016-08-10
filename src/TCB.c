#include "TCB.h"
#include <stdlib.h>

Tcb task1Tcb;
Tcb task2Tcb;
Tcb task3Tcb;

/**
 * Must call this function first
 */
void initTcb1() {
	task1Tcb.name = "task_1";
	task1Tcb.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE];
	task1Tcb.next = NULL;
	
	task1Tcb.context.r0 = 0x135d0293;
	task1Tcb.context.r1 = 0x1111AAAA;
	task1Tcb.context.r2 = 0x2222BBBB;
	task1Tcb.context.r3 = 0x3333CCCC;
	task1Tcb.context.r4 = 0x4444DDDD;
	task1Tcb.context.r5 = 0x5555EEEE;
	task1Tcb.context.r6 = 0x6666FFFF;
	task1Tcb.context.r7 = 0x7777ABAB;
	task1Tcb.context.r8 = 0x8888BCBC;
	task1Tcb.context.r9 = 0x9999CDCD;
	task1Tcb.context.r10 = 0x1010AABB;
	task1Tcb.context.r11 = 0x1100AACC;
	task1Tcb.context.r12 = 0x1212BBCC;
}

void initTcb2() {
	task2Tcb.name = "task_2";
	task2Tcb.sp = (uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE];
	task2Tcb.next = NULL;
	
	task2Tcb.context.r0 = 0x12133423;
	task2Tcb.context.r1 = 0x0100a01a;
	task2Tcb.context.r2 = 0x0200b02b;
	task2Tcb.context.r3 = 0x0300c03c;
	task2Tcb.context.r4 = 0x0400d04d;
	task2Tcb.context.r5 = 0x0500e05e;
	task2Tcb.context.r6 = 0x0600a06a;
	task2Tcb.context.r7 = 0x0700b07b;
	task2Tcb.context.r8 = 0x0800c08c;
	task2Tcb.context.r9 = 0x0900d09d;
	task2Tcb.context.r10 = 0x1000e10e;
	task2Tcb.context.r11 = 0x1100a11a;
	task2Tcb.context.r12 = 0x1200b12b;
}

void initTcb3() {
	task3Tcb.name = "task_3";
	task3Tcb.sp = (uint32_t)&task3Tcb.virtualStack[TASK_STACK_SIZE];
	task3Tcb.next = NULL;
	
	task3Tcb.context.r0 = 0x23455554;
	task3Tcb.context.r1 = 0xaa013111;
	task3Tcb.context.r2 = 0xbb023222;
	task3Tcb.context.r3 = 0xcc033333;
	task3Tcb.context.r4 = 0xdd043444;
	task3Tcb.context.r5 = 0xee053555;
	task3Tcb.context.r6 = 0xab063666;
	task3Tcb.context.r7 = 0xac073777;
	task3Tcb.context.r8 = 0xad083888;
	task3Tcb.context.r9 = 0xae093999;
	task3Tcb.context.r10 = 0xba103010;
	task3Tcb.context.r11 = 0xbc113011;
	task3Tcb.context.r12 = 0xbd123012;
	task3Tcb.context.r13 = 0xbe133013;
}

uint32_t getTask1TcbSp(){ 
 	return task1Tcb.sp; 
} 


// Study the code in AsssemblyModule.s and take note of what
// how each instruction performs its job. You need that knowledge
// to do the following:
//
// 1) Create a new assembly file called 'SaveRegisters.s'.
// 2) Write a code in assembly [in (1)] to:
//    - load SP with the value in 'task1Tcb.sp'
//    - push all registers, except R13 to the stack
// 3) Name that function as 'saveRegs'
// 4) From main() call: 
//    - initTcb()
//    - saveRegs()
// 5) Verify that the registers are in 'task1Tcb.virtualStack'
// 6) Submit your work by pushing it to GitHub
