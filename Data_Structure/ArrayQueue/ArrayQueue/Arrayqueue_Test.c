#include <stdio.h>
#include <stdlib.h>
#include "Arrayqueue.h"

int main() {
	ArrayQueue *pQueue = NULL;
	ArrayQueueNode *pNode = NULL;
	char value = 0;

	pQueue = createArrayQueue(4);
	if (pQueue != NULL) {
		enqueueAQChar(pQueue, 'A');
		enqueueAQChar(pQueue, 'B');
		enqueueAQChar(pQueue, 'C');
		enqueueAQChar(pQueue, 'D');
		displayArrayQueue(pQueue);

		
		pNode = dequeueAQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value - [%c]\n", pNode->element);
			free(pNode);
		}
		displayArrayQueue(pQueue);
		
		pNode = peekAQ(pQueue);
		if (pNode != NULL) {
			printf("Peek Value - [%c]\n", pNode->element);
		}
		
		enqueueAQChar(pQueue, 'E');
		displayArrayQueue(pQueue);
		
		deleteArrayQueue(pQueue);
		
	}

	return 0;
}