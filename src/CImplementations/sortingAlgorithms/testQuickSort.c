
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quickSort.c"

void testQuickSort(){
	
	int* array = (int*) malloc(sizeof(int)*4);
	array[0] = 7;
	array[1] = 3;
	array[2] = 5;
	array[3] = 2;

	int *res = quickSort(array,4);
	
	assert(res[0] == 2);	
	assert(res[1] == 3);
	assert(res[2] == 5);
	assert(res[3] == 7);
}

void testQuickSortI(){
	
	int* array = (int*) malloc(sizeof(int)*5);
	array[0] = 7;
	array[1] = 3;
	array[2] = 5;
	array[3] = 2;
	array[4] = 2;
	

	int *res = quickSort(array,5);
	

	assert(res[0] == 2);
	assert(res[1] == 2);	
	assert(res[2] == 3);
	assert(res[3] == 5);
	assert(res[4] == 7);
}

void testQuickSortII(){
	
	int* array = (int*) malloc(sizeof(int)*5);
	array[0] = 4;
	array[1] = 3;
	array[2] = 2;
	array[3] = 1;
	array[4] = 0;
	

	int *res = quickSort(array,5);
	

	assert(res[0] == 0);
	assert(res[1] == 1);	
	assert(res[2] == 2);
	assert(res[3] == 3);
	assert(res[4] == 4);
}

int main(){
	testMerge();
	testQuickSort();
	testQuickSortI();
	testQuickSortII();
	
return 0;
}