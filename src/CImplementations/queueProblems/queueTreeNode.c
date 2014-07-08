#ifndef QUEUETREENODE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "queueTreeNode.h"

QueueTreeNode* newQueueTreeNode(){
	QueueTreeNode* head = NULL;
	return head;
}

void enqueue(QueueTreeNode** head,QueueTreeNode** tail, Node* node){
	QueueTreeNode* newNode = (QueueTreeNode*) malloc (sizeof(QueueTreeNode));
	newNode->node = node;
	newNode->next = NULL;

	if(*head == NULL){
		*head = newNode;
		*tail = *head;
	}else{
		(*tail)->next = newNode;
		*tail = newNode; 
	}
}



Node* dequeue(QueueTreeNode** head,QueueTreeNode** tail){

	if(*head != NULL){
		QueueTreeNode* temp = *head;
		
		if(*head == *tail){
			*head = NULL;
			*tail = *head;
		}else{
			*head = temp->next;
			temp->next = NULL;
		}

		return temp->node;
	}else{
		return NULL;
	}
}
#endif