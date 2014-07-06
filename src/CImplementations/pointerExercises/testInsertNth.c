#ifndef TESTINSERTNTH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "insertNth.c"

extern int errno;

void testOutOfBounds(){
	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	insertNth(&list,1,13);
}

void testInsert(){
	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	insertNth(&list,0,13);
	assert(size(list) == 1);
	assert(list->value == 13);

	insertNth(&list,1,42);
	assert(size(list) == 2);
	assert(list->next->value == 42);

	insertNth(&list,2,5);
	assert(size(list) == 3);
	assert(list->next->next->value == 5);

}


int main(void)
{
	testOutOfBounds();
	testInsert();

return 0;
}
#endif