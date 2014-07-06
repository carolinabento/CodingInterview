#ifndef GETNTH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "../linkedlist.c"


int getNth(Node* head, int index){
	int pos = 0;

	Node* current = head;

	if(size(head) - 1  < index){
		puts("Index out of bounds!");
		return INT_MAX;
	}

	while(current != NULL && pos < index){
		current = current->next;
		pos++;
	}



return current->value;
}
#endif