#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "linkedList.c"

int* listToArray(Node* head, int size){
	int sizeList = size;

	int* array = (int*) malloc(sizeof(int)*sizeList);
	int i = 0;

	while(head != NULL){

		array[i] = head->value;
		i++;
		head = head->next;
	}
return array;
}

int isPalindrome(Node* head){
	int palindrome = 0;
	if(head != NULL){
		int sizeList = size(head);
		int* array = listToArray(head,sizeList);

		int i = 0;
		int j = sizeList-1;

		while(i < sizeList -1){

			if(array[i] == array[j]){
				palindrome = 1;
			}else{
				palindrome = 0;
				return palindrome;
			}
			i++;
			j--;
		}
	}

	return palindrome;
}