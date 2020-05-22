#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Linkedlisttop.h"


// 리스트 순회
void iterateLinkedList(LinkedList * pList){
	ListNode* pNode = NULL;
	int count = 0;

	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while (pNode != NULL) {
			printf("[%d],%d\n", count, pNode->data);
			count++;

			pNode = pNode->pLink;
		}

		printf("노드 개수 : %d\n", count);
	}
	else {
		printf("공백 리스트입니다.\n");
	}
}


//리스트 연결
void concatLinkedList(LinkedList * pListA, LinkedList * pListB){
	ListNode *pNodeA = NULL, *pNodeB = NULL;

	if (pListA != NULL && pListB != NULL) {
		pNodeA = pListA->headerNode.pLink;
		while (pNodeA->pLink != NULL) {
			pNodeA = pNodeA->pLink;
		}
		pNodeA->pLink = pListB->headerNode.pLink;
		pListA->currentElementCount += pListB->currentElementCount;

		pListB->headerNode.pLink = NULL;
		pListB->currentElementCount = 0;
	}
}

//리스트 역순
void reverseLinkedList(LinkedList * pList){
	ListNode *pNode = NULL, *pCurrentNode = NULL, *pPreNode = NULL;

	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while (pNode != NULL) {
			pPreNode = pCurrentNode;
			pCurrentNode = pNode;
			pNode = pNode->pLink;
			pCurrentNode->pLink = pPreNode;
		}

		pList->headerNode.pLink = pCurrentNode;
	}
}




