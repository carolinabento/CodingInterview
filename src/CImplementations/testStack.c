#ifndef TESTSTACK

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "stack.c"

int main(void)
{
	Node* stack = newStack();

	assert(stack == NULL);
	assert(isEmpty(stack) == 1);

	push(&stack,1);
	assert(stack != NULL);
	assert(stack->value == 1);
	assert(stack->size == 1);
	assert(peek(stack) == 1);

	push(&stack,2);
	assert(stack->value == 2 && stack->previous->value == 1);
	assert(stack->size == 2);
	assert(peek(stack) == 2);

	assert(pop(&stack) == 2);
	assert(stack->value == 1);
	assert(stack->size == 1);

	assert(pop(&stack) == 1);
	assert(stack == NULL);
	
	push(&stack,3);
	assert(stack != NULL);
	assert(stack->value == 3);
	assert(stack->size == 1);


return 0;
}
#endif