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
		push(&(*mq)->s1, pop(&(*mq)->s2));
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
	int res = INT_MAX;
	if(*mq != NULL){
		if((*mq)->s1->size > 0){
			res = pop(&(*mq)->s1);
			
		}else{
			if((*mq)->s2->size > 0){
				switchStack(mq);
				res = pop(&(*mq)->s1);
			}
		}
	}
	return res;
}


#endif