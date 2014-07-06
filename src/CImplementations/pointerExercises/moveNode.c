#ifndef MOVENODE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../linkedlist.c"


void moveNode(Node** destRef, Node** sourceRef){

	if(*sourceRef != NULL){
			Node* node = *sourceRef;

			*sourceRef = (*sourceRef)->next;
			node->next = *destRef;
			*destRef = node;
	}
}
#endif