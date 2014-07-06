#ifndef CIRCULARLIST

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../linkedList.c"

Node* getClosingNode(Node* head){
	Node* res = NULL;
	if(head != NULL){
		Node* node1 = head;
		Node* node2 = head->next;

		while(node1 != node2 && node2->next != NULL){
			if(node1->value == node2->next->value){
				res = node2;
				return res;
			}else{
				node2 = node2->next;
			}
		}
	}	
	return res;
}
#endif