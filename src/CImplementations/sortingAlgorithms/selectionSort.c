#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int* selectionSort(int* array, int length){
	int swap = 0;
	int i = 0;
	int min = array[i];

	while(i < length){
		int j = i + 1;
		int minPos = 0;
		min = array[i];

		while(j < length){
			if(array[j] < array[i] && array[j] < min){
				min = array[j];
				minPos = j;
				swap = 1;
			}
			j++;
		}

		if(swap == 1){
			int temp = array[i];
			array[i] = min;
			array[minPos] = temp;
			swap = 0;
		}
		i++;
	}
	return array;
}
