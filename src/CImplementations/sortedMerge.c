#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "linkedlist.c"

extern int errno;

Node* sortedMerge(Node* a, Node* b){

	Node* finalList = NULL;

	if(a != NULL){
		finalList = a;

		Node* prevA = a;
		Node* currentA = a;
		
		Node* currentB = b;

		if(currentB != NULL){
			while(currentA->next != NULL){
			
				if(currentB->value <= currentA->value){
					Node* temp = currentB;
					currentB= currentB->next;
					temp->next = prevA->next;
					prevA->next = temp;
					
					//free(temp);
				}else{
					prevA = currentA;
				}
				prevA = currentA;
				currentA = currentA->next;
			}
				

			while(currentB->next != NULL){
				if(currentB->value <= currentA->value){
					Node* temp = currentB;
					currentB = currentB->next;
					temp->next = prevA->next;
					prevA->next = temp;
					
				}else{
					currentA->next = currentB;
					break;
				}
				prevA = prevA->next;
			}
			currentA->next = currentB;
	}
	}else{
		finalList = b;
	}


return finalList;
}