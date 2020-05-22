#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include "Linkedqueue.h"
#include "Arrayheap.h"

int main(int argc, char *args[]) {
	int values[] = { 80,50,70,10,60,20,40,30 };

	/*
	printf("Before Sort\n");
	printArray(values, 8);
	printf("\n");

	slectionSort(values, 8);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	*/

	/*
	printf("Before Sort\n");
	printArray(values, 8);
	printf("\n");

	bubbleSort(values, 8);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	*/

	/*
	printf("Before Sort\n");
	printArray(values, 8);
	printf("\n");

	quickSort(values, 0, 7);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	*/
	
	/*
	printf("Before Sort\n");
	printArray(values, 8);
	printf("\n");

	insertionSort(values, 8);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	*/

	/*
	printf("Before Sort\n");
	printArray(values, 8);
	printf("\n");

	shellSort(values, 8);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	*/

	/*
	int* pBuffer = NULL;
	
	pBuffer = (int*)malloc(sizeof(int) * 8);
	if (pBuffer != NULL) {
		printf("Before Sort\n");
		printArray(values, 8);
		printf("\n");

		mergeSort(values, pBuffer, 0, 7);

		free(pBuffer);
	}

	printf("\nAfter Sort\n");
	printArray(values, 8);
	*/

	/*
	int values[] = { 42,60,75,81,10,23,12,18 };

	printf("Before Sort\n");
	printArray(values, 8);
	printf("\n");

	radixSort(values, 8, 10, 2);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	*/

	
	printf("Before Sort\n");
	printArray(values, 8);

	heapSort(values, 8);

	printf("\nAfter Sort\n");
	printArray(values, 8);
	

	return 0;
}