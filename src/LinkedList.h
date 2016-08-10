#ifndef linkedlist_H
#define linkedlist_H

#include "TCB.h"


struct ListElement{
	struct ListElement *next; //Pointer Next will point to the next element
	int value; //Value will store integer number that given by users
};

struct LinkedList{
	Tcb *head; //Pointer head will always point to the first element
	Tcb *tail; //Pointer Tail will always point to the last element
	int length;
};


struct ListElement *createListElement(int value);
struct LinkedList *createLinkedList();
#endif // linkedlist_H
