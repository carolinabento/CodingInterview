#ifndef TESTMOVENODE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "moveNode.c"

extern int errno;


void sortedInsert(Node** headRef, Node* node){
	Node* current = *headRef;
	Node* prev = current;

	if(current == NULL || node->value <= current->value){
		*headRef = node;
		node->next = current;
	}else{
		current = current->next;

		while(current != NULL){
			if(prev->value <= node->value && current->value > node->value){
				node->next = current;
				break;
			}else{
				prev = current;
				current = current->next;
			}
		}

		prev->next = node;
	}

}

void emptyTest(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();
	Node* sourceRef = NULL;
	Node* destRef = NULL;

	assert(listA == NULL && listB == NULL);
	moveNode(&destRef,&sourceRef);
	assert(listA == NULL && listB == NULL);
}

void moveNodeEmptyA(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	assert(listA == NULL && listB == NULL);

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 3;
	n3->next = NULL;

	sortedInsert(&listB, n1);
	sortedInsert(&listB, n2);
	sortedInsert(&listB, n3);

	assert(size(listA) == 0);
	assert(size(listB) == 3);

	moveNode(&listA,&listB);

	assert(size(listA) == 1);
	assert(size(listB) == 2);

	assert(listA->value == 1);
	assert(listA->next == NULL);

	assert(listB->value == 2);
	assert(listB->next->value == 3);
	assert(listB->next->next == NULL);
}


void moveNodeEmptyB(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	assert(listA == NULL && listB == NULL);

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 3;
	n3->next = NULL;

	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);
	sortedInsert(&listA, n3);

	assert(size(listA) == 3);
	assert(size(listB) == 0);

	moveNode(&listA,&listB);

	assert(size(listA) == 3);
	assert(size(listB) == 0);

	assert(listA->value == 1);
	assert(listA->next->value == 2);
	assert(listA->next->next->value == 3);

	assert(listB == NULL);
}

void moveNodeTest(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	assert(listA == NULL && listB == NULL);

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
	
	n5->value = 2;
	n5->next = NULL;

	n6->value = 3;
	n6->next = NULL;

	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);
	sortedInsert(&listA, n3);

	sortedInsert(&listB, n4);
	sortedInsert(&listB, n5);
	sortedInsert(&listB, n6);

	assert(size(listA) == 3);
	assert(size(listB) == 3);

	moveNode(&listA,&listB);

	assert(size(listA) == 4);
	assert(size(listB) == 2);

	assert(listA->value == 1);
	assert(listA->next->value == 1);
	assert(listA->next->next->value == 2);
	assert(listA->next->next->next->value == 3);

	assert(listB->value == 2);
	assert(listB->next->value == 3);
}

int main(){

	emptyTest();
	moveNodeEmptyA();
	moveNodeEmptyB();
	moveNodeTest();

return 0;	
}
#endif