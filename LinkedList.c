#include "TCB.h"
#include "linkedlist.h"
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
void addList(TCB *newElement, struct LinkedList *list){
	struct ListElement *current = malloc(sizeof(struct ListElement));
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

struct ListElement *elementRemoved(struct LinkedList *list){
	int i=1;
	struct ListElement *preElem = malloc(sizeof(struct ListElement));
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