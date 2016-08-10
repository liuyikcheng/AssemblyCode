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
uint32_t vSp;
uint32_t vSpNext;

uint32_t variableInC = 0xdeaf;
struct LinkedList *tcbList ;
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
	
	switchTask = (uint32_t)&task2;
	vSpNext = task2Tcb.sp;
	saveRegs();
	
	while(1);
	
}

void task2(){

	switchTask = (uint32_t)&task3;
	vSpNext = task3Tcb.sp;
	saveRegs();
	
	while(1);
	
}

void task3(){
	switchTask = (uint32_t)&task1;
	vSpNext = task1Tcb.sp;
	saveRegs();
	
	while(1);
	
}

int main() {
	initSysTick();
	tcbList = createLinkedList();
	
	noArgFunc();

  initTcb1();
	initTcb2();
	initTcb3();
	
	addList(&task1Tcb, tcbList);
	addList(&task2Tcb, tcbList);
	addList(&task3Tcb, tcbList);
	
	switchTask = (uint32_t)&task1;
	vSpNext = task1Tcb.sp;

	saveRegs();
	

	while(1);


	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;		//
}
