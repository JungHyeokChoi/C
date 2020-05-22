#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkeddeque.h"


//연결리스트 덱 생성
LinkedDeque* createLinkedDeque(){
	LinkedDeque *pReturn = NULL;

	pReturn = (LinkedDeque*)malloc(sizeof(LinkedDeque));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedDeque));
	}
	else {
		printf("오류, 메모리 할당, createLinkedDeque()\n");
		return NULL;
	}

	return pReturn;
}

//노드 추가(Front)
int insertFrontLD(LinkedDeque *pDeque, DequeNode element){
	int ret = FALSE;
	DequeNode *pNode = NULL;

	if (pDeque != NULL) {
		pNode = (DequeNode*)malloc(sizeof(DequeNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;

			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pFrontNode = pNode;
				pDeque->pRearNode = pNode;
			}
			else {
				pDeque->pFrontNode->pLLink = pNode;
				pNode->pRLink = pDeque->pFrontNode;
				pDeque->pFrontNode = pNode;
			}

			pDeque->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 메모리 할당 insertFrontLD()\n");
		}
	}
	return ret;
}

//노드 추가(Rear)
int insertRearLD(LinkedDeque *pDeque, DequeNode element){
	int ret = FALSE;
	DequeNode *pNode = NULL;

	if (pDeque != NULL) {
		pNode = (DequeNode*)malloc(sizeof(DequeNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;

			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pFrontNode = pNode;
				pDeque->pRearNode = pNode;
			}
			else {
				pDeque->pRearNode->pRLink = pNode;
				pNode->pLLink = pDeque->pRearNode;
				pDeque->pRearNode = pNode;
			}

			pDeque->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 메모리 할당 insertFrontLD()\n");
		}
	}
	return ret;
}

//노드 삭제(Front)
DequeNode* deleteFrontLD(LinkedDeque* pDeque){
	DequeNode* pReturn = NULL;

	if (pDeque != NULL) {
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pFrontNode;
			pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
			pReturn->pRLink = NULL;

			pDeque->currentElementCount--;
			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pRearNode = NULL;
			}
			else {
				pDeque->pFrontNode->pLLink = NULL;
			}
		}
	}
	return pReturn;
}

//피크 연산(Front)
DequeNode* peekFrontLD(LinkedDeque* pDeque){
	DequeNode* pReturn = NULL;

	if (pDeque != NULL) {
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pFrontNode;
		}
	}
	return pReturn;
}

//노드 삭제(Rear)
DequeNode* deleteRearLD(LinkedDeque *pDeque){
	DequeNode* pReturn = NULL;

	if(pDeque != NULL){
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pRearNode;
			pDeque->pRearNode = pDeque->pRearNode->pLLink;
			pReturn->pLLink = NULL;

			pDeque->currentElementCount--;
			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pFrontNode = NULL;
			}
			else {
				pDeque->pRearNode->pRLink = NULL;
			}
		}
	}
	return pReturn;
}

//피크 연산(Rear)
DequeNode* peekRearLD(LinkedDeque *pDeque){
	DequeNode* pReturn = NULL;

	if (pDeque != NULL) {
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pRearNode;
		}
	}
	return pReturn;
}

//덱 삭제
void deleteLinkedDeque(LinkedDeque *pDeque){
	DequeNode* pNode = NULL;
	DequeNode* pDelNode = NULL;

	if (pDeque != NULL) {
		pNode = pDeque->pFrontNode;
		while(pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pRLink;
			free(pDelNode);
		}

		free(pDeque);
	}
}

//덱(Full) 연산
int isLinkedDequeFull(LinkedDeque *pDeque){
	int ret = FALSE;

	return ret;
}

//덱(Empty) 연산
int isLinkedDequeEmpty(LinkedDeque *pDeque){
	int ret = FALSE;
	
	if (pDeque != NULL) {
		if (pDeque->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

//덱 데이터 확인
void displayLinkedDeque(LinkedDeque *pDeque){
	DequeNode* pNode = NULL;
	int i = 0;

	if (pDeque != NULL) {
		printf("현재 노드 개수 : %d\n", pDeque->currentElementCount);
		
		pNode = pDeque->pFrontNode;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pRLink;
		}
	}

}

int insertFrontLDchar(LinkedDeque *pDeque, char data){
	DequeNode node = { 0, };
	node.data = data;

	return insertFrontLD(pDeque, node);
}

int insertRearLDchar(LinkedDeque *pDeque, char data) {
	DequeNode node = { 0, };
	node.data = data;

	return insertRearLD(pDeque, node);
}


















