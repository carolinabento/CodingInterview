#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "frontBackSplit.c"

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

void testOddSize(){
	Node* list = newLinkedlist();
	Node* headRef = NULL;
	Node* endRef = NULL;

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));

	n1->value = 2;
	n1->next = NULL;
	
	n2->value = 3;
	n2->next = NULL;

	n3->value = 5;
	n3->next = NULL;
	
	n4->value = 7;
	n4->next = NULL;

	n5->value = 11;
	n5->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);
	

	assert(list != NULL);
	assert(size(list) == 5);

	frontBackSplit(list,&headRef,&endRef);

	assert(size(headRef) == 3);
	assert(size(endRef) == 2);

	assert(headRef->value == 2);
	assert(headRef->next->value == 3);
	assert(headRef->next->next->value == 5);
	assert(headRef->next->next->next == NULL);

	assert(endRef->value == 7);
	assert(endRef->next->value == 11);
}


void testEvenSize(){
	Node* list = newLinkedlist();
	Node* headRef = NULL;
	Node* endRef = NULL;

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));

	n1->value = 2;
	n1->next = NULL;
	
	n2->value = 3;
	n2->next = NULL;

	n3->value = 5;
	n3->next = NULL;
	
	n4->value = 7;
	n4->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	

	assert(list != NULL);
	assert(size(list) == 4);

	frontBackSplit(list,&headRef,&endRef);

	assert(size(headRef) == 2);
	assert(size(endRef) == 2);

	assert(headRef->value == 2);
	assert(headRef->next->value == 3);

	assert(endRef->value == 5);
	assert(endRef->next->value == 7);
}

void testEmpty(){
	Node* list = newLinkedlist();
	Node* headRef = NULL;
	Node* endRef = NULL;

	assert(list == NULL);
	frontBackSplit(list,&headRef,&endRef);
	assert(headRef == NULL);
	assert(endRef == NULL);
}

int main(){

	testOddSize();
	testEvenSize();
	testEmpty();


return 0;
}