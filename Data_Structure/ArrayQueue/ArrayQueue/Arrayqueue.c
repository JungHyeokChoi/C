#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrayqueue.h"

//배열 큐 생성
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
			printf("오류, 메모리할당,createArrayQueue()\n");
			return NULL;
		}
	}
	else {
		printf("오류, 큐 크기는 0보다 커야 합니다\n");
		return NULL;
	}

	pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode)*maxElementCount);
	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(ArrayQueueNode)*maxElementCount);
	}
	else {
		printf("오류, 메모리할당2,createArrayQueue()\n");
		free(pReturn);
		return NULL;
	}

	return pReturn;
}

//인큐 연산
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
			printf("오류, 큐가 가득 찼습니다, enqueueAQ()\n");
		}
	}

	return ret;
}

//디큐 연산
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
				printf("오류, 메모리할당,dequeueAQ()\n");
			}
		}
	}

	return pReturn;
}

//피크 연산
ArrayQueueNode *peekAQ(ArrayQueue *pQueue){
	ArrayQueueNode *pReturn = NULL;
	
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == FALSE) {
			pReturn = &(pQueue->pElement[pQueue->front + 1]);
		}
	}

	return pReturn;
}

//큐 삭제
void deleteArrayQueue(ArrayQueue *pQueue){
	if (pQueue != NULL) {
		if (pQueue->pElement != NULL) {
			free(pQueue->pElement);
		}
		free(pQueue);
	}
}

//큐(Full) 연산
int isArrayQueueFull(ArrayQueue *pQueue){
	int ret = FALSE;
	
	if (pQueue != NULL) {
		if (pQueue->currentElementCount == pQueue->maxElementCount) {
			ret = TRUE;
		}
	}
	return ret;
}

//큐(Empty) 연산
int isArrayQueueEmpty(ArrayQueue *pQueue){
	int ret = FALSE;

	if (pQueue != NULL) {
		if (pQueue->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

//큐 데이터 확인
void displayArrayQueue(ArrayQueue *pQueue){
	int i = 0, maxElementIndex = 0, pos = 0;

	if (pQueue != NULL) {
		printf("큐의 크기 : %d, 현재 노드 개수 : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);

		maxElementIndex = pQueue->front + pQueue->currentElementCount;
		for (i = pQueue->front+1; i <= maxElementIndex; i++) {
			pos = i % pQueue->maxElementCount;
			printf("[%d] - [%c]\n", pos, pQueue->pElement[pos].element);
		}
	}
}

//인큐 연산(Char)
int enqueueAQChar(ArrayQueue *pQueue, char element){
	ArrayQueueNode node = { 0, };
	node.element = element;

	return enqueueAQ(pQueue, node);
}


