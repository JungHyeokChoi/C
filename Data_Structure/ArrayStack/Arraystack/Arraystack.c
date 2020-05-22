#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraystack.h"

//스택 생성
ArrayStack * createArrayStack(int size){
	ArrayStack* pReturn = NULL;
	int i = 0;

	if (size > 0) {
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
		
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(ArrayStack));
			pReturn->maxElementCount = size;
		}
		else {
			printf("오류, 메모리할당 createArrayStack()\n");
			return pReturn;
		}

		pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode)*size);

		if (pReturn->pElement != NULL) {
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode)*size);
		}
		else {
			printf("오류, 메모리할당2 createArrayStack()\n");
			free(pReturn);

			return pReturn;
		}
	}
	else {
		printf("오류, 스택의 크기는 0 이상이여야 합니다.\n");
		return NULL;
	}

	return pReturn;
}

//노드 추가
int pushAs(ArrayStack * pStack, ArrayStackNode element){
	int ret = FALSE;
	int i = 0;

	if (pStack != NULL) {
		if (isArrayStackFull(pStack) == FALSE) {
			pStack->pElement[pStack->currentElementCount] = element;

			pStack->currentElementCount++;

			ret = TRUE;
		}
	}
	else {
		printf("오류, 스택이 가득 찼습니다. pushAs()\n");
	}

	return ret;
}

//노드 제거
ArrayStackNode * popAs(ArrayStack * pStack){
	ArrayStackNode* pReturn = NULL;
	
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));

			if (pReturn != NULL) {
				*pReturn = pStack->pElement[pStack->currentElementCount - 1];
				pStack->currentElementCount--;
			}
			else {
				printf("오류, 메모리할당 popAs()\n");
			}
		}
	}
	return pReturn;
}

//Top 노드 확인
ArrayStackNode * peekAs(ArrayStack * pStack){
	ArrayStackNode* pReturn = NULL;
	
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
		}
	}
	return pReturn;
}

//스택 제거
void deletArrayStack(ArrayStack* pStack){
	if (pStack != NULL) {
		if (pStack->pElement != NULL) {
			free(pStack->pElement);
		}
		free(pStack);
	}
}

//스택 확인(Full)
int isArrayStackFull(ArrayStack * pStack){
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == pStack->maxElementCount) {
			ret = TRUE;
		}
	}
	return ret;
}

//스택 확인(Empty)
int isArrayStackEmpty(ArrayStack * pStack){
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {
			ret = TRUE;
		}
	}
	return ret;
}

//스택 전체 데이터 확인
void displayArrayStack(ArrayStack * pStack){
	int i = 0;

	if (pStack != NULL) {
		int size = pStack->maxElementCount;
		int top = pStack->currentElementCount;

		printf("스택 크기 : %d, 현재 노드 개수 : %d\n", size, top);

		for (i = size - 1; i >= top; i--) {
			printf("[%d]-[Empty]\n",i);
		}

		for (i = top - 1; i >= 0; i--) {
			printf("[%d]-[%c]\n", i, pStack->pElement[i].data);
		}
		printf("\n");
	}
}













