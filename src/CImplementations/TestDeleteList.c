#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "deleteList.c"

extern int errno;

void emptyTest(){

	Node* list = newLinkedlist();

	assert(list == NULL);
	assert(size(list) == 0);

	deleteList(&list);
	assert(list == NULL);
}

void deleteTest(){
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

	deleteList(&list);

	assert(size(list) == 0);
	assert(list == NULL);

}


int main(void)
{
	emptyTest();
	deleteTest();
	

return 0;
}