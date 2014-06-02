#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "isPalindrome.c"

void testNull(){

	Node* head = newLinkedlist();

	assert(isPalindrome(head) == 0);

}

void testPalindrome(){

	Node* head = newLinkedlist();

	push(&head,1);

	assert(isPalindrome(head) == 0);
}

void testPalindromeI(){

	Node* head = newLinkedlist();

	push(&head,1);
	push(&head,2);
	push(&head,1);

	assert(isPalindrome(head) == 1);
}

void testPalindromeII(){

	Node* head = newLinkedlist();

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,1);
	push(&head,4);
	push(&head,1);
	push(&head,3);
	push(&head,2);
	push(&head,1);

	assert(isPalindrome(head) == 1);
}



int main(){

	testNull();
	testPalindrome();
	testPalindromeI();
	testPalindromeII();

	return 0;
}