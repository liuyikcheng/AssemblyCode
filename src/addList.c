#include "addList.h"

#include <stdio.h>
#include <stdlib.h>

/* 
 * Link the pointer Head to the first new element and link the pointer Tail to the last element.
 * Make the pointer of an element to point to the next element
 * 
 * Input:
 *  newElement    Element contains pointer Next and an integer number
 *  LinkedList    Element contains pointer Head and Tail
 */
void addList(Tcb *newElement, struct LinkedList *list){
	
	if(list->head == NULL){ 
		list->head = newElement;
		list->tail = newElement;
	}
	
	else{
		list->tail->next = newElement;
		list->tail = newElement;
	}
	list->length++;
}

Tcb *elementRemoved(struct LinkedList *list){
	int i=1;
	Tcb *preElem = malloc(sizeof(struct ListElement));
	preElem = list->head; 
	if(list->head->next == NULL){
		list->head = NULL;
		list->tail = NULL;
	}
	else{
		while(i < list->length){
			list->tail = preElem;
			preElem = preElem->next;
			i++;
		}
	}
	free(preElem);
	list->length--;
	return preElem;
}

void elementSwitch(struct LinkedList *list){
	
	Tcb* temp = list->head;
	
	list->head = list->head->next;
	
	temp->next = NULL;
	
	list->tail->next = temp;
	
	list->tail = list->tail->next;
	
}