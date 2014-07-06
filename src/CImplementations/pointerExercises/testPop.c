#ifndef TESTPOP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "pop.c"

extern int errno;

void testEmpty(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0); 
	pop(&list);
}

void testPop(){
	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	push(&list, 3);
	push(&list, 2);
	push(&list, 1);

	assert(size(list) == 3);

	assert(list->value == 1);
	assert(list->next->value == 2);
	assert(list->next->next->value == 3);

	assert(pop(&list) == 1);
	assert(size(list) == 2);
	assert(list->value == 2);
	assert(list->next->value == 3);


	assert(pop(&list) == 2);
	assert(size(list) == 1);
	assert(list->value == 3);

	assert(pop(&list) == 3);
	assert(size(list) == 0);
	assert(list == NULL);
}

int main(void)
{
	testEmpty();
	testPop();
	
return 0;
}
#endif