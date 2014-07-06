#ifndef TESTAPPEND

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "append.c"

extern int errno;

void testAppend(){
	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	assert(listA == NULL && listB == NULL);
	assert(size(listA) == 0 && size(listB) == 0);

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	n2->value = 2;
	n2->next = NULL;

	n3->value = 3;
	n3->next = NULL;
	n4->value = 4;
	n4->next = NULL;

	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);

	sortedInsert(&listB, n3);
	sortedInsert(&listB, n4);
	
	assert(size(listA) == 2 && size(listB) == 2);

	append(&listA,&listB);
	assert(size(listA) == 4);

	assert(listA->value == 1);
	assert(listA->next->value == 2);
	assert(listA->next->next->value == 3);
	assert(listA->next->next->next->value == 4);
}

void testEmptyAList(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	assert(listA == NULL && listB == NULL);
	assert(size(listA) == 0 && size(listB) == 0);

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));

	n1->value = 3;
	n1->next = NULL;
	n2->value = 4;
	n2->next = NULL;

	sortedInsert(&listB, n1);
	sortedInsert(&listB, n2);

	assert(size(listA) == 0 && size(listB) == 2);
	append(&listA,&listB);
	assert(size(listA) == 2);
	assert(listA->value == 3);
	assert(listA->next->value == 4);
}

void testEmptyBList(){
	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	assert(listA == NULL && listB == NULL);
	assert(size(listA) == 0 && size(listB) == 0);


	listA = newLinkedlist();
	listB = newLinkedlist();

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	n2->value = 2;
	n2->next = NULL;

	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);

	append(&listA,&listB);
	assert(size(listA) == 2);
	assert(listA->value == 1);
	assert(listA->next->value == 2);
}


int main(void)
{

	testAppend();
	testEmptyAList();
	testEmptyBList();
	
return 0;
}
#endif