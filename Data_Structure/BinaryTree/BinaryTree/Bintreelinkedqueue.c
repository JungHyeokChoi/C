#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bintree.h"
#include "Bintreelinkedqueue.h"

//연결리스트 큐 생성
LinkedQueue *createLinkedQueue() {
	LinkedQueue *pReturn = NULL;

	pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedQueue));
	}
	else {
		printf("오류, 메모리 할당 createLinkedQueue()\n");
	}

	return pReturn;
}

//인큐 연산
int enqueueLQ(LinkedQueue *pQueue, QueueNode element) {
	int ret = FALSE;
	QueueNode *pNode = NULL;

	if (pQueue != NULL) {
		pNode = (QueueNode*)malloc(sizeof(QueueNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLink = NULL;

			if (isLinkedQueueEmpty(pQueue) == TRUE) {
				pQueue->pFrontNode = pNode;
				pQueue->pRearNode = pNode;
			}
			else {
				pQueue->pRearNode->pLink = pNode;
				pQueue->pRearNode = pNode;
			}

			pQueue->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 메모리 할당 enqueueLQ()\n");
		}
	}

	return ret;
}

//디큐 연산
QueueNode *dequeueLQ(LinkedQueue *pQueue) {
	QueueNode *pReturn = NULL;

	if (pQueue != NULL) {
		if (isLinkedQueueEmpty(pQueue) == FALSE) {
			pReturn = pQueue->pFrontNode;
			pQueue->pFrontNode = pQueue->pFrontNode->pLink;
			pReturn->pLink = NULL;

			pQueue->currentElementCount--;
			if (isLinkedQueueEmpty(pQueue) == TRUE) {
				pQueue->pRearNode = NULL;
			}
		}
	}

	return pReturn;
}

//피크 연산
QueueNode *peekLQ(LinkedQueue *pQueue) {
	QueueNode *pReturn = NULL;

	if (pQueue != NULL) {
		if (isLinkedQueueEmpty(pQueue) == FALSE) {
			pReturn = pQueue->pFrontNode;
		}
	}

	return pReturn;
}

//연결리스트 큐 삭제
void deletLinkedQueue(LinkedQueue *pQueue) {
	QueueNode *pNode = NULL;
	QueueNode *pDelNode = NULL;

	if (pQueue != NULL) {
		pNode = pQueue->pFrontNode;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;

			free(pDelNode);
		}

		free(pQueue);
	}
}

//큐(Full) 연산
int isLinkedQueueFull(LinkedQueue *pQueue) {
	int ret = FALSE;

	return ret;
}

//큐(Empty) 연산
int isLinkedQueueEmpty(LinkedQueue *pQueue) {
	int ret = FALSE;

	if (pQueue != NULL) {
		if (pQueue->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}










