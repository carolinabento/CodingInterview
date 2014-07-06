#ifndef MERGESORT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "../linkedlist.c"

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


Node* recursiveFunction(Node* head, Node** leftSide, Node** rightSide){	
	Node** frontRef = (Node**) malloc (sizeof(Node**));
	Node** endRef = (Node**) malloc (sizeof(Node**));
	Node* midRes = NULL;

	frontBackSplit(head, frontRef,endRef);
	leftSide = frontRef;	
	rightSide = endRef;

	if((*leftSide)->next == NULL){
		midRes = sortedMerge(*leftSide,*rightSide);		
	}else{
		Node** frontRef = (Node**) malloc (sizeof(Node**));
		Node** endRef = (Node**) malloc (sizeof(Node**));
		midRes = sortedMerge(recursiveFunction(*leftSide,frontRef,endRef), recursiveFunction(*rightSide,frontRef,endRef));
	}
	

return midRes;
}

Node* mergeSort(Node* head){
	if(head == NULL){
		return NULL;
	}else{
		Node* result = recursiveFunction(head, NULL, NULL);
		return result;
	}
}
#endif

