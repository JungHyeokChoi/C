#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrayqueue.h"

//�迭 ť ����
ArrayQueue *createArrayQueue(int maxElementCount){
	ArrayQueue *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(ArrayQueue));
			pReturn->maxElementCount = maxElementCount;
			pReturn->front = -1;
			pReturn->rear = -1;
		}
		else {
			printf("����, �޸��Ҵ�,createArrayQueue()\n");
			return NULL;
		}
	}
	else {
		printf("����, ť ũ��� 0���� Ŀ�� �մϴ�\n");
		return NULL;
	}

	pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode)*maxElementCount);
	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(ArrayQueueNode)*maxElementCount);
	}
	else {
		printf("����, �޸��Ҵ�2,createArrayQueue()\n");
		free(pReturn);
		return NULL;
	}

	return pReturn;
}

//��ť ����
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element){
	int ret = FALSE;
	int i = 0;

	if (pQueue != NULL) {
		if (isArrayQueueFull(pQueue) == FALSE) {
			pQueue->rear = (pQueue->rear +1) % pQueue->maxElementCount;
			pQueue->pElement[pQueue->rear] = element;

			pQueue->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("����, ť�� ���� á���ϴ�, enqueueAQ()\n");
		}
	}

	return ret;
}

//��ť ����
ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue){
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == FALSE) {
			pReturn = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode));
			if (pReturn != NULL) {
				pQueue->front = (pQueue->front +1) % pQueue->maxElementCount;
				pReturn->element = pQueue->pElement[pQueue->front].element;

				pQueue->currentElementCount--;
			}
			else {
				printf("����, �޸��Ҵ�,dequeueAQ()\n");
			}
		}
	}

	return pReturn;
}

//��ũ ����
ArrayQueueNode *peekAQ(ArrayQueue *pQueue){
	ArrayQueueNode *pReturn = NULL;
	
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == FALSE) {
			pReturn = &(pQueue->pElement[pQueue->front + 1]);
		}
	}

	return pReturn;
}

//ť ����
void deleteArrayQueue(ArrayQueue *pQueue){
	if (pQueue != NULL) {
		if (pQueue->pElement != NULL) {
			free(pQueue->pElement);
		}
		free(pQueue);
	}
}

//ť(Full) ����
int isArrayQueueFull(ArrayQueue *pQueue){
	int ret = FALSE;
	
	if (pQueue != NULL) {
		if (pQueue->currentElementCount == pQueue->maxElementCount) {
			ret = TRUE;
		}
	}
	return ret;
}

//ť(Empty) ����
int isArrayQueueEmpty(ArrayQueue *pQueue){
	int ret = FALSE;

	if (pQueue != NULL) {
		if (pQueue->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

//ť ������ Ȯ��
void displayArrayQueue(ArrayQueue *pQueue){
	int i = 0, maxElementIndex = 0, pos = 0;

	if (pQueue != NULL) {
		printf("ť�� ũ�� : %d, ���� ��� ���� : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);

		maxElementIndex = pQueue->front + pQueue->currentElementCount;
		for (i = pQueue->front+1; i <= maxElementIndex; i++) {
			pos = i % pQueue->maxElementCount;
			printf("[%d] - [%c]\n", pos, pQueue->pElement[pos].element);
		}
	}
}

//��ť ����(Char)
int enqueueAQChar(ArrayQueue *pQueue, char element){
	ArrayQueueNode node = { 0, };
	node.element = element;

	return enqueueAQ(pQueue, node);
}


