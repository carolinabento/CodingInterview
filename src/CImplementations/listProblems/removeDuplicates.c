#ifndef REMOVEDUPLICATES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../linkedlist.c"

void removeDuplicates(Node* head){

	if(head != NULL){
		Node* current = head;
		Node* prev;
		int lastNumber;

		while(current != NULL){
			
			if(current->value != lastNumber){
				lastNumber = current->value;
				prev = current;
				current = current->next;
			}else{
				Node* temp = current;
				current = current->next;
				prev->next = current;
				temp->next = NULL;
				free(temp);
			}
		}	
	}
}
#endif