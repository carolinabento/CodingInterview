#ifndef LINKEDLIST_H

typedef struct Node{
	int value;
	struct Node* next;
}Node;

Node* newLinkedList();
int size(Node*);
Node* push(Node**, int);
#endif