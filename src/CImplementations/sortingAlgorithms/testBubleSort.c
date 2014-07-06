#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bubbleSort.c"


void testBubbleSort(){

	int array[7] = {3,7,4,4,6,5,8};

	assert(array[0] == 3);

	int* sortedArray = bubbleSort(array,7);
	
	assert(array[0] == 3);	
	assert(array[1] == 4);
	assert(array[2] == 4);
	assert(array[3] == 5);
	assert(array[4] == 6);
	assert(array[5] == 7);
	assert(array[6] == 8);
}


int main(){

	testBubbleSort();
	
return 0;
}
