#ifndef ARRAYTOTREE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "queueTreeNode.c"


Node* arrayToTree(int* array, int length){
	QueueTreeNode* qHead = newQueueTreeNode();
	QueueTreeNode* qTail = qHead;

	Node* root = NULL;
	Node* returnTree = NULL;
	int i;

	if(length >= 1){
		
		root = (Node*) malloc (sizeof(Node));
		root->number = array[0];
		root->left = NULL;
		root->right = NULL;

		returnTree = root;
	

		i = 1;

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
	}else{
		if(i == length -1){
			root = dequeue(&qHead,&qTail);
			root->left->number = array[i];		
		}
	}
	return returnTree;
}
#endif