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

int* sortFunction(int* array, int begin, int length){
	int sortedArea = 0;
	for(int i = begin, j = 1; i < length && j <length; i++,j++){
		if(array[i] > array[j]){
			//if we found the minimun, we want to insert it at the begining
			if(array[j] < array[0]){
				array = insertInPosition(array,0,j,array[j]);
			}else{
				//otherwise, we want to insert from the sortedArea onwards
				array = insertInPosition(array,sortedArea,j,array[j]);
			}
		}else{
			sortedArea = i;
		}
	}

	return array;
}


/* In-place merge function */
int* merge(int* arrayA, int* arrayB, int lengthA, int lengthB){
	int totalLen = lengthA + lengthB;
	int* res = (int*) malloc(sizeof(int)*totalLen);

	for(int i = 0; i < lengthA; i++){
		res[i] = arrayA[i];
	}

	for(int j = lengthA; j < totalLen;j++){
		res[j] = arrayB[j];
	}

return res;
}



int* recursiveFunction(int* array, int begining, int half, int end){
	if(abs(half-begining) == 1){
		return sortFunction(array,begining,end);
	}else{
		end = ceil(half/2.0)+1;
		half = ceil(half/2.0);
		return recursiveFunction(array,begining,half,end);
	}
}



int* mergeSort(int* array, int length){

	int half = ceil(length/2.0);
	int quarterL = ceil(half/2.0);
	int quarterR = half;

	return sortFunction(merge(recursiveFunction(array,0,quarterL,half-1),
								recursiveFunction(array,half,quarterR,length),half,(length-half)),
						0,length);

}