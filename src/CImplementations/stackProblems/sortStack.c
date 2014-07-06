#ifndef SORTSTACK

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "../stack.c"

void pushInOrder(Node** stack, int element){
	Node* tempStack = newStack();

	int swap = 1;

	while(swap != 0){		
		if(isEmpty(*stack) == 1 || peek(*stack) > element){
				swap = 0;
			push(stack,element);

			while(isEmpty(tempStack) == 0){
				push(stack,pop(&tempStack)->value);
			}
			free(tempStack);
			break;			
		}else{
			push(&tempStack, pop(stack)->value);
			swap = 1;
			
		}
	}
}


Node* sortStackAsc(Node** top){

	Node* finalStack = newStack();

	
	while(isEmpty(*top) == 0){
		
		if(isEmpty(finalStack) == 1 || peek(*top) <= peek(finalStack)){
			push(&finalStack,pop(top)->value);
		}else{
			if(peek(*top) > peek(finalStack)){
				pushInOrder(&finalStack, pop(top)->value);
			}
		}
	}
	return finalStack;
}
#endif