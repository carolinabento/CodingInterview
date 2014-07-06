#ifndef INSERTNTH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../linkedlist.c"


void insertNth(Node** headRef, int index, int value){
int pos = 0;

	if(size(*headRef) < index){
		puts("Index Out of bounds!");
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
#endif