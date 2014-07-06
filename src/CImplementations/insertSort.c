#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "sortedInsert.c"

extern int errno;


void insertSort(Node** headRef){
	Node* current = *headRef;
	Node* newHead = NULL;

	while(current != NULL){
		Node* node = current;
		current = current->next;
		node->next = NULL;

		sortedInsert(&newHead, node);
	}

	*headRef = newHead;
}