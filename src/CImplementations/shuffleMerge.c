#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "linkedlist.c"

extern int errno;

Node* shuffleMerge(Node* a, Node* b){
	Node* res = NULL;
	
	if(a != NULL){
		Node* pA = a;
		Node* currentA = a->next;	

		Node* currentB = b;
		res = a;

		while(currentA != NULL){
			if(currentB!= NULL){
				Node* temp = currentB;
				currentB = currentB->next;

				pA->next = temp;
				temp->next = currentA;
				pA = currentA;
				currentA = currentA->next;
			}else{
				return res = a;
			}
		}
		pA->next = currentB;
		res = a;
	}else{
		return res = b;
	}

	return res;
}