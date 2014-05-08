#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int* merge(int* arrayA, int* arrayB, int lengthA, int lengthB){
	int totalLen = lengthA + lengthB -1;
	int* res = (int*) malloc(sizeof(int)*totalLen);
	for(int i = 0, j = lengthA; i < lengthA; i++){
		res[i] = arrayA[i];
	}

	for(int j = lengthA, k = 0; k < lengthB && j <= totalLen;j++, k++){
		res[j] = arrayB[k];
	}

return res;
}



int* quickSort(int* array, int length){
	int update = 1;
	int nPicks = 0;
	while(update == 1 || nPicks < length){
		update = 0;

		nPicks++;
		int pivotIndex = rand() % (length -1);
		int pivot = array[pivotIndex];

		for(int i = 0; i < length; i++){
			if(array[i] < pivot){
				if(i > pivotIndex){
					int pValue = array[pivotIndex];
					
					for(int j = i; j - 1 >= pivotIndex; j--){
						int elem = array[j];
						if(pivot == array[j -1]){
							pivotIndex = j;
						}
						array[j] = array[j -1];
						array[j -1] = elem;
					}
					update = 1;
				}
			}else{
					while(i + 1 <= pivotIndex){
						int elem = array[i];
						
						if(i+1 == pivotIndex){
							pivotIndex = i;
						}
						array[i] = array[i +1];
						array[i+1] = elem;

						i++;
						update = 1;
					}
					
				}
		}
	}
	return array;
}