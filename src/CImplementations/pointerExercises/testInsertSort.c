#ifndef TESTINSERTSORT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "insertSort.c"

extern int errno;

void testSortedInsert(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	push(&list,0);
	push(&list,5);
	push(&list,1);
	push(&list,2);
	push(&list,3);

	assert(size(list) == 5);
	assert(list->value == 3);

	insertSort(&list);
	assert(size(list) == 5);
	assert(list->value == 0);
	assert(list->next->value == 1);
	assert(list->next->next->value == 2);
	assert(list->next->next->next->value == 3);
	assert(list->next->next->next->next->value == 5);
	assert(list->next->next->next->next->next == NULL);
}

int main(void)
{
	testSortedInsert();

return 0;
}
#endif