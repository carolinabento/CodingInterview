#ifndef DELETELIST

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../linkedlist.c"


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
#endif