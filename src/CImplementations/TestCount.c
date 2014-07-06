#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "count.c"

void testEmpty(){

	Node* list = newLinkedlist();
	assert(list == NULL);
	assert(size(list) == 0);
	assert(count(list,1) == 0);
}

void testCount(){

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

	assert(count(list,2) == 1);

}

int main(void)
{
	testEmpty();

	testCount();
	
return 0;
}