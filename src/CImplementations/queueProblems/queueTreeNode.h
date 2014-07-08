#ifndef QUETREENODE_H

typedef struct Node{
	int number;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct QueueTreeNode{
	struct Node* node;
	struct QueueTreeNode* next;
}QueueTreeNode;
#endif
