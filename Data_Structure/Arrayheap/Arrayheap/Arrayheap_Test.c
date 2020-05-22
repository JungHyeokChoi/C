#include <stdio.h>
#include <stdlib.h>
#include "Arrayheap.h"

int main() {

	int maxHeapSize = 20;

	ArrayHeap *pMaxHeap = NULL, *pMinHeap;

	HeapNode *pNode = NULL;
	HeapNode e1 = { 1 };
	HeapNode e2 = { 2 };
	HeapNode e3 = { 4 };
	HeapNode e4 = { 8 };
	HeapNode e5 = { 16 };
	HeapNode e6 = { 32 };
	HeapNode e7 = { 64 };
	HeapNode e8 = { 128 };
	HeapNode e9= { 256 };
	
	
	printf("Max Heap : \n\n");
	pMaxHeap = createArrayHeap(maxHeapSize);
	if (pMaxHeap != NULL) {
		insertMaxHeapAH(pMaxHeap, e1);
		insertMaxHeapAH(pMaxHeap, e7);
		insertMaxHeapAH(pMaxHeap, e2);
		insertMaxHeapAH(pMaxHeap, e3);
		insertMaxHeapAH(pMaxHeap, e4);
		insertMaxHeapAH(pMaxHeap, e5);
		insertMaxHeapAH(pMaxHeap, e6);
		insertMaxHeapAH(pMaxHeap, e8);
		insertMaxHeapAH(pMaxHeap, e9);

		displayArrayHeap(pMaxHeap);
		printf("Count : %d\n", pMaxHeap->currentElementCount);

		pNode = deleteMaxHeapAH(pMaxHeap);
		if (pNode != NULL) {
			printf("\ndeleteMaxHeapAH()-[%d]\n\n", pNode->key);
			free(pNode);
		}

		displayArrayHeap(pMaxHeap);

		deleteArrayHeap(pMaxHeap);
	}
	

	printf("\nMix Heap : \n\n");
	pMinHeap = createArrayHeap(maxHeapSize);
	if (pMinHeap != NULL) {
		insertMinHeapAH(pMinHeap, e1);
		insertMinHeapAH(pMinHeap, e7);
		insertMinHeapAH(pMinHeap, e2);
		insertMinHeapAH(pMinHeap, e3);
		insertMinHeapAH(pMinHeap, e4);
		insertMinHeapAH(pMinHeap, e5);
		insertMinHeapAH(pMinHeap, e6);
		insertMinHeapAH(pMinHeap, e8);
		insertMinHeapAH(pMinHeap, e9);
		
		displayArrayHeap(pMinHeap);

		pNode = deleteMinHeapAH(pMinHeap);
		if (pNode != NULL) {
			printf("\ndeleteMinHeapAH()-[%d]\n\n", pNode->key);
			free(pNode);
		}

		displayArrayHeap(pMinHeap);

		deleteArrayHeap(pMinHeap);

	}


	return 0;
}