#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exprdef.h"
#include "Exprlinkedstack.h"

//스택리스트 생성
LinkedStack * createLinkedStack() {
	LinkedStack* pReturn = NULL;
	int i = 0;

	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));

	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedStack));
	}
	else {
		printf("오류, 메모리할당 createLinkedStack()\n");
		return NULL;
	}

	return pReturn;
}

//노드 추가
int pushLS(LinkedStack * pStack, StackNode element) {
	int ret = FALSE;
	StackNode* pNode = NULL;

	if (pStack != NULL) {
		pNode = (StackNode*)malloc(sizeof(StackNode));

		if (pNode != NULL) {
			memset(pNode, 0, sizeof(StackNode));
			*pNode = element;
			pNode->pLink = pStack->pTopElement;

			pStack->pTopElement = pNode;

			pStack->currentElemnetCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 메모리할당 pushLS()\n");
		}
	}
	return ret;
}

//노드 제거
StackNode * popLS(LinkedStack * pStack) {
	StackNode* pReturn = NULL;

	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;

			pStack->pTopElement = pReturn->pLink;

			pReturn->pLink = NULL;

			pStack->currentElemnetCount--;
		}
	}

	return pReturn;
}

//최상위 노드 확인
StackNode * peekLS(LinkedStack * pStack) {
	StackNode* pReturn = NULL;

	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
		}
	}
	return pReturn;
}

//스택리스트 제거
void deleteLinkedStack(LinkedStack * pStack) {
	StackNode *pNode = NULL;
	StackNode *pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTopElement;

		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		free(pStack);
	}
}

//스택리스트 확인(Full)
int isLinkedStackFull(LinkedStack * pStack) {
	int ret = FALSE;

	return ret;
}

//스택리스트 확인(Empty)
int isLinkedStackEmpty(LinkedStack * pStack) {
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElemnetCount == 0) {
			ret = TRUE;
		}
	}
	return ret;
}

//스택리스트 데이터 확인
void displayLinkedStack(LinkedStack * pStack) {
	StackNode* pNode = NULL;
	int i = 0;

	if (pStack != NULL) {
		printf("현재 노드 개수 : %d\n\n", pStack->currentElemnetCount);

		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", pStack->currentElemnetCount - i, pNode->data);
			pNode = pNode->pLink;
			i++;
		}
		printf("\n");
	}
}








