#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "queueTreeNode.c"

int main(void)
{
	QueueTreeNode* head = newQueueTreeNode();
	QueueTreeNode* tail = head;

	assert(head == NULL);
	assert(tail == NULL);
	
	Node* node = (Node*) malloc (sizeof(Node));
	node->number = 1;
	node->left = NULL;
	node->right = NULL;

	enqueue(&head,&tail,node);

	assert(head->node->number == 1);
	assert(tail->node->number == 1);

	Node* node1 = (Node*) malloc (sizeof(Node));
	node1->number = 2;
	node1->left = NULL;
	node1->right = NULL;

	Node* node2 = (Node*) malloc (sizeof(Node));
	node2->number = 3;
	node2->left = NULL;
	node2->right = NULL;

	enqueue(&head,&tail,node1);
	enqueue(&head,&tail,node2);

	assert(head->node->number == 1);
	assert(head->next->node->number == 2);
	assert(tail->node->number == 3);

	assert(dequeue(&head,&tail) == node);

	assert(head->node->number == 2);
	assert(tail->node->number == 3);

	assert(dequeue(&head,&tail) == node1);

	assert(head->node->number == 3);
	assert(tail->node->number == 3);

	assert(dequeue(&head,&tail) == node2);

	assert(head == NULL);
	assert(tail == NULL);

	assert(dequeue(&head,&tail) == NULL);
return 0;
}
