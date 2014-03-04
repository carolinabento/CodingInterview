#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "linkedlist.c"

extern int errno;

void insertNth(Node** headRef, int index, int value){
int pos = 0;

	if(size(*headRef) < index){
		puts("Index Out of bounds!");
		puts(strerror(errno));
	}else{

		Node* current = *headRef;

		while(pos < (index - 1)){
			pos++;
			current = current->next;
		}

		Node* node = (Node*) malloc (sizeof(Node*));
		node->value = value;

		if(index == 0){
			*headRef = node;
			node->next = NULL;
		}else{
			Node* temp = current->next;
			current->next = node;
			node->next = temp;
		}
		
	}

}