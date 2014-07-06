#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "sortedIntersect.c"

extern int errno;

void emptyTest(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	assert(listA == NULL && listB == NULL);
	assert(sortedIntersect(listA, listB) == NULL);
}


void sortedIntersectTestI(){
	
	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));
	Node* n6 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 3;
	n3->next = NULL;

	n4->value = 1;
	n4->next = NULL;

	n5->value = 5;
	n5->next = NULL;

	n6->value = 6;
	n6->next = NULL;

	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);
	sortedInsert(&listA, n3);

	sortedInsert(&listB, n4);
	sortedInsert(&listB, n5);
	sortedInsert(&listB, n6);
	

	assert(listA != NULL && listB != NULL);

	
	Node* resList = newLinkedlist();
	resList = sortedIntersect(listA,listB);

	assert(resList->value == 1);


}

void sortedIntersectTestII(){
	
	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));
	Node* n6 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 5;
	n3->next = NULL;

	n4->value = 3;
	n4->next = NULL;

	n5->value = 4;
	n5->next = NULL;

	n6->value = 5;
	n6->next = NULL;

	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);
	sortedInsert(&listA, n3);

	sortedInsert(&listB, n4);
	sortedInsert(&listB, n5);
	sortedInsert(&listB, n6);
	

	assert(listA != NULL && listB != NULL);

	
	Node* resList = newLinkedlist();
	resList = sortedIntersect(listA,listB);

	assert(resList->value == 5);
}

void sortedIntersectTestIII(){
	
	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));
	Node* n6 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 5;
	n3->next = NULL;

	n4->value = 1;
	n4->next = NULL;

	n5->value = 2;
	n5->next = NULL;

	n6->value = 4;
	n6->next = NULL;

	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);
	sortedInsert(&listA, n3);

	sortedInsert(&listB, n4);
	sortedInsert(&listB, n5);
	sortedInsert(&listB, n6);
	

	assert(listA != NULL && listB != NULL);

	
	Node* resList = newLinkedlist();
	resList = sortedIntersect(listA,listB);

	assert(resList->value == 1);
	assert(resList->next->value == 2);
	
}

int main(){
	emptyTest();
	sortedIntersectTestI();
	sortedIntersectTestII();
	sortedIntersectTestIII();
return 0;
}