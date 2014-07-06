#ifndef TESTNODESUM

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "nodeSum.c"

void testNull(){

	Node* head1 = newLinkedlist();
	Node* head2 = newLinkedlist();

	assert(nodeSum(head1,head2) == NULL);

}

void testANull(){

	Node* head1 = newLinkedlist();
	Node* head2 = newLinkedlist();

	push(&head2,1);

	assert(nodeSum(head1,head2) == head2);

}

void testBNull(){

	Node* head1 = newLinkedlist();
	Node* head2 = newLinkedlist();

	push(&head1,1);

	assert(nodeSum(head1,head2) == head1);

}


void testABI(){

	Node* head1 = newLinkedlist();
	Node* head2 = newLinkedlist();

	push(&head1,3);
	push(&head1,2);
	push(&head1,1);

	push(&head2,2);
	push(&head2,2);

	Node* res = nodeSum(head1,head2);
	assert(res->value == 100);
	assert(res->next->value == 40);
	assert(res->next->next->value == 5);

}


void testBAI(){

	Node* head1 = newLinkedlist();
	Node* head2 = newLinkedlist();

	push(&head2,3);
	push(&head2,2);
	push(&head2,1);

	push(&head1,2);
	push(&head1,2);

	Node* res = nodeSum(head1,head2);
	assert(res->value == 100);
	assert(res->next->value == 40);
	assert(res->next->next->value == 5);

}

void testABII(){

	Node* head1 = newLinkedlist();
	Node* head2 = newLinkedlist();

	push(&head1,3);
	push(&head1,2);
	push(&head1,1);

	push(&head2,3);
	push(&head2,2);
	push(&head2,1);

	Node* res = nodeSum(head1,head2);
	assert(res->value == 200);
	assert(res->next->value == 40);
	assert(res->next->next->value == 6);

}

void testABIII(){

	Node* head1 = newLinkedlist();
	Node* head2 = newLinkedlist();

	push(&head1,1);
	push(&head1,1);
	push(&head1,1);

	push(&head2,2);
	push(&head2,2);
	push(&head2,2);

	Node* res = nodeSum(head1,head2);
	assert(res->value == 300);
	assert(res->next->value == 30);
	assert(res->next->next->value == 3);

}

int main(){

	testNull();
	testANull();
	testBNull();
	testABI();
	testBAI();
	testABII();
	testABIII();

	return 0;
}
#endif