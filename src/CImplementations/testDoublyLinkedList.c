#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "doublyLinkedList.c"

void testAppend(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);

	append(&head,1);
	assert(head->value == 1);
	assert(head->size == 1);
	assert(size(head) == 1);

	append(&head,2);
	assert(size(head) == 2);
	assert(head->value == 1);
	assert(head->next->value == 2);

	append(&head,3);
	assert(size(head) == 3);
	assert(head->value == 1);
	assert(head->next->value == 2);
	assert(head->next->next->value == 3);
}



void testPrepend(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);

	prepend(&head,3);
	assert(size(head) == 1);
	assert(head->value == 3);

	prepend(&head,2);
	assert(size(head) == 2);
	assert(head->value == 2);
	assert(head->next->value == 3);

	prepend(&head,1);
	assert(size(head) == 3);
	assert(head->value == 1);
	assert(head->next->value == 2);
	assert(head->next->next->value == 3);
}

void testRemoveFirstI(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);

	Node* node = removeFirst(&head);
	assert(node == NULL);

}

void testRemoveFirstII(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);

	append(&head,1);
	append(&head,2);
	append(&head,3);

	assert(size(head) == 3);

	Node* node = removeFirst(&head);
	assert(node->value == 1);
	assert(head->value == 2);
	assert(size(head) == 2);

	node = removeFirst(&head);
	assert(node->value == 2);
	assert(head->value == 3);
	assert(size(head) == 1);

	node = removeFirst(&head);
	assert(node->value == 3);
	assert(head == NULL);
	assert(size(head) == 0);
}


void testRemoveLastI(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);

	Node* node = removeLast(&head);
	assert(node == NULL);
	assert(size(head) == 0);
}

void testRemoveLastII(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);

	append(&head,1);
	Node* node = removeLast(&head);
	assert(node->value == 1);
	assert(size(head) == 0);
}

void testRemoveLastIII(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);

	append(&head,1);
	append(&head,2);
	append(&head,3);
	append(&head,4);
	Node* node = removeLast(&head);
	assert(node->value == 4);
	assert(size(head) == 3);

	node = removeLast(&head);
	assert(node->value == 3);
	assert(size(head) == 2);

	node = removeLast(&head);
	assert(node->value == 2);
	assert(size(head) == 1);

	node = removeLast(&head);
	assert(node->value == 1);
	assert(size(head) == 0);

	node = removeLast(&head);
	assert(node == NULL);
	assert(size(head) == 0);
}


void testRemoveI(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);
	Node* node = removeAtPos(&head,1);
	assert(node == NULL);
}

void testRemoveII(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);
	append(&head,1);
	Node* node = removeAtPos(&head,2);
	assert(node == NULL);
}

void testRemoveIII(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);
	append(&head,1);
	Node* node = removeAtPos(&head,1);
	assert(node->value == 1);
	assert(size(head) == 0);

}

void testRemoveIV(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);
	append(&head,1);
	append(&head,2);
	Node* node = removeAtPos(&head,2);
	assert(node->value == 2);
	assert(head->tail->value == 1);
	assert(size(head) == 1);
}

void testRemoveV(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);
	append(&head,1);
	append(&head,2);
	append(&head,3);
	Node* node = removeAtPos(&head,3);
	assert(node->value == 3);
	assert(head->tail->value == 2);
	assert(head->next->value == 2);
	assert(head->next->tail->value == 2);
	assert(size(head) == 2);
}

void testRemoveVI(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);
	append(&head,1);
	append(&head,2);
	append(&head,3);
	Node* node = removeAtPos(&head,1);
	assert(node->value == 1);
	assert(head->value == 2);
	assert(head->next->value == 3);
	assert(head->tail->value == 3);
	assert(head->next->tail->value == 3);
	assert(size(head) == 2);
}

void testRemoveVII(){
	Node* head = newDoublyLinkedList();

	assert(head == NULL);
	append(&head,1);
	append(&head,2);
	append(&head,3);
	append(&head,4);
	append(&head,5);
	Node* node = removeAtPos(&head,3);
	assert(node->value == 3);

	assert(head->value == 1);
	assert(head->next->value == 2);
	assert(head->next->next->value == 4);
	assert(head->next->next->next->value == 5);

	assert(head->tail->value == 5);
	assert(head->next->tail->value == 5);
	assert(head->next->next->tail->value == 5);
	assert(head->next->next->next->tail->value == 5);

	assert(size(head) == 4);
}

int main(void)
{
	testAppend();
	testPrepend();	

	testRemoveFirstI();
	testRemoveFirstII();

	testRemoveLastI();
	testRemoveLastII();

	testRemoveI();
	testRemoveII();
	testRemoveIII();
	testRemoveIV();
	testRemoveV();
	testRemoveVI();
	testRemoveVII();

return 0;
}
