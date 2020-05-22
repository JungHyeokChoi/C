#include <stdio.h>
#include <stdlib.h>
#include "Linkedstack.h"

int main() {
	LinkedStack* pStack = NULL;
	StackNode* pNode = NULL;

	pStack = createLinkedStack();

	if (pStack != NULL) {
		StackNode node1 = { 'A' };
		StackNode node2 = { 'B' };
		StackNode node3 = { 'C' };
		StackNode node4 = { 'D' };

		pushLS(pStack, node1);
		pushLS(pStack, node2);
		pushLS(pStack, node3);
		pushLS(pStack, node4);
		displayLinkedStack(pStack);

		pNode = popLS(pStack);
		if (pNode != NULL) {
			printf("Pop - [%c]\n\n", pNode->data);
			free(pNode);
		}
		else {
			printf("Pop - NULL\n\n");
		}
		printf("After Pop\n");
		displayLinkedStack(pStack);

		pNode = peekLS(pStack);
		if (pNode != NULL) {
			printf("Peek - [%c]\n\n", pNode->data);
		}
		else {
			printf("Peek - NULL\n\n");
		}
		printf("After Peek\n");
		displayLinkedStack(pStack);
	}

	deleteLinkedStack(pStack);
}