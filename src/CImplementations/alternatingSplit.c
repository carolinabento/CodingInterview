#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "linkedlist.c"

extern int errno;

void alternatingSplit(Node* source, Node** aRef, Node** bRef){

	if(source != NULL){
		*aRef = source;
		*bRef = source->next;

		Node* lastA = *aRef;
		Node* lastB = *bRef;
		
		while(lastB != NULL){	
			lastA->next = lastB->next;
			lastA = lastA->next;
			lastB->next = lastA->next;
			lastB = lastB->next;
		}
		lastA->next = NULL;

	}

}