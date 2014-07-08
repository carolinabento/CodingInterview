#ifndef QUEUEFROMSTACK

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "myQueue.h"
#include "../stack.c"


MyQueue* newMyQueue(){
	MyQueue* mq = NULL;
	return mq;
}

void switchStack(MyQueue** mq){

	while((*mq)->s2->size > 0){
		Node* node = pop(&(*mq)->s2);
		push(&(*mq)->s1, node->value);
	}
}


void enqueue(MyQueue** mq, int element){

	if(*mq != NULL){
		if((*mq)->s1->size == 0){
			push(&(*mq)->s1,element);
		}else{
			push(&(*mq)->s2,element);
		}
	}else{
		*mq = (MyQueue*) malloc (sizeof (MyQueue));
		(*mq)->s1 = (Node*) malloc (sizeof (Node));
		(*mq)->s2 = (Node*) malloc (sizeof (Node));
		push(&(*mq)->s1,element);
	}
}


int dequeue(MyQueue** mq){
	Node* node = (Node*) malloc (sizeof (Node));
	node->value = INT_MAX;

	if(*mq != NULL){
		if((*mq)->s1->size > 0){
			node = pop(&(*mq)->s1);
			return node->value;
		}else{
			if((*mq)->s2->size > 0){
				switchStack(mq);
				node = pop(&(*mq)->s1);
				return node->value;
			}
		}
	}
	
	return node->value;	
}


#endif