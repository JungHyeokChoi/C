#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedStack.h"

int main() {
	DoublyLinkedStack* pStack = NULL;
	DoublyLinkedStackNode* pNode = NULL;

	pStack = createDLStack();

	if (pStack != NULL) {
		DoublyLinkedStackNode node1 = { 'A' };
		DoublyLinkedStackNode node2 = { 'B' };
		DoublyLinkedStackNode node3 = { 'C' };
		DoublyLinkedStackNode node4 = { 'D' };

		pushDLS(pStack, node1);
		pushDLS(pStack, node2);
		pushDLS(pStack, node3);
		pushDLS(pStack, node4);
		displayDLStack(pStack);

		
		pNode = popDLS(pStack);
		if (pNode != NULL) {
			printf("Pop - [%c]\n\n", pNode->data);
			free(pNode);
		}
		else {
			printf("Pop - NULL\n\n");
		}
		printf("After Pop\n");
		displayDLStack(pStack);

		pNode = peekDLS(pStack);
		if (pNode != NULL) {
			printf("Peek - [%c]\n\n", pNode->data);
		}
		else {
			printf("Peek - NULL\n\n");
		}
		printf("After Peek\n");
		displayDLStack(pStack);
		
	}

	deleteDLStack(pStack);
}