#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mergeSort.c"


void testMerge(){

int* arrayA = (int*) malloc(sizeof(int)*2);
arrayA[0] = 3;
arrayA[1] = 7;
arrayA[2] = 4;
arrayA[3] = 4;

int* arrayB = (int*) malloc(sizeof(int)*2);
arrayB[0] = 3;
arrayB[1] = 7;
arrayB[2] = 4;
arrayB[3] = 4;

int* res = merge(arrayA,arrayB,2,2);

assert(res[0] == 3);	
assert(res[1] == 7);
assert(res[2] == 4);
assert(res[3] == 4);

}

void testSort(){

int* array = (int*) malloc(sizeof(int)*2);
array[0] = 3;
array[1] = 7;
array[2] = 4;
array[3] = 4;

int* res = sortFunction(array,0,4);

assert(res[0] == 3);	
assert(res[1] == 4);
assert(res[2] == 4);
assert(res[3] == 7);

}


void testMergeSort(){

	int len = 5;
	int* array = (int*) malloc(sizeof(int)*len);
	array[0] = 7;
	array[1] = 3;
	array[2] = 4;
	array[3] = 4;
	array[4] = 8;


	int *res = mergeSort(array,len);
	

	assert(res[0] == 3);	
	assert(res[1] == 4);
	assert(res[2] == 4);
	assert(res[3] == 7);
	assert(res[4] == 8);
}



void testMergeSortI(){

	int len = 6;
	int* array = (int*) malloc(sizeof(int)*len);
	array[0] = 3;
	array[1] = 7;
	array[2] = 1;
	array[3] = 4;
	array[4] = 8;
	array[5] = 0;


	int *res = mergeSort(array,len);
	

	assert(res[0] == 0);	
	assert(res[1] == 1);
	assert(res[2] == 3);
	assert(res[3] == 4);
	assert(res[4] == 7);
	assert(res[5] == 8);
}


void testMergeSortII(){

	int len = 6;
	int* array = (int*) malloc(sizeof(int)*len);
	array[0] = 9;
	array[1] = 8;
	array[2] = 7;
	array[3] = 6;
	array[4] = 5;
	array[5] = 4;


	int *res = mergeSort(array,len);
	

	assert(res[0] == 4);	
	assert(res[1] == 5);
	assert(res[2] == 6);
	assert(res[3] == 7);
	assert(res[4] == 8);
	assert(res[5] == 9);
}


void testMergeSortIII(){

	int len = 5;
	int* array = (int*) malloc(sizeof(int)*len);
	array[0] = 1;
	array[1] = 1;
	array[2] = 1;
	array[3] = 1;
	array[4] = 1;


	int *res = mergeSort(array,len);
	

	assert(res[0] == 1);	
	assert(res[1] == 1);
	assert(res[2] == 1);
	assert(res[3] == 1);
	assert(res[4] == 1);
}


void testMergeSortIV(){

	int len = 5;
	int* array = (int*) malloc(sizeof(int)*len);
	array[0] = 1;
	array[1] = 1;
	array[2] = 1;
	array[3] = 1;
	array[4] = 0;


	int *res = mergeSort(array,len);
	

	assert(res[0] == 0);	
	assert(res[1] == 1);
	assert(res[2] == 1);
	assert(res[3] == 1);
	assert(res[4] == 1);
}

int main(){

	testMerge();
	testSort();
	testMergeSort();
	testMergeSortI();
	testMergeSortII();
	testMergeSortIII();
	testMergeSortIV();
	
return 0;
}