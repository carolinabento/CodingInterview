#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "linkedlist.c"

extern int errno;



int getNth(Node* head, int index){
	int pos = 0;

	Node* current = head;

	if(size(head) - 1  < index){
		puts("Index out of bounds!");
		puts(strerror(errno));
	}

	while(current != NULL && pos < index){
		current = current->next;
		pos++;
	}



return current->value;
}