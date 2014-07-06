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

void recursiveFunction(Node* source,Node** destRef){

	if(source == NULL){
		return;
	}else{
		moveNode(destRef,&source);
		recursiveFunction(source,destRef);
	}
	
}

/*Node* recursiveFunction(Node* source){
	if(source == NULL){
		return;
	}else{
		Node* list = 
		moveNode(destRef,&source);
		recursiveFunction(source,destRef);
	}
	
}*/

void recursiveReverse(Node** headRef){
	Node* res = NULL;

	recursiveFunction(headRef);

	*headRef = res;
}

