#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int* insertInPosition(int* array, int beginIndex, int endIndex, int element){
	int position = 0;

	for(int i = beginIndex; i < endIndex; i++){
		if(array[i] > element){
			position = i;
			break;
		}
	}

	for(int i= endIndex; i - 1 >= position; i--){
		int temp = array[i];
		array[i] = array[i - 1];
		array[i - 1] = temp;
	}

	array[position] = element;
	return array;
}


int* insertionSort(int* array, int length){

int sortedArea = 0;

	for(int i = 0, j =1; i < j && j < length; i++, j++){
		if(array[i] > array[j]){
			array = insertInPosition(array,sortedArea,j,array[j]);
		}else{
			sortedArea = i;
		}
	}
	return array;
}


int* insertionSortAlternative(int* array, int length){
	for(int i = 1; i < length; i++){

		int temp = array[i];
		int j = i - 1;

		while(temp < array[j] && j >=0){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
	return array;
}