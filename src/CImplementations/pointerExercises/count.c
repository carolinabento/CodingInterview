#ifndef COUNT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../linkedlist.c"

int count(Node* head, int value){
int res = 0;

	Node* current = head;

	while(current != NULL){

		if(current->value == value){
			res++;
		}

		current = current->next;
	}

return res;
}
#endif