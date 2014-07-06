#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "alternatingSplit.c"

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
	Node* aRef = NULL;
	Node* bRef = NULL;

	assert(list == NULL);
	alternatingSplit(list,&aRef,&bRef);
	assert(list == NULL);
}



void alternateSplitTestI(){

	Node* list = newLinkedlist();
	Node* aRef = NULL;
	Node* bRef = NULL;

	Node* n1 = (Node*) malloc(sizeof(Node*));
	Node* n2 = (Node*) malloc(sizeof(Node*));
	Node* n3 = (Node*) malloc(sizeof(Node*));

	assert(list == NULL);

	n1->value = 1;
	n1->next = NULL;
	
	n2->value = 2;
	n2->next = NULL;

	n3->value = 3;
	n3->next = NULL;

	sortedInsert(&list, n1);
	sortedInsert(&list, n2);
	sortedInsert(&list, n3);

	alternatingSplit(list,&aRef,&bRef);
	assert(aRef != NULL && bRef != NULL);
	assert(aRef->value == 1);
	assert(aRef->next->value == 3);
	assert(aRef->next->next == NULL);

	assert(bRef->value == 2);
	assert(bRef->next == NULL);
}


void alternateSplitTestII(){

	Node* list = newLinkedlist();
	Node* aRef = NULL;
	Node* bRef = NULL;

	Node* n1 = (Node*) malloc(sizeof(Node*));

	assert(list == NULL);

	n1->value = 1;
	n1->next = NULL;

	assert(n1->next == NULL);

	sortedInsert(&list, n1);

	alternatingSplit(list,&aRef,&bRef);
	
	assert(aRef != NULL && bRef == NULL);
	assert(aRef->value == 1);
	assert(aRef->next == NULL);

	assert(bRef == NULL);
}


int main(){

	emptyTest();
	alternateSplitTestI();
	alternateSplitTestII();
return 0;
}