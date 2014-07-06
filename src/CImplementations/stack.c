#ifndef STACK

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
	Node* temp = *top;

	*top= (*top)->previous;
	//(*top)->size = (*top)->size - 1;		
	temp->previous = NULL;
	//free(temp);

return temp;
}

int isEmpty(Node* top){
	if(top == NULL){
		return 1;
	}else{
		return 0;
	}
}

int peek(Node* top){
	int res;
	if(isEmpty(top) == 0){
		res = top->value;
	}

	return res;
}
#endif