#include "TCB.h"
#include <stdlib.h>

Tcb task1Tcb;
Tcb task2Tcb;
Tcb task3Tcb;
Tcb taskMain;

/**
 * Must call this function first
 */

void initTcbMain() {
	taskMain.name = "task_Main";
	taskMain.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE];
	taskMain.next = NULL;

}
 
void initTcb1() {
	task1Tcb.name = "task_1";
	task1Tcb.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE];
	task1Tcb.next = NULL;
	

}

void initTcb2() {
	task2Tcb.name = "task_2";
	task2Tcb.sp = (uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE];
	task2Tcb.next = NULL;
	

}

void initTcb3() {
	task3Tcb.name = "task_3";
	task3Tcb.sp = (uint32_t)&task3Tcb.virtualStack[TASK_STACK_SIZE];
	task3Tcb.next = NULL;
	

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
