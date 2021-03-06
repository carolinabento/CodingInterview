#ifndef REVERSE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "../linkedlist.c"


void moveNode(Node** destRef, Node** sourceRef){

	if(*sourceRef != NULL){
			Node* node = *sourceRef;

			*sourceRef = (*sourceRef)->next;
			node->next = *destRef;
			*destRef = node;
	}
}

void reverse(Node** a){
	Node* res = NULL;
	Node* current = *a;
	Node* first = *a;

	while(current != NULL){
		moveNode(&res,&current);
	}
	*a = res;

}
#endif