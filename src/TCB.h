#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define TASK_STACK_SIZE	1024

typedef struct context{
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
	uint32_t r12;
	uint32_t r13;
	
}Context;

typedef struct Tcb_t Tcb;
struct Tcb_t{
	char *name;									// Task name	
	uint32_t 	sp;								// Stack pointer (R13)
	uint8_t		virtualStack[TASK_STACK_SIZE];
	Context context;
	Tcb* next;
} ;



extern Tcb task1Tcb;
extern Tcb task2Tcb;
extern Tcb task3Tcb;

void initTcb1();
void initTcb2();
void initTcb3();

#endif	// __TCB_H__
