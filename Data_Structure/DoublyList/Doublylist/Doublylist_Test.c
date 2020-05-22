#include <stdio.h>
#include <stdlib.h>
#include "Doublylist.h"

int main() {
	int i = 0;
	DoublyList* pList = NULL;
	DoublyListNode* pNode = NULL;
	DoublyListNode node;

	pList = createDoublyList();

	if (pList != NULL) {
		node.data = 1;
		addDLElement(pList, 0, node);

		node.data = 3;
		addDLElement(pList, 1, node);

		node.data = 5;
		addDLElement(pList, 2, node);
		
		displayDoublyList(pList);
		
		removeDLElement(pList, 0);
		displayDoublyList(pList);
		
		deleteDoublyList(pList);
		
	}

	return 0;
}