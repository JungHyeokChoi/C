#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Polylist.h"

int main() {
	LinkedList *pListA = NULL, *pListB = NULL, *pListC = NULL;

	pListA = createLinkedList();
	pListB = createLinkedList();

	if (pListA != NULL && pListB != NULL) {
		//pListA : 6x^6 + 4x^5 + 2x^2

		addPolyNodeList(pListA, 6, 5);
		addPolyNodeList(pListA, 4, 4);
		addPolyNodeList(pListA, 2, 2);
		printf("AÇ× : ");
		displayPolyList(pListA);

		//pListB : 1x^5 + 2x^4 + 3x^2 + 4x^0
		addPolyNodeList(pListB, 1, 6);
		addPolyNodeList(pListB, 2, 4);
		addPolyNodeList(pListB, 3, 2);
		addPolyNodeList(pListB, 4, 0);
		printf("BÇ× : ");
		displayPolyList(pListB);
		printf("--------------------------------------------------------------\n");


		pListC = polyAdd(pListA, pListB);
		if (pListC != NULL) {
			printf("µ¡¼À : ");
			displayPolyList(pListC);

		}

		pListC = polySubtraction(pListA, pListB);
		if (pListC != NULL) {
			printf("»¬¼À : ");
			displayPolyList(pListC);
		}
		deleteLinkedList(pListA);
		deleteLinkedList(pListB);
		deleteLinkedList(pListC);
	}

	return 0;
}