#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "linkedlist.c"

extern int errno;

void sortedInsert(Node** headRef, Node* node){
	Node* current = *headRef;
	Node* prev = current;

	if(current == NULL || node->value <= current->value){
		*headRef = node;
		node->next = current;
	}else{
		current = current->next;

		while(current != NULL){
			if(prev->value <= node->value && current->value > node->value){
				node->next = current;
				break;
			}else{
				prev = current;
				current = current->next;
			}
		}

		prev->next = node;
	}

}