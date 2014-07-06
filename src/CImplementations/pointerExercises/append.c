#ifndef APPEND

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sortedInsert.c"


void append(Node** headRefA, Node** headRefB){

	Node* current = *headRefA;

	if(current == NULL && *headRefB != NULL){
		*headRefA = *headRefB;
	}else{
		while(current->next != NULL){
			current = current->next;
		}

		current->next= *headRefB;
		*headRefB = NULL;
	}
}
#endif