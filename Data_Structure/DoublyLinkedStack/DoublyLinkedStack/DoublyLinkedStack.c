#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedStack.h"

//이중연결 스택 생성
DoublyLinkedStack* createDLStack(){
	DoublyLinkedStack* pReturn = NULL;

	pReturn = (DoublyLinkedStack*)malloc(sizeof(DoublyLinkedStack));

	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(DoublyLinkedStack));
	}
	else {
		printf("오류, 메모리할당 createDLStack()\n");
		return NULL;
	}

	return pReturn;
}

//노드 추가
int pushDLS(DoublyLinkedStack* pStack, DoublyLinkedStackNode element){
	int ret = FALSE;
	DoublyLinkedStackNode* pNode = NULL;

	if (pStack != NULL) {
		pNode = (DoublyLinkedStackNode*)malloc(sizeof(DoublyLinkedStackNode));

		if (pNode != NULL) {
			memset(pNode, 0, sizeof(DoublyLinkedStackNode));

			*pNode = element;
			
			if (pStack->currentElemnetCount == 0) {
				pNode->pTLink = pStack->pTopElement;
				pNode->pBLink = NULL;
					
				pStack->pTopElement = pNode;

				pStack->currentElemnetCount++;
				ret = TRUE;
			}
			else {
				pStack->pTopElement->pTLink = pNode;
				pNode->pBLink = pStack->pTopElement;

				pStack->pTopElement = pNode;

				pNode->pTLink = pStack->pTopElement;
			
				pStack->currentElemnetCount++;
				ret = TRUE;
			}
		}
		else {
			printf("오류, 메모리할당 pushDLS()\n");
		}
	}
	return ret;
}

//노드 제거
DoublyLinkedStackNode * popDLS(DoublyLinkedStack * pStack){
	DoublyLinkedStackNode* pReturn = NULL;

	if (pStack != NULL) {
		if (isDLStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;

			pStack->pTopElement = pReturn->pBLink;

			pReturn->pTLink = NULL;
			pReturn->pBLink = NULL;

			pStack->currentElemnetCount--;
		}
	}

	return pReturn;
}

//최상위 노드 확인
DoublyLinkedStackNode * peekDLS(DoublyLinkedStack * pStack){
	DoublyLinkedStackNode* pReturn = NULL;

	if (pStack != NULL) {
		if (isDLStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
		}
	}
	return pReturn;
}

//스택 삭제
void deleteDLStack(DoublyLinkedStack * pStack){
	DoublyLinkedStackNode* pNode = NULL;
	DoublyLinkedStackNode* pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pBLink;
			free(pDelNode);
		}

		free(pStack);
	}
}

//스택리스트 확인(Full)
int isDLStackFull(DoublyLinkedStack * pStack) {
	int ret = FALSE;

	return ret;
}

//스택리스트 확인(Empty)
int isDLStackEmpty(DoublyLinkedStack * pStack) {
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElemnetCount == 0) {
			ret = TRUE;
		}
	}
	return ret;
}

//스택리스트 데이터 확인
void displayDLStack(DoublyLinkedStack * pStack){
	DoublyLinkedStackNode* pNode = NULL;
	int i = 0;

	if (pStack != NULL) {
		printf("현재 노드 개수 %d \n\n", pStack->currentElemnetCount);

		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", pStack->currentElemnetCount - i, pNode->data);
			pNode = pNode->pBLink;
			i++;
		}
		printf("\n");
	}
}




