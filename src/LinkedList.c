#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "listElement.h"
#include "addList.h"
/*******************************************************************************
 * Overall Function:
 * Create a linked list and add new node(element) to the end of the linked list.
 * Eg.,
 *  A several integers was entered (4, 3, 2, 7,) and it will output "4->3->2->7"
 *******************************************************************************/
/* 
 * Create an element which contain pointers Head and Tail
 * Return:
 *  The element which contain the pointers Head and Tail
 */
 

struct LinkedList *createLinkedList(){
	struct LinkedList *list;
	list -> head = NULL;
	list -> tail = NULL;
	list -> length = 0;
	return list;
}

void initLinkedList(struct LinkedList *list){
	list -> head = NULL;
	list -> tail = NULL;
	list -> length = 0;
}
