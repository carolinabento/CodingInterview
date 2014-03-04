#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "linkedlist.c"

extern int errno;

void moveNode(Node** destRef, Node** sourceRef){

	if(*sourceRef != NULL){
			Node* node = *sourceRef;

			*sourceRef = (*sourceRef)->next;
			node->next = *destRef;
			*destRef = node;
	}
}