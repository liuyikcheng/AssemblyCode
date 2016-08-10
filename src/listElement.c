#include "listElement.h"
#include "linkedlist.h"
#include "addList.h"
#include <stdio.h>
#include <stdlib.h>

/* 
 * Create an element which contain pointer Next and an integer number
 *
 * Input:
 *  value   contain an integer number that input by users
 * Return:
 *  The element which contain the pointer Next and an integer number
 */

struct ListElement *createListElement(int value){
	struct ListElement *newElement;
	newElement = malloc(sizeof(struct ListElement));
	newElement -> next = NULL ;
	newElement -> value = value ;
	return newElement;
}