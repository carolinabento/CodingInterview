#ifndef TESTSORTEDINSERT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "sortedInsert.c"


void testInsertHeadI(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	Node* n1 = (Node*) malloc (sizeof(Node*));
	n1->value = 1;
	n1->next = NULL;

	sortedInsert(&list, n1);

	assert(size(list) == 1);
	assert(list->value == 1);
}


void testInsertI(){
	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	Node* n1 = (Node*) malloc (sizeof(Node*));
	n1->value = 1;
	n1->next = NULL;

	Node* n2 = (Node*) malloc (sizeof(Node*));
	n2->value = 3;
	n2->next = NULL;

	sortedInsert(&list, n1);

	assert(size(list) == 1);
	assert(list->value == 1);

	sortedInsert(&list, n2);
	assert(size(list) == 2);
	assert(list->next->value == 3);

}


void testInsertII(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	Node* n1 = (Node*) malloc (sizeof(Node*));
	n1->value = 1;
	n1->next = NULL;

	Node* n2 = (Node*) malloc (sizeof(Node*));
	n2->value = 3;
	n2->next = NULL;


	Node* n3 = (Node*) malloc (sizeof(Node*));
	n3->value = 4;
	n3->next = NULL;

	Node* n4 = (Node*) malloc (sizeof(Node*));
	n4->value = 6;
	n4->next = NULL;

	Node* n5 = (Node*) malloc (sizeof(Node*));
	n5->value = 2;
	n5->next = NULL;

	Node* n6 = (Node*) malloc (sizeof(Node*));
	n6->value = 5;
	n6->next = NULL;

	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);
	sortedInsert(&list, n6);

	assert(size(list) == 6);
	assert(list->value == 1);
	assert(list->next->value == 2);
	assert(list->next->next->value == 3);
	assert(list->next->next->next->value == 4);
	assert(list->next->next->next->next->value == 5);
	assert(list->next->next->next->next->next->value == 6);
}




void testInsertHeadII(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	Node* n1 = (Node*) malloc (sizeof(Node*));
	n1->value = 1;
	n1->next = NULL;

	Node* n2 = (Node*) malloc (sizeof(Node*));
	n2->value = 3;
	n2->next = NULL;


	Node* n3 = (Node*) malloc (sizeof(Node*));
	n3->value = 4;
	n3->next = NULL;

	Node* n4 = (Node*) malloc (sizeof(Node*));
	n4->value = 6;
	n4->next = NULL;

	Node* n5 = (Node*) malloc (sizeof(Node*));
	n5->value = 2;
	n5->next = NULL;

	Node* n6 = (Node*) malloc (sizeof(Node*));
	n6->value = 5;
	n6->next = NULL;

	Node* n7 = (Node*) malloc (sizeof(Node*));
	n7->value = 0;
	n7->next = NULL;

	Node* n8 = (Node*) malloc (sizeof(Node*));
	n8->value = 0;
	n8->next = NULL;

	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);
	sortedInsert(&list, n6);

	assert(size(list) == 6);
	assert(list->value == 1);
	assert(list->next->value == 2);
	assert(list->next->next->value == 3);
	assert(list->next->next->next->value == 4);
	assert(list->next->next->next->next->value == 5);
	assert(list->next->next->next->next->next->value == 6);


	sortedInsert(&list, n7);
	assert(size(list) == 7);
	assert(list->value == 0);
	assert(list->next->value == 1);
	assert(list->next->next->value == 2);
	assert(list->next->next->next->value == 3);
	assert(list->next->next->next->next->value == 4);
	assert(list->next->next->next->next->next->value == 5);
	assert(list->next->next->next->next->next->next->value == 6);

	

	sortedInsert(&list, n8);
	assert(size(list) == 8);
	assert(list->value == 0);
	assert(list->next->value == 0);

}

void testInsertExisting(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	Node* n1 = (Node*) malloc (sizeof(Node*));
	n1->value = 1;
	n1->next = NULL;

	Node* n2 = (Node*) malloc (sizeof(Node*));
	n2->value = 3;
	n2->next = NULL;


	Node* n3 = (Node*) malloc (sizeof(Node*));
	n3->value = 4;
	n3->next = NULL;

	Node* n4 = (Node*) malloc (sizeof(Node*));
	n4->value = 6;
	n4->next = NULL;

	Node* n5 = (Node*) malloc (sizeof(Node*));
	n5->value = 2;
	n5->next = NULL;

	Node* n6 = (Node*) malloc (sizeof(Node*));
	n6->value = 5;
	n6->next = NULL;

	Node* n7 = (Node*) malloc (sizeof(Node*));
	n7->value = 0;
	n7->next = NULL;

	Node* n8 = (Node*) malloc (sizeof(Node*));
	n8->value = 0;
	n8->next = NULL;

	Node* n9 = (Node*) malloc (sizeof(Node*));
	n9->value = 3;
	n9->next = NULL;

	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);
	sortedInsert(&list, n6);
	sortedInsert(&list, n7);
	sortedInsert(&list, n8);
	sortedInsert(&list, n9);
	
	assert(size(list) == 9);
	assert(list->value == 0);
	assert(list->next->value == 0);
	assert(list->next->next->value == 1);
	assert(list->next->next->next->value == 2);
	assert(list->next->next->next->next->value == 3);
	assert(list->next->next->next->next->next->value == 3);
	assert(list->next->next->next->next->next->next->value == 4);
	assert(list->next->next->next->next->next->next->next->value == 5);
	assert(list->next->next->next->next->next->next->next->next->value == 6);

}




int main(void)
{

	testInsertHeadI();

	testInsertI();

	testInsertII();

	testInsertExisting();
return 0;
}
#endif