#ifndef TESTREMOVEDUPLICATES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "removeDuplicates.c"

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
	assert(size(list) == 0);
	removeDuplicates(list);
	assert(size(list) == 0);
}


void removeDuplicatesTestI(){

	Node* list = newLinkedlist();
	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 2;
	n3->next = NULL;
	
	n4->value = 3;
	n4->next = NULL;

	n5->value = 4;
	n5->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);

	assert(size(list) == 5);
	
	removeDuplicates(list);
	
	assert(size(list) == 4);

	assert(list->value == 1);
	assert(list->next->value == 2);
	assert(list->next->next->value == 3);
	assert(list->next->next->next->value == 4);
}

void removeDuplicatesTestII(){

	Node* list = newLinkedlist();
	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 1;
	n2->next = NULL;

	n3->value = 2;
	n3->next = NULL;
	
	n4->value = 3;
	n4->next = NULL;

	n5->value = 4;
	n5->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);

	assert(size(list) == 5);
	
	removeDuplicates(list);
	
	assert(size(list) == 4);

	assert(list->value == 1);
	assert(list->next->value == 2);
	assert(list->next->next->value == 3);
	assert(list->next->next->next->value == 4);
}

void removeDuplicatesTestIII(){

	Node* list = newLinkedlist();
	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 3;
	n3->next = NULL;
	
	n4->value = 3;
	n4->next = NULL;

	n5->value = 4;
	n5->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);

	assert(size(list) == 5);
	
	removeDuplicates(list);
	
	assert(size(list) == 4);

	assert(list->value == 1);
	assert(list->next->value == 2);
	assert(list->next->next->value == 3);
	assert(list->next->next->next->value == 4);
}

void removeDuplicatesTestIV(){

	Node* list = newLinkedlist();
	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 2;
	n3->next = NULL;
	
	n4->value = 3;
	n4->next = NULL;

	n5->value = 3;
	n5->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);

	assert(size(list) == 5);
	
	removeDuplicates(list);
	
	assert(size(list) == 3);

	assert(list->value == 1);
	assert(list->next->value == 2);
	assert(list->next->next->value == 3);
}

void removeDuplicatesTestV(){

	Node* list = newLinkedlist();
	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));
	Node* n4 = (Node*) malloc(sizeof(Node*));
	Node* n5 = (Node*) malloc(sizeof(Node*));

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 1;
	n2->next = NULL;

	n3->value = 1;
	n3->next = NULL;
	
	n4->value = 1;
	n4->next = NULL;

	n5->value = 1;
	n5->next = NULL;


	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);
	sortedInsert(&list, n4);
	sortedInsert(&list, n5);

	assert(size(list) == 5);
	
	removeDuplicates(list);
	
	assert(size(list) == 1);
}

int main(){

	emptyTest();
	removeDuplicatesTestI();
	removeDuplicatesTestII();
	removeDuplicatesTestIII();
	removeDuplicatesTestIV();
	removeDuplicatesTestV();

return 0;
}
#endif