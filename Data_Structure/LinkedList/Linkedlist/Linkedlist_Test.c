#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Linkedlisttop.h"


int main(int argc, char *argv[]) {
	int i = 0;
	int arrayCount = 0;
	LinkedList *pListA = NULL, *pListB = NULL;
	ListNode* pNode = NULL;
	ListNode node;

	pListA = createLinkedList();
	pListB = createLinkedList();
	
	if (pListA != NULL && pListB != NULL) {
		
		node.data = 1;
		addLLElement(pListA, 0, node);
		
		node.data = 3;
		addLLElement(pListA, 1, node);
		
		node.data = 5;
		addLLElement(pListA, 2, node);

		node.data = 7;
		addLLElement(pListA, 3, node);

		node.data = 10;
		addLLElement(pListB, 0, node);
		
		printf("Before concatLinkedList() \n");
		iterateLinkedList(pListA);

		reverseLinkedList(pListA);
		iterateLinkedList(pListA);
		iterateLinkedList(pListB);
		reverseLinkedList(pListA);

		concatLinkedList(pListA, pListB);

		printf("\nAfter concatLinkedList() \n");
		iterateLinkedList(pListA);
		iterateLinkedList(pListB);
		printf("\n");


		reverseLinkedList(pListA);
		iterateLinkedList(pListA);

		deleteLinkedList(pListA);
		deleteLinkedList(pListB);
	}

	return 0;
}


