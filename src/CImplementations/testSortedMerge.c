#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "sortedMerge.c"

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

	assert(listA == NULL && listB == NULL);
	assert(sortedMerge(listA,listB) == NULL);
}


void emptyATest(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 5;
	n3->next = NULL;


	sortedInsert(&listB, n1);
	sortedInsert(&listB, n2);
	sortedInsert(&listB, n3);


	assert(listA == NULL && listB != NULL);

	
	Node* resList = newLinkedlist();
	resList = sortedMerge(listA,listB);

	assert(resList->value == 1);
	assert(resList->next->value == 2);
	assert(resList->next->next->value == 5);
}


void emptyBTest(){

	Node* listA = newLinkedlist();
	Node* listB = newLinkedlist();

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 5;
	n3->next = NULL;


	sortedInsert(&listA, n1);
	sortedInsert(&listA, n2);
	sortedInsert(&listA, n3);


	assert(listA != NULL && listB == NULL);

	
	Node* resList = newLinkedlist();
	resList = sortedMerge(listA,listB);

	assert(resList->value == 1);
	assert(resList->next->value == 2);
	assert(resList->next->next->value == 5);
}


void sortedMergeTest(){

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
	resList = sortedMerge(listA,listB);

	assert(resList->value == 1);
	assert(resList->next->value == 2);
	assert(resList->next->next->value == 3);
	assert(resList->next->next->next->value == 4);
	assert(resList->next->next->next->next->value == 5);
	assert(resList->next->next->next->next->next->value == 6);
}


void sortedMergeTestI(){

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

	n5->value = 4;
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
	resList = sortedMerge(listA,listB);

	assert(resList->value == 1);
	assert(resList->next->value == 1);
	assert(resList->next->next->value == 2);
	assert(resList->next->next->next->value == 4);
	assert(resList->next->next->next->next->value == 5);
	assert(resList->next->next->next->next->next->value == 6);
}
int main(){
	
	emptyTest();
	emptyATest();
	emptyBTest();
	sortedMergeTest();
	sortedMergeTestI();

return 0;	
}