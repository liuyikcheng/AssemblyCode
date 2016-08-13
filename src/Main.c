/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"
#include "TCB.h"
#include "SaveRegisters.h"
#include "LoadRegisters.h"
#include "addList.h"

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s
extern int task1Sp;							// Import from SaveRegisters.s

uint32_t switchTask;
uint32_t vSpMain;
uint32_t virtualSp;

uint32_t variableInC = 0xdeaf;
struct LinkedList tcbList ;
Context context;

void task1();
void task2();
void task3();

void waitForever(void) {
	volatile int counter = 500000;
	while(counter--);
//	NVIC_DisableIRQ(SysTick_IRQn);
	disableSysTickInterrupt();
}

void task1(){
	while(1); //do something...
	
}

void task2(){
	while(1); //do something...
	
}

void task3(){
	while(1); //do something...
	
}

int main() {
	initSysTick();
	initLinkedList(&tcbList);
	noArgFunc();
	
	initTcbMain();
  initTcb1();
	initTcb2();
	initTcb3();
	
	//add tcb to linked list
	addList(&taskMain, &tcbList);
	addList(&task1Tcb, &tcbList);
	addList(&task2Tcb, &tcbList);
	addList(&task3Tcb, &tcbList);
	
	
	//push tcb2 stack
	switchTask = (uint32_t)&task2; 
	virtualSp = task2Tcb.sp;
	saveRegs();
	task2Tcb.sp = virtualSp;
	
	//push tcb3 stack
	switchTask = (uint32_t)&task3;
	virtualSp = task3Tcb.sp;
	saveRegs();
	task3Tcb.sp = virtualSp;
	
	//push tcb1 stack
	switchTask = (uint32_t)&task1; 
	virtualSp = task1Tcb.sp;
	saveRegs();
	task1Tcb.sp = virtualSp;

	while(1);	


	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;		//
}
