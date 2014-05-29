#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "stack.c"

int main(void)
{
	Node* stack = newStack();

	assert(stack == NULL);

	push(&stack,1);
	assert(stack != NULL);
	assert(stack->value == 1);
	assert(stack->size == 1);

	push(&stack,2);
	assert(stack->value == 2 && stack->previous->value == 1);
	assert(stack->size == 2);

	Node* node = pop(&stack);
	assert(node->value == 2);
	assert(stack->value == 1);
	assert(stack->size == 1);


	
	node = pop(&stack);
	assert(node->value == 1);
	assert(stack == NULL);

	
	push(&stack,3);
	assert(stack != NULL);
	assert(stack->value == 3);
	assert(stack->size == 1);


return 0;
}
