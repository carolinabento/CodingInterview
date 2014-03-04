#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "linkedlist.c"

extern int errno;

void deleteList(Node** headRef){

	Node* temp = *headRef;

	while(temp != NULL){
		*headRef = temp->next;
		temp->next = NULL;
		free(temp);
		temp = *headRef;
	}
	
	temp = NULL;
	*headRef = NULL;
}