#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include "doublyLinkedList.h"

Node* newDoublyLinkedList(){
	Node* head = NULL;
return head;
}

/*Returns the total number of elements in the list*/
int size(Node* head){
	if(head != NULL){
		return head->size;
	}else{
		return 0;
	}
}

/* Inserts the element at the end of the list*/
void append(Node** head,int value){
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;	

	if(*head == NULL){
		*head = node;
		(*head)->size = 1;
		(*head)->previous = NULL;
		(*head)->next = NULL;
		(*head)->tail = node;
	}else{
		node->size = (*head)->size + 1;

		if((*head)->tail != NULL){
			node->previous = (*head)->tail;
		}else{
			node->previous = (*head);
		}
		
		node->next = NULL;
		node->tail = node;
		(*head)->tail->next = node;
		(*head)->tail = node;
		node->previous->tail = node;
		(*head)->size = (*head)->size + 1;
	}
}

/* Inserts the element at the beginning of the list*/
void prepend(Node** head,int value){
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;	

	if(*head == NULL){
		*head = node;
		(*head)->size = 1;
		(*head)->previous = NULL;
		(*head)->next = NULL;
		(*head)->tail = *head;
	}else{
		node->next = *head;
		node->previous = NULL;
		node->tail = *head;
		node->size = (*head)->size + 1;

		(*head)->previous = node;
		*head = node;
	}
}

/* Removes the first element on the list*/
Node* removeFirst(Node** head){
	Node* temp = *head;

	if(*head != NULL){
		*head = temp->next;

		if(*head != NULL){
			(*head)->size = temp->size -1;
		}
	}else{
		*head = NULL;
	}
return temp;
}


/* Removes the last element on the list*/
Node* removeLast(Node** head){
	Node* temp = NULL;
	if(*head != NULL){
		temp = (*head)->tail;

		if(temp != NULL){
			if(temp->previous != NULL){
				temp->previous->tail = temp->previous;
				(*head)->tail = temp->previous;

				temp->previous->next = NULL;
				temp->previous = NULL;

				if(*head != NULL){
					(*head)->size = (*head)->size -1;
				}
			}else{
				*head = NULL;
			}
		}
		free(temp);
	}
return temp;
}

/* Update the change of the tail of the list to all the elements in the list*/
void propagateTailChange(Node** head, int listSize){
	int count = 1;
	Node* temp = *head;
	Node* newTail = (*head)->tail;
	while(count <= listSize){
		temp->tail = newTail;
		temp = temp->next;
		count++;
	}
}

/* Remove the node in the given position. Positions start at 1*/
Node* removeAtPos(Node** head, int position){
	Node* temp = NULL;
	if(*head != NULL){
		int listSize = size(*head);	

		if(position <= listSize){
			int halfSize = ceil(listSize/2.0);
			int hops = 1;

			if(position <= halfSize){
				temp = *head;
				while(hops < position){
					temp = temp->next;
					hops++;
				}

				Node* res = (Node*)malloc(sizeof(Node));
				res->value = temp->value;
				res->size = temp->size -1;
				res->next = NULL;
				res->previous = NULL;
				res->tail = res;

				if(temp->previous != NULL){
					
					temp->previous->next = temp->next;
					//temp->next = NULL;
					temp->next->previous = temp->previous;

					(*head)->size = (*head)->size -1;

					temp->previous = NULL;
					temp->next = NULL;
					free(temp);

					propagateTailChange(head,(*head)->size);
				}else{
					
					if(listSize > 1){
						*head = temp->next;
						(*head)->size = temp->size -1;
						(*head)->previous = NULL;
						temp->next = NULL;
						free(temp);
						propagateTailChange(head,(*head)->size);

					}else{
						//listSize == 1
						*head = NULL;
					}
				}
				return res;
			}else{

				hops = listSize;
				temp = (*head)->tail;
				while(hops > position){
					temp = temp->previous;
					hops--;
				}

				Node* res = (Node*)malloc(sizeof(Node));
				res->value = temp->value;
				res->size = temp->size -1;
				res->next = NULL;
				res->previous = NULL;

				if(temp->previous != NULL){
					
					temp->previous->next = NULL;
					temp->next = NULL;
					
					(*head)->tail = temp->previous;
					(*head)->size = (*head)->size -1;

					temp->previous = NULL;

					propagateTailChange(head,(*head)->size);
					return res;
				}				
			}
		}

	}
return temp;
}
