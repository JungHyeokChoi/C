#include <stdio.h>
#include <stdlib.h>
#include "Linkedqueue.h"

int main() {
	LinkedQueue *pQueue = NULL;
	QueueNode *pNode = NULL;

	pQueue = createLinkedQueue();
	if (pQueue != NULL) {

		QueueNode node1 = { 'A' };
		QueueNode node2 = { 'B' };
		QueueNode node3 = { 'C' };
		QueueNode node4 = { 'D' };

		enqueueLQ(pQueue, node1);
		enqueueLQ(pQueue, node2);
		enqueueLQ(pQueue, node3);
		enqueueLQ(pQueue, node4);
		displayLinkedQueue(pQueue);


		pNode = dequeueLQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value - [%c]\n", pNode->data);
			free(pNode);
		}
		displayLinkedQueue(pQueue);

		pNode = peekLQ(pQueue);
		if (pNode != NULL) {
			printf("Peek Value - [%c]\n", pNode->data);
		}

		QueueNode node5 = { 'E' };
		enqueueLQ(pQueue, node5);
		displayLinkedQueue(pQueue);

		deleteLinkedQueue(pQueue);

	}

	return 0;
}