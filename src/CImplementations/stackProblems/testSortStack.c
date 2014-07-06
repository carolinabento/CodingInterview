#ifndef TESTSORTSTACK

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "sortStack.c"

void testSort(){

	Node* stack = newStack();
	assert(stack == NULL);
	sortStackAsc(&stack);
	assert(stack == NULL);
}


void testSortI(){

	Node* stack = newStack();
	assert(stack == NULL);	
	push(&stack,3);
	push(&stack,10);
	push(&stack,5);
	push(&stack,1);
	push(&stack,4);
	push(&stack,7);
	push(&stack,9);

	assert(peek(stack) == 9);

	Node* sortedStack = sortStackAsc(&stack);

	assert(pop(&sortedStack)->value == 1);
	assert(pop(&sortedStack)->value == 3);
	assert(pop(&sortedStack)->value == 4);
	assert(pop(&sortedStack)->value == 5);
	assert(pop(&sortedStack)->value == 7);
	assert(pop(&sortedStack)->value == 9);
	assert(pop(&sortedStack)->value == 10);

	assert(stack == NULL);	
	
}

void testSortII(){

	Node* stack = newStack();
	assert(stack == NULL);	
	push(&stack,7);
	push(&stack,6);
	push(&stack,5);
	push(&stack,4);
	push(&stack,3);
	push(&stack,2);
	push(&stack,1);	

	Node* sortedStack = sortStackAsc(&stack);

	assert(pop(&sortedStack)->value == 1);
	assert(pop(&sortedStack)->value == 2);
	assert(pop(&sortedStack)->value == 3);
	assert(pop(&sortedStack)->value == 4);
	assert(pop(&sortedStack)->value == 5);
	assert(pop(&sortedStack)->value == 6);
	assert(pop(&sortedStack)->value == 7);

	assert(stack == NULL);	
	
}


void testSortIII(){

	Node* stack = newStack();
	assert(stack == NULL);	
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	push(&stack,4);
	push(&stack,5);
	push(&stack,6);
	push(&stack,7);	

	Node* sortedStack = sortStackAsc(&stack);

	assert(pop(&sortedStack)->value == 1);
	assert(pop(&sortedStack)->value == 2);
	assert(pop(&sortedStack)->value == 3);
	assert(pop(&sortedStack)->value == 4);
	assert(pop(&sortedStack)->value == 5);
	assert(pop(&sortedStack)->value == 6);
	assert(pop(&sortedStack)->value == 7);

	assert(stack == NULL);	
	
}
int main(void)
{

	testSort();
	testSortI();
	testSortII();
	testSortIII();

return 0;
}
#endif