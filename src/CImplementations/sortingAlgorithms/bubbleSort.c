#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int* bubbleSort(int* array, int length){

int swap = 1;

	while(swap == 1){
		swap = 0;
		for(int index = 0; (index + 1) < length; index++){
			if(array[index] > array[index + 1]){
				int temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				swap = 1;
			}
		}
	}
	return array;
}

