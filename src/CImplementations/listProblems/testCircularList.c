#ifndef TESTCIRCULARLIST

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "circularList.c"

void testNull(){
	Node* head = newLinkedlist();
	assert(getClosingNode(head) == NULL);
}

void testNonCircular(){
	Node* head = newLinkedlist();

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);

	//list: 4->3->2->1->//
	assert(head->value == 4);
	assert(head->next->value == 3);
	assert(head->next->next->value == 2);
	assert(head->next->next->next->value == 1);

	assert(head->next->next->next->next == NULL);

	assert(getClosingNode(head) == NULL);

}

void testCircular(){
	Node* head = newLinkedlist();

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);

	//list: 4->3->2->1->//
	assert(head->value == 4);
	assert(head->next->value == 3);
	assert(head->next->next->value == 2);
	assert(head->next->next->next->value == 1);

	assert(head->next->next->next->next == NULL);

	//closing the list to become circular
	head->next->next->next->next = head;

	//list: 4->3->2->1->4
	assert(head->value == 4);
	assert(head->next->value == 3);
	assert(head->next->next->value == 2);
	assert(head->next->next->next->value == 1);
	assert(head->next->next->next->next->value == 4);	

	assert(getClosingNode(head)->value == 1);
}

int main(void)
{
	testNull();
	testNonCircular();
	testCircular();

return 0;
}
#endif