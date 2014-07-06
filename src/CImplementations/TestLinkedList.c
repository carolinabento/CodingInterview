#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "linkedlist.c"

int main(void)
{
	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	push(&list,1);
	assert(list != NULL);
	assert(size(list) == 1);
	assert(list->value == 1);

	push(&list,2);
	assert(size(list) == 2);
	assert(list->value == 2 && list->next->value == 1);

return 0;
}
