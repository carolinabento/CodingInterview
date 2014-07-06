#ifndef LINKEDLIST 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "linkedlist.h"

Node* newLinkedlist(){
	Node* head = NULL;

return head;
}

Node* push(Node** head, int value){
	Node* node = (Node*) malloc (sizeof(Node*));

	node->value = value;
	node->next = *head;
	*head = node;

return *head;
}


int size(Node* head){
int len = 0;
	
	Node* current = head;
	
	while(current != NULL){
		len++;
		current = current->next;
	}

return len;
}

Node* removeFirst(Node** head){
	Node* temp = *head;

	*head= (*head)->next;
	temp->next = NULL;
	free(temp);

return *head;
}
#endif