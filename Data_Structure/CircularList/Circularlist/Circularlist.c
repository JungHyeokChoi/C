#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Circularlist.h"

//리스트 생성
CircularList * createCircularList(){
	CircularList* pReturn = NULL;
	int i = 0;

	pReturn = (CircularList*)malloc(sizeof(CircularList));

	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(CircularList));
	}
	else {
		printf("오류, 메모리할당 createCircularList()\n");
		return NULL;
	}
	return pReturn;
}

//노드 추가
int addCLElement(CircularList * pList, int position, CircularListNode element){
	int ret = FALSE;
	int i = 0;
	CircularListNode *pPreNode = NULL, *pNewNode = NULL, *pLastNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {
			pNewNode = (CircularListNode*)malloc(sizeof(CircularListNode));
			if (pNewNode == NULL) {
				printf("오류, 메모리할당 addCLElement()\n");
				return ret;
			}
			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0) {
				if (pList->currentElementCount == 0) {
					pList->headerNode.pLink = pNewNode;
					pNewNode->pLink = pNewNode;
				}
				else {
					pLastNode = pList->headerNode.pLink;
					while (pLastNode->pLink != pList->headerNode.pLink) {
						pLastNode = pLastNode->pLink;
					}

					pList->headerNode.pLink = pNewNode;
					pNewNode->pLink = pLastNode->pLink;
					pLastNode->pLink = pNewNode;
				}
			}
			else {
				pPreNode = pList->headerNode.pLink;
				for (i = 0; i < position-1; i++) {
					pPreNode = pPreNode->pLink;
				}

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			pList->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] addCLElement()\n", position);
		}
	}

	return ret;
}


//노드 제거
int removeCLElement(CircularList * pList, int position){
	int ret = FALSE;
	int i = 0;
	int arrayCount = 0;
	CircularListNode *pPreNode = NULL, *pDelNode = NULL, *pLastNode = NULL;

	if (pList != NULL) {
		arrayCount = getCircularListLength(pList);
		if (position >= 0 && position < arrayCount) {
			if (position == 0) {
				pDelNode = pList->headerNode.pLink;

				if (arrayCount == 1) {
					free(pDelNode);
					pList->headerNode.pLink = NULL;
				}
				else {
					pLastNode = pList->headerNode.pLink;
					while (pLastNode->pLink != pList->headerNode.pLink) {
						pLastNode = pLastNode->pLink;
					}
					pLastNode->pLink = pDelNode->pLink;
					pList->headerNode.pLink = pDelNode->pLink;
					free(pDelNode);
				}
			}
			else {
				pPreNode = pList->headerNode.pLink;
				for (i = 0; i < position - 1; i++) {
					pPreNode = pPreNode->pLink;
				}

				pDelNode = pPreNode->pLink;
				pPreNode->pLink = pDelNode->pLink;
				free(pDelNode);
			}
			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] removeCLElement()\n",position);
		}
	}
	return ret;
}

//노드 데이터 확인
CircularListNode * getCLElement(CircularList * pList, int position){
	int i = 0;
	CircularListNode* pNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {
			pNode = pList->headerNode.pLink;
			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;
			}
		}
	}
	return pNode;
}

//리스트 확인
void displayCircularList(CircularList * pList){
	int i = 0;

	if (pList != NULL) {
		printf("현재 원소 개수 : %d\n", pList->currentElementCount);
		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d]-%d\n", i, getCLElement(pList, i)->data);
		}
	}
	else {
		printf("원소가 없습니다.\n");
	}
}

//리스트 길이 확인
int getCircularListLength(CircularList * pList){
	int ret = 0;
	
	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

//리스트 삭제
void deleteCircularList(CircularList * pList){
	int i = 0;
	if (pList != NULL) {
		clearCircularList(pList);
		free(pList);
	}
}

//리스트 초기화
void clearCircularList(CircularList * pList){
	if (pList != NULL) {
		while (pList->currentElementCount > 0) {
			removeCLElement(pList, 0);
		}
	}
}