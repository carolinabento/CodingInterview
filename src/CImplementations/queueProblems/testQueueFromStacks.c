#ifndef TESTQUEUEFROMSTACKS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include "queueFromStacks.c"

void testCreateQueue(){
	MyQueue* mq = newMyQueue();

	assert(mq == NULL);
}

void testEnqueue(){
	MyQueue* mq = newMyQueue();

	assert(mq == NULL);

	enqueue(&mq,1);
	
	assert(mq != NULL);
	assert(mq->s1->size == 1);
	assert(mq->s1->value == 1);
}

void testEnqueueII(){
	MyQueue* mq = newMyQueue();

	assert(mq == NULL);

	enqueue(&mq,1);
	assert(mq != NULL);
	assert(mq->s1->size == 1);
	assert(mq->s1->value == 1);

	enqueue(&mq,2);
	assert(mq->s1->size == 1);
	assert(mq->s2->size == 1);
	assert(mq->s1->value == 1);
	assert(mq->s2->value == 2);

	enqueue(&mq,3);
	assert(mq->s1->size == 1);
	assert(mq->s2->size == 2);
	assert(mq->s1->value == 1);
	assert(mq->s2->value == 3);
	assert(mq->s2->previous->value == 2);
}

void testDequeue(){
	MyQueue* mq = newMyQueue();

	assert(mq == NULL);

	enqueue(&mq,1);
	assert(mq != NULL);
	assert(mq->s1->size == 1);
	assert(mq->s1->value == 1);

	assert(dequeue(&mq) == 1);
	dequeue(&mq);
}

void testDequeueII(){
	MyQueue* mq = newMyQueue();

	assert(mq == NULL);

	enqueue(&mq,1);
	assert(mq != NULL);
	assert(mq->s1->size == 1);
	assert(mq->s1->value == 1);

	
	enqueue(&mq,2);
	enqueue(&mq,3);
	assert(mq->s1->size == 1);
	assert(mq->s2->size == 2);


	assert(dequeue(&mq) == 1);
	assert(dequeue(&mq) == 2);
	assert(dequeue(&mq) == 3);

	assert(mq->s1->size == 0);
	assert(mq->s2->size == 0);
}


void testDequeueIII(){
	MyQueue* mq = newMyQueue();

	assert(mq == NULL);
	assert(dequeue(&mq) == INT_MAX);
}


int main(void)
{
	testCreateQueue();
	testEnqueue();
	testEnqueueII();
	testDequeue();
	testDequeueII();
	testDequeueIII();

return 0;
}
#endif