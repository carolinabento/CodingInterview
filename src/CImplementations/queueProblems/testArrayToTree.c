#ifndef TESTARRAYTOTREE 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "arrayToTree.c"

void testI(){

	int array[0] = {};

	Node* tree = arrayToTree(array,0);

	assert(tree == NULL);

}

void testII(){
	int array[7] = {1,2,3,4,5,6,7};

	Node* tree = arrayToTree(array,7);

	assert(tree->number == 1);
	assert(tree->left->number == 2);
	assert(tree->right->number == 3);
	assert(tree->left->left->number == 4);
	assert(tree->left->right->number == 5);
	assert(tree->right->left->number == 6);
	assert(tree->right->right->number == 7);
}

int main()
{

	testI();
	testII();
	
	return 0;
}
#endif