#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "linkedlist.c"

int error = ECANCELED;


int pop(Node** headRef){
int res = 0;

	if(*headRef == NULL){
		//puts("Pop Operation on an empty list!");
		puts(strerror(error));
	}else{

		Node* temp = *headRef;

		*headRef = (*headRef)->next;
		temp->next = NULL;
		res = temp->value;
		free(temp);
	}
return res;
}