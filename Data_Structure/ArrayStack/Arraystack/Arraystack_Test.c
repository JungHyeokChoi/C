#include <stdio.h>
#include <stdlib.h>
#include "Arraystack.h"

int main() {
	ArrayStack *pStack = NULL;
	ArrayStackNode *pNode = NULL;
	char value = 0;

	pStack = createArrayStack(6);

	if (pStack != NULL) {
		ArrayStackNode node1 = { 'A' };
		ArrayStackNode node2 = { 'B' };
		ArrayStackNode node3 = { 'C' };
		ArrayStackNode node4 = { 'D' };

		pushAs(pStack, node1);
		pushAs(pStack, node2);
		pushAs(pStack, node3);
		pushAs(pStack, node4);

		pNode = popAs(pStack);	

		if (pNode != NULL) {
			printf("Pop °ª - [%c]\n\n", pNode->data);
			free(pNode);
		}
		else {
			printf("Empty Stack\n");
		}
		displayArrayStack(pStack);
		
		pNode = peekAs(pStack);
		if (pNode != NULL) {
			printf("Peek °ª - [%c]\n", pNode->data);
		}
		else {
			printf("Empty Stack\n");
		}
		displayArrayStack(pStack);
	}

	deletArrayStack(pStack);

	return 0;
}