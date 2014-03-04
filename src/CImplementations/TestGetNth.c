#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "getNth.c"

extern int errno;


void testEmpty(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	assert(getNth(list,0) == 1);
}


void testGetNth(){
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

	assert(getNth(list,0) == 1);
	assert(getNth(list,1) == 2);
	assert(getNth(list,2) == 3);
}

void testFail(){
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

	assert(getNth(list,0) == 1);
	assert(getNth(list,1) == 2);
	assert(getNth(list,2) == 3);

	assert(getNth(list,10) == 1);

}

int main(void)
{
	testEmpty();

	testGetNth();

	testFail();
return 0;
}