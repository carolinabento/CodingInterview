typedef struct Node{
	int value;
	int size;
	struct Node* previous;
	struct Node* next;
	struct Node* tail;
}Node;