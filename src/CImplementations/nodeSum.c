#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include "linkedList.c"


Node* nodeSum(Node* head1, Node* head2){
	Node* res = NULL;
	Node* resHead = NULL;

	if(head1 == NULL){

		if(head2 != NULL){
			return head2;
		}else{
			return res;
		}
	}else{
		if(head2 == NULL){
			return head1;
		}else{
			int size1 = size(head1);
			int size2 = size(head2);
			int diff = size1-size2;
			int count = 0;

			if(size1 < size2){
				//switch the pointers and the variables associated with the lists
				Node* temp = head1;
				head1= head2;

				head2 = temp;

				int sizeTemp = size1;
				size1 = size2;
				size2 = sizeTemp;

				diff = size1-size2;
			}
				
			while(head1 != NULL){
				if(count < diff){

					if(count == 0){
						res = (Node*)malloc(sizeof(Node*));
						int value = (int) ((head1->value)*(pow(10,size1-count-1)));
					
						res->value = value;
						//store a pointer to the head of the resulting list
						resHead = res;
					}else{
						res->next = (Node*)malloc(sizeof(Node*));
						int value = (int) ((head1->value)*(pow(10,size1-count-1)));
					
						res->next->value = value;
						res = res->next;
					}

					
					count++;
				}else{

					if(diff == 0){
						if(count == 0){
							res = (Node*)malloc(sizeof(Node*));
							int value = (int) ((head1->value)*pow(10,size1-count-1) + (head2->value)*pow(10,size2-count-1));
							res->value = value;
							//store a pointer to the head of the resulting list
							resHead = res;
						}else{
							res->next = (Node*)malloc(sizeof(Node*));
							int value = (int) ((head1->value)*pow(10,size1-count-1) + (head2->value)*pow(10,size2-count-1));
						
							res->next->value = value;
							res = res->next;
						}
						count++;
						head2 = head2->next;
					}else{
						if(count <= size2 && head2 != NULL){
							
							if(count == 0){
						
								res = (Node*)malloc(sizeof(Node*));
								int value = (int) ((head1->value)*(pow(10,size1-count-1)) + (head2->value)*(pow(10,size2-count)));

								res->value = value;
							}else{
								res->next = (Node*)malloc(sizeof(Node*));
								int value = (int) ((head1->value)*(pow(10,size1-count-1)) + (head2->value)*(pow(10,size2-count)));
							
								res->next->value = value;
								res = res->next;
							}

						count++;
						}
						head2 = head2->next;
					}
				}

				head1 = head1->next;
			}

			return resHead;
		}
	}

}