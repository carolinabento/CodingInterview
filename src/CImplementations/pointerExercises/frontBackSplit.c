#ifndef FRONTBACKSPLIT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "../linkedlist.c"


void frontBackSplit(Node* source, Node** frontRef, Node** endRef){

	if(source != NULL){
		Node* current = source;
		int halfList = ceil(size(source)/2.0);
		int index = 1;

		while(index < halfList){
			current = current->next;
			index++;
		}
		
	*endRef = current->next;
	current->next = NULL;
	*frontRef = source;
	}
}
#endif