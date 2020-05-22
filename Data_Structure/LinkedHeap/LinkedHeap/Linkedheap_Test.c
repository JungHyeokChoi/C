#include <stdio.h>
#include <stdlib.h>
#include "Linkedheap.h"

LinkedHeap* createExampleMaxHeap();
LinkedHeap* createExampleMinHeap();

int main(int argc, char *argv[]) {
	LinkedHeap* pHeap = NULL;

	printf("Max Heap : \n\n");
	pHeap = createExampleMaxHeap();

	if (pHeap != NULL) {
		printf("Before deleteMaxHeapLH()\n\n");
		displayLinkedHeap(pHeap);
		printf("Current Element Count : %d\n", pHeap->currentElementCount);

		printf("\nAfter deleteMaxHeapLH()\n\n");
		deleteMaxHeapLH(pHeap);
		displayLinkedHeap(pHeap);
		printf("Current Element Count : %d\n", pHeap->currentElementCount);

		deleteLinkedHeap(pHeap);
	}
	
	printf("\nMin Heap : \n\n");
	pHeap = createExampleMinHeap();

	if (pHeap != NULL) {
		displayLinkedHeap(pHeap);
		printf("Current Element Count : %d\n", pHeap->currentElementCount);

		printf("\nAfter deleteMinHeapLH()\n\n");
		deleteMinHeapLH(pHeap);
		displayLinkedHeap(pHeap);
		printf("Current Element Count : %d\n", pHeap->currentElementCount);

		deleteLinkedHeap(pHeap);
	}
	return 0;
}

LinkedHeap* createExampleMaxHeap() {
	LinkedHeap *pReturn = NULL;
	LinkedHeapNode node = { 0, };


	pReturn = createLinkedHeap();
	if (pReturn != NULL) {
		
		node.key = 80;
		insertMaxHeapLH(pReturn, node);
		node.key = 100;
		insertMaxHeapLH(pReturn, node);
		node.key = 70;
		insertMaxHeapLH(pReturn, node);
		node.key = 20;
		insertMaxHeapLH(pReturn, node);
		node.key = 60;
		insertMaxHeapLH(pReturn, node);
		node.key = 110;
		insertMaxHeapLH(pReturn, node);
		node.key = 10;
		insertMaxHeapLH(pReturn, node);
		node.key = 120;
		insertMaxHeapLH(pReturn, node);
		node.key = 150;
		insertMaxHeapLH(pReturn, node);
		node.key = 130;
		insertMaxHeapLH(pReturn, node);
		node.key = 180;
		insertMaxHeapLH(pReturn, node);
		node.key = 200;
		insertMaxHeapLH(pReturn, node);
		node.key = 300;
		insertMaxHeapLH(pReturn, node);
		node.key = 5;
		insertMaxHeapLH(pReturn, node);
		node.key = 1000;
		insertMaxHeapLH(pReturn, node);
	}

	return pReturn;
}

LinkedHeap* createExampleMinHeap() {
	LinkedHeap *pReturn = NULL;
	LinkedHeapNode node = { 0, };


	pReturn = createLinkedHeap();
	if (pReturn != NULL) {

		node.key = 80;
		insertMinHeapLH(pReturn, node);
		node.key = 100;
		insertMinHeapLH(pReturn, node);
		node.key = 70;
		insertMinHeapLH(pReturn, node);
		node.key = 20;
		insertMinHeapLH(pReturn, node);
		node.key = 60;
		insertMinHeapLH(pReturn, node);
		node.key = 110;
		insertMinHeapLH(pReturn, node);
		node.key = 10;
		insertMinHeapLH(pReturn, node);
		node.key = 120;
		insertMinHeapLH(pReturn, node);
		node.key = 150;
		insertMinHeapLH(pReturn, node);
		node.key = 130;
		insertMinHeapLH(pReturn, node);
		node.key = 1000;
		insertMinHeapLH(pReturn, node);
		node.key = 5;
		insertMinHeapLH(pReturn, node);
		node.key = 1;
		insertMinHeapLH(pReturn, node);
		node.key = 400;
		insertMinHeapLH(pReturn, node);
		node.key = 800;
		insertMinHeapLH(pReturn, node);
		node.key = 700;
		insertMinHeapLH(pReturn, node);

		
	}

	return pReturn;
}
