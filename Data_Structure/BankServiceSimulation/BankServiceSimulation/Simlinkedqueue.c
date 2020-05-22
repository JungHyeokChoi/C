#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Simdef.h"
#include "Simlinkedqueue.h"

//���Ḯ��Ʈ ť ����
LinkedQueue *createLinkedQueue() {
	LinkedQueue *pReturn = NULL;

	pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedQueue));
	}
	else {
		printf("����, �޸� �Ҵ� createLinkedQueue()\n");
	}

	return pReturn;
}

//��ť ����
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
			printf("����, �޸� �Ҵ� enqueueLQ()\n");
		}
	}

	return ret;
}

//��ť ����
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

//��ũ ����
QueueNode *peekLQ(LinkedQueue *pQueue) {
	QueueNode *pReturn = NULL;

	if (pQueue != NULL) {
		if (isLinkedQueueEmpty(pQueue) == FALSE) {
			pReturn = pQueue->pFrontNode;
		}
	}

	return pReturn;
}

//���Ḯ��Ʈ ť ����
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

//ť(Full) ����
int isLinkedQueueFull(LinkedQueue *pQueue) {
	int ret = FALSE;

	return ret;
}

//ť(Empty) ����
int isLinkedQueueEmpty(LinkedQueue *pQueue) {
	int ret = FALSE;

	if (pQueue != NULL) {
		if (pQueue->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

//ť ������ Ȯ��
void displayLinkedQueue(LinkedQueue *pQueue) {
	QueueNode *pNode = NULL;
	int i = 0;

	if (pQueue != NULL) {
		printf("���� ��� ���� : %d\n", pQueue->currentElementCount);

		pNode = pQueue->pFrontNode;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}













