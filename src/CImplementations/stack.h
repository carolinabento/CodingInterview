#ifndef STACK_H

typedef struct Node{
	int value;
	int size;
	struct Node* previous;
	struct Node* next;
}Node;
#endif