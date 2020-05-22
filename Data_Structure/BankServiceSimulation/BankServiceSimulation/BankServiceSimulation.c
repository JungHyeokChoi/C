#include <stdio.h>
#include <stdlib.h>
#include "Simdef.h"
#include "Simutil.h"
#include "Simlinkedqueue.h"

int main() {
	int currentTime = 0;
	int endTime = 15;
	int serviceUserCount = 0;
	int totalWaitTime = 0;

	LinkedQueue *pArrivalQueue = NULL, *pWaitQueue = NULL;
	QueueNode *pServiceNode1 = NULL, *pServiceNode2 = NULL;

	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();
	if (pArrivalQueue != NULL && pWaitQueue == NULL) {
		printf("¿À·ù, createLinkedQueue()\n");
		return FALSE;
	}

	insertCutomer(0, 3, pArrivalQueue);
	insertCutomer(0, 2, pArrivalQueue);
	insertCutomer(1, 4, pArrivalQueue);
	insertCutomer(2, 2, pArrivalQueue);
	insertCutomer(4, 1, pArrivalQueue);
	insertCutomer(5, 3, pArrivalQueue);
	insertCutomer(6, 1, pArrivalQueue);
	insertCutomer(8, 3, pArrivalQueue);
	insertCutomer(9, 7, pArrivalQueue);
	insertCutomer(10, 5, pArrivalQueue);


	for (currentTime = 0; currentTime < endTime; currentTime++) {
		processArrival(currentTime, pArrivalQueue, pWaitQueue);

		if (pServiceNode1 != NULL) {
			pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
		}

		if (pServiceNode2 != NULL) {
			pServiceNode2 = processServiceNodeEnd(currentTime, pServiceNode2, &serviceUserCount, &totalWaitTime);
		}

		if(pServiceNode1 == NULL){
			pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
		}

		if (pServiceNode2 == NULL) {
			pServiceNode2 = processServiceNodeStart(currentTime, pWaitQueue);
		}

		printWaitQueueStatus(currentTime, pWaitQueue);
		printf("\n");
	}

	printReport(pWaitQueue, serviceUserCount, totalWaitTime);

	if (pServiceNode1 != NULL) {
		free(pServiceNode1);
	}

	deletLinkedQueue(pArrivalQueue);
	deletLinkedQueue(pWaitQueue);

	return 0;
}