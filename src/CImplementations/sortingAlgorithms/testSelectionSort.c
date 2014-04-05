#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "selectionSort.c"


void testSelectionSort(){

	int array[7] = {3,7,4,4,6,5,8};

	assert(array[0] == 3);

	int* sortedArray = selectionSort(array,7);
	
	assert(array[0] == 3);	
	assert(array[1] == 4);
	assert(array[2] == 4);
	assert(array[3] == 5);
	assert(array[4] == 6);
	assert(array[5] == 7);
	assert(array[6] == 8);
}

void testSelectionSortI(){

	int array[8] = {3,7,4,4,6,5,8,2};

	assert(array[0] == 3);

	int* sortedArray = selectionSort(array,8);
	
	assert(array[0] == 2);
	assert(array[1] == 3);	
	assert(array[2] == 4);
	assert(array[3] == 4);
	assert(array[4] == 5);
	assert(array[5] == 6);
	assert(array[6] == 7);
	assert(array[7] == 8);
}


int main(){

	testSelectionSort();
	testSelectionSortI();
	

return 0;
}