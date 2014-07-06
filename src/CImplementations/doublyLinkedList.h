#ifndef DOUBLYLINKEDLIST_H

typedef struct Node{
	int value;
	int size;
	struct Node* previous;
	struct Node* next;
	struct Node* tail;
}Node;
#endif