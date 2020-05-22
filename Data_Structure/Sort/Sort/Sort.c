#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include "Linkedqueue.h"
#include "Arrayheap.h"

//선택 정렬
void slectionSort(int value[], int count){
	int i = 0, j = 0;
	int min = 0, temp = 0;

	for (i = 0; i < count - 1; i++) {
		min = i;
		for (j = i + 1; j < count; j++) {
			if (value[j] < value[min]) {
				min = j;
			}
		}

		temp = value[i];
		value[i] = value[min];
		value[min] = temp;

		printf("Step - %d\t", i + 1);
		printArray(value,count);
	}
}

//버블 정렬
void bubbleSort(int value[], int count){
	int i = 0, j = 0;
	int temp = 0;

	for (i = count - 1; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			if (value[j - 1] > value[j]) {
				temp = value[j - 1];
				value[j - 1] = value[j];
				value[j] = temp;
			}
		}

		printf("Step - %d\t", count - i);
		printArray(value, count);
	}
}

//퀵 정렬
void quickSort(int value[], int start, int end){
	int pivot = 0;

	if (start < end) {
		pivot = partitionQuickSort(value, start, end);
		quickSort(value, start, pivot - 1);
		quickSort(value, pivot + 1, end);
	}
}

int partitionQuickSort(int value[], int start, int end){
	int pivot = 0;
	int temp = 0, left = 0, right = 0;

	left = start;
	right = end;
	pivot = end;

	while (left < right) {
		while ((value[left] < value[pivot]) && (left < right)) {
			left++;
		}
		while ((value[right] >= value[pivot]) && (left < right)) {
			right--;
		}

		if (left < right) {
			temp = value[left];
			value[left] = value[right];
			value[right] = temp;

			printf("start-[%d], end-[%d], pivot-[%d], in-loop \t", start, end, value[pivot]);

			printArray(value, end - start + 1);
		}
	}

	temp = value[pivot];
	value[pivot] = value[right];
	value[right] = temp;

	printf("start-[%d], end-[%d], pivot-[%d], out-loop \t", start, end, value[right]);

	printArray(value, end - start + 1);

	return right;
}

//삽입 정렬
void insertionSort(int value[], int count){
	int i = 0, j = 0;
	int temp = 0;

	for (i = 1; i < count; i++) {
		temp = value[i];
		j = i;
		while ((j > 0) && (value[j - 1] > temp)) {
			value[j] = value[j - 1];
			j = j - 1;
		}

		value[j] = temp;

		printf("Step-[%d],",i);
		printArray(value, count);
	}
}

//셸 정렬
void shellSort(int value[], int count){
	int i = 0, interval = 0;

	interval = count / 2;
	while (interval >= 1) {
		for (i = 0; i < interval; i++) {
			shellInsertionSort(value, i, count - 1, interval);
		}

		printf("Interval-[%d]\t",interval);
		printArray(value, count);

		interval = interval / 2;
	}
}

//셸 정렬
void shellInsertionSort(int value[], int start, int end, int interval){
	int i = 0;
	int item = 0, index = 0;

	for (i = start + interval; i <= end; i = i + interval) {
		item = value[i];
		index = i - interval;
		while ((index >= start) && (item < value[index])) {
			value[index + interval] = value[index];
			index = index - interval;
		}

		value[index + interval] = item;
	}
}

//병렬 정렬
void mergeSort(int value[], int buffer[], int start, int end){
	int middle = 0;

	if (start < end) {
		middle = (start + end) / 2;
		mergeSort(value, buffer, start, middle);
		mergeSort(value, buffer, middle + 1, end);

		mergeSortInternal(value, buffer, start, middle, end);
	}
}

//병렬 정렬
void mergeSortInternal(int value[], int buffer[], int start, int middle, int end){
	int i = 0, j = 0, k = 0, t = 0;

	i = start;
	j = middle + 1;
	k = start;

	while (i <= middle && j <= end) {
		if (value[i] <= value[j]) {
			buffer[k] = value[i];
			i++;
		}
		else {
			buffer[k] = value[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (t = j; t <= end; t++, k++) {
			buffer[k] = value[t];
		}
	}
	else {
		for (t = i; t <= middle; t++, k++) {
			buffer[k] = value[t];
		}
	}

	for (t = start; t <= end; t++) {
		value[t] = buffer[t];
	}

	printf("start-[%d], middle-[%d], end-[%d],\t",start, middle, end);
	for (t = start; t <= end; t++) {
		printf("%d\t", value[t]);
	}
	printf("\n");
}

//기수 정렬
void radixSort(int value[], int count, int radix, int digit){
	int i = 0, bucket = 0, d = 0, factor = 1;
	LinkedQueue **ppQueue = NULL;
	QueueNode node = { 0, };
	
	ppQueue = (LinkedQueue**)malloc(sizeof(LinkedQueue*) * radix);
	if (ppQueue == NULL) {
		printf("오류, 메모리 할당(1) in radixSort()\n");
		return;
	}

	for (bucket = 0; bucket < radix; bucket++) {
		ppQueue[bucket] = createLinkedQueue();
		if (ppQueue[bucket] == NULL) {
			for (i = 0; i < bucket - 1; i++) {
				if (ppQueue[i] != NULL) {
					deleteLinkedQueue(ppQueue[i]);
				}
			}
			free(ppQueue);
			printf("오류, creteLinkedQueue(), in radixSort()\n");
			return;
		}
	}

	for (d = 0; d < digit; d++) {
		for (i = 0; i < count; i++) {
			node.data = value[i];
			enqueueLQ(ppQueue[(value[i] / factor) % radix], node);
		}

		i = 0;
		for (bucket = 0; bucket < radix; bucket++) {
			while (isLinkedQueueEmpty(ppQueue[bucket]) == FALSE) {
				QueueNode *pNode = dequeueLQ(ppQueue[bucket]);
				if (pNode != NULL) {
					value[i] = pNode->data;
					i++;
					free(pNode);
				}
			}
		}
		printf("Digit-%d,\t", factor);
		printArray(value, count);
		factor = factor * radix;
	}

	for (bucket = 0; bucket < radix; bucket++) {
		deleteLinkedQueue(ppQueue[bucket]);
	}

	free(ppQueue);
}

//히프 정렬
void heapSort(int value[], int count){
	int i = 0;
	ArrayHeap *pHeap = NULL;

	pHeap = createArrayHeap(count);
	if (pHeap != NULL) {
		HeapNode node = { 0, };
		for (i = 0; i < count; i++) {
			node.key = value[i];
			insertMinHeapAH(pHeap, node);
		}

		for (i = 0; i < count; i++) {
			HeapNode *pNode = deleteMinHeapAH(pHeap);
			if (pNode != NULL) {
				value[i] = pNode->key;
				free(pNode);
			}
		}

		deleteArrayHeap(pHeap);
	}
	else {
		printf("Error, createArrayHeap(), in heapSort()\n");
		return;
	}
}

//1차원 행렬 출력
void printArray(int value[], int count){
	for (int i = 0; i < count; i++) {
		printf("%d\t", value[i]);
	}
	printf("\n");
}
