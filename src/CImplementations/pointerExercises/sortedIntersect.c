#ifndef SORTEDINTERSECT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../linkedlist.c"


void sortedInsert(Node** headRef, Node* node){
	Node* current = *headRef;
	Node* prev = current;

	if(current == NULL || node->value <= current->value){
		*headRef = node;
		node->next = current;
	}else{
		current = current->next;

		while(current != NULL){
			if(prev->value <= node->value && current->value > node->value){
				node->next = current;
				break;
			}else{
				prev = current;
				current = current->next;
			}
		}

		prev->next = node;
	}

}

Node* sortedIntersect(Node* a, Node* b){
	Node* res = NULL;

	if(a == NULL){
		return b;
	}else{
		if(b != NULL){
			Node* currentA = a;
			Node* currentB = b;

			while(currentA != NULL && currentB != NULL){
				if(currentB->value  == currentA->value){

					Node* temp = currentB;
					currentB = temp->next;
					
					temp->next = NULL;

					sortedInsert(&res, temp);
					currentA = currentA->next;
				}else{
					if(currentA->value  < currentB->value){
						currentA = currentA->next;
					}else{
						currentB = currentB->next;
					}
				}
			}
		}
	}
return res;
}
#endif