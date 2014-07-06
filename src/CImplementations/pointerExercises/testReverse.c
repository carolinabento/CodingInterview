#ifndef TESTREVERSE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "reverse.c"

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

	Node* list = newLinkedlist();

	assert(list == NULL);
	reverse(&list);
}

void testReverse(){

	Node* list = newLinkedlist();
	
	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));


	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 3;
	n3->next = NULL;

	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);

	reverse(&list);

	assert(list->value == 3);
	assert(list->next->value == 2);
	assert(list->next->next->value == 1);

}

int main(){
	emptyTest();
	testReverse();
	return 0;
}
#endif