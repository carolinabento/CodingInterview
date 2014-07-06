#ifndef TESTMERGESORT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "mergeSort.c"

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
	assert(mergeSort(list) == NULL);
}


void mergeTestI(){

	Node* list = newLinkedlist();

	assert(list == NULL);


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
	
	n4->value = 4;
	n4->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);

	Node* res = mergeSort(list);

	assert(res != NULL);
	assert(res->value == 1);
	assert(res->next->value == 2);
}
int main(){
	emptyTest();
	mergeTestI();
return 0;
}
#endif