#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "queueTreeNode.c"


Node* arrayToTree(int* array, int length){
	QueueTreeNode* qHead = newQueueTreeNode();
	QueueTreeNode* qTail = qHead;

	Node* root = (Node*) malloc (sizeof(Node));
	root->left = NULL;
	root->right = NULL;

	Node* returnTree = root;

	if(length >= 1){
		root->number = array[0];
	}

	int i = 1;

	while(i + 1 < length){
		if(i > 1){
			root = dequeue(&qHead,&qTail);
		}

		root->left = (Node*) malloc (sizeof(Node));
		root->left->number = array[i];
		root->left->left = NULL;
		root->left->right = NULL;

		root->right = (Node*) malloc (sizeof(Node));
		root->right->number = array[i + 1];
		root->right->left = NULL;
		root->right->right = NULL;

		enqueue(&qHead,&qTail,root->left);	
		enqueue(&qHead,&qTail,root->right);

		i= i + 2;
	}
	
	if(i == length -1){
		root = dequeue(&qHead,&qTail);
		root->left->number = array[i];		
	}
	return returnTree;
}


int main()
{
	int array[7] = {1,2,3,4,5,6,7};

	Node* tree = arrayToTree(array,7);

	assert(tree->number == 1);
	assert(tree->left->number == 2);
	assert(tree->right->number == 3);
	assert(tree->left->left->number == 4);
	assert(tree->left->right->number == 5);
	assert(tree->right->left->number == 6);
	assert(tree->right->right->number == 7);

	return 0;
}