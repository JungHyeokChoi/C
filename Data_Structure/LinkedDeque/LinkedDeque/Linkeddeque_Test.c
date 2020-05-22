#include <stdio.h>
#include <stdlib.h>
#include "Linkeddeque.h"

int main() {
	LinkedDeque* pDeque = NULL;
	DequeNode* pNode = NULL;

	pDeque = createLinkedDeque();
	if (pDeque != NULL) {
		insertFrontLDchar(pDeque,'A');
		insertFrontLDchar(pDeque, 'B');
		insertRearLDchar(pDeque, 'C');
		insertRearLDchar(pDeque, 'D');
		displayLinkedDeque(pDeque);

		pNode = deleteRearLD(pDeque);
		if (pNode != NULL) {
			printf("DeleteRearLD Value - [%c]\n", pNode->data);
			free(pNode);
		}
		displayLinkedDeque(pDeque);

		pNode = deleteFrontLD(pDeque);
		if (pNode != NULL) {
			printf("DeleteFrontLD Value - [%c]\n", pNode->data);
			free(pNode);
		}
		displayLinkedDeque(pDeque);

		deleteLinkedDeque(pDeque);
	}
	return 0;
}