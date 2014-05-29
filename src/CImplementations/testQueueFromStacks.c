#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "queueFromStacks.c"

void testCreateStacks(){
	Node* stack1 = newStack();
	Node* stack2 = newStack();

	assert(stack1 == NULL);
	assert(stack2 == NULL);
}

void testEnqueue(){
	Node* stack1 = newStack();
	Node* stack2 = newStack();

	enqueue(&stack1,&stack2,1);
	assert(stack1 != NULL);
	assert(stack2 == NULL);

	assert(stack1->value ==1);
	assert(stack1->size ==1);

	enqueue(&stack1,&stack2,2);

	assert(stack1->value ==1);
	assert(stack1->size ==1);

	assert(stack2->value ==2);
	assert(stack2->size ==1);
}


void testDequeue(){
	Node* stack1 = newStack();
	Node* stack2 = newStack();

	enqueue(&stack1,&stack2,1);
	assert(stack1 != NULL);
	assert(stack2 == NULL);

	assert(stack1->value ==1);
	assert(stack1->size ==1);

	enqueue(&stack1,&stack2,2);

	assert(stack1->value ==1);
	assert(stack1->size ==1);

	assert(stack2->value == 2);
	assert(stack2->size == 1);

	enqueue(&stack1,&stack2,3);

	assert(stack1->value ==1);
	assert(stack1->size ==1);

	assert(stack2->value == 3);
	assert(stack2->previous->value == 2);
	assert(stack2->size == 2);

	Node* node = dequeue(&stack1,&stack2);
	assert(stack1 == NULL);
	assert(stack2->value == 3);
	assert(stack2->previous->value == 2);
	assert(stack2->size == 2);

	node = dequeue(&stack1,&stack2);

	assert(stack2 == NULL);
	assert(node->value == 2);
	assert(stack1->value == 3);
	assert(stack1->size == 1);

	enqueue(&stack1,&stack2,4);
	assert(stack1 != NULL);
	assert(stack2 != NULL);
	assert(stack1->value == 3);
	assert(stack2->value == 4);


	enqueue(&stack1,&stack2,5);
	assert(stack1->value == 3);
	assert(stack2->value == 5);


	node = dequeue(&stack1,&stack2);

	assert(node->value == 3);
	assert(stack1 == NULL);
	assert(stack2->value == 5);
	assert(stack2->previous->value == 4);

	node = dequeue(&stack1,&stack2);
	assert(node->value == 4);

	assert(stack1 != NULL);
	assert(stack2 == NULL);
	assert(stack1->value == 5);
	
	node = dequeue(&stack1,&stack2);
	assert(node->value == 5);
	assert(stack1 == NULL);
	assert(stack2 == NULL);

	node = dequeue(&stack1,&stack2);
	assert(node == NULL);


}


int main(void)
{
	testCreateStacks();
	testEnqueue();
	testDequeue();

return 0;
}