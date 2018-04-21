#include <stdio.h>
#include <stdlib.h>
#include "linkednode.h"
int * LeSequenciaArrayInt(int tamanho){
	int *seq = (int *) malloc(tamanho*sizeof(int));
	for (int i = 0; i<tamanho; i++){
		scanf("%d", seq + i);
	}
	return seq;
}

void ImprimeSequenciaArrayInt(int * seq, int tamanho){
	for(int i = 0; i < tamanho; i++){
		printf("%d ", *(seq + i));
	}
	printf("\n");
	return;
}
int BinarySearchArrayInt(int *seq, int len, int key){
	int left = 0, 
	right = len-1, mid=0;
	while (left <= right){
		mid = left + (right - left)/2;			
		//printf("%d\n", mid);
		if(seq[mid]<key){
			left = mid+1;
		}else if (seq[mid] > key){
			right = mid -1;
		}else{
			return mid;
		}
	}
	return -1;
}
int BinarySearchArrayIntRecursive(int seq[], int left, int right, int key){
	
	if (left > right){
		return -1;
	}
	int mid = (left+right)/2;
	if (seq[mid] == key){
		return mid;
	}
	if (key > seq[mid]){
		return BinarySearchArrayIntRecursive(seq, mid + 1, right, key);
	}else{
		return BinarySearchArrayIntRecursive(seq, left, mid - 1, key);
	}
}
int main(void){

	int *seq = LeSequenciaArrayInt(10);
	ImprimeSequenciaArrayInt(seq, 10);
	int key = 0;
	printf("%d in pos %d\n", key, BinarySearchArrayIntRecursive(seq, 0, 9, key));
	printf("%d in pos %d\n", key, BinarySearchArrayInt(seq, 10, key));
	return 0;
}

