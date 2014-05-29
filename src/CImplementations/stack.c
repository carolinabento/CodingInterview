#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "stack.h"

Node* newStack(){
	Node* top = NULL;
return top;
}

Node* push(Node** top, int value){
	Node* node = (Node*) malloc (sizeof(Node*));

	node->value = value;
	node->previous = *top;	
	node->next = NULL;

	if(node->previous == NULL){
		node->size = 1;
	}else{
		node->size = node->previous->size + 1;
	}
	*top = node;

return *top;
}


Node* pop(Node** top){
	Node* node = (Node*) malloc (sizeof(Node*));
	if(top == NULL){
		*top = NULL;
	}else{
		node->value = (*top)->value;
		node->size = 1;
		node->previous = NULL;
		node->next = NULL;

		*top = (*top)->previous;

		if(*top != NULL){
			(*top)->next = NULL;
		}
		
	}

return node;
}