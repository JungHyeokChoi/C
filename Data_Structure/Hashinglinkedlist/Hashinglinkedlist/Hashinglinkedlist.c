#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashingdef.h"
#include "Hashinglinkedlist.h"


// ����Ʈ �߰�
LinkedList *createLinkedList() {
	LinkedList* pReturn = NULL;
	int i = 0;

	pReturn = (LinkedList*)malloc(sizeof(LinkedList));

	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedList));
	}
	else {
		printf("����, �޸��Ҵ� createLinkedList()\n");
		return NULL;
	}

	return pReturn;
}

//��� �߰�
int addLLElement(LinkedList *pList, int position, ListNode element) {
	int ret = FALSE;
	int i = 0;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL) {
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(pList->headerNode);
				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				}

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;

				pList->currentElementCount++;

				ret = TRUE;
			}
			else {
				printf("����, �޸��Ҵ� addLLElement()\n");
				return ret;
			}
		}
		else {
			printf("����, ��ġ �ε���-[%d],addLLElement()\n", position);
		}
	}
	return ret;
}

int addLLElementLast(LinkedList *pList, HashElement element){
	int ret = FALSE;
	int i = 0;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL) {
				pNewNode->data = element;
				pNewNode->pLink = NULL;

				pList->headerNode.pLink = pNewNode;
				pList->currentElementCount++;

				ret = TRUE;
			}
		}
		else {
			pPreNode = &(pList->headerNode);
			for (i = 0; i < pList->currentElementCount; i++) {
				pPreNode = pPreNode->pLink;
			}

			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL) {
				pNewNode->data = element;
				pNewNode->pLink = NULL;

				pPreNode->pLink = pNewNode;
				pList->currentElementCount++;

				ret = TRUE;
			}

		}
	}
	return ret;
}

//��� ����
int removeLLElement(LinkedList *pList, int position) {
	int ret = FALSE;
	int i = 0;
	int arrayCount = 0;
	ListNode* pNode = NULL;
	ListNode* pDelNode = NULL;

	if (pList != NULL) {
		arrayCount = getLinkedListLengh(pList);
		if (position >= 0 && position < arrayCount) {
			pNode = &(pList->headerNode);
			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;
			}

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink;

			free(pDelNode);

			pList->currentElementCount--;

			ret = TRUE;

		}
		else {
			printf("����, ��ġ �ε���-[%d] removeLLEmenet()\n", position);

		}
	}

	return ret;
}

//��� ��ȯ
ListNode * getLLElement(LinkedList *pList, int position) {
	ListNode* pReturn = NULL;
	int i = 0;
	ListNode* pNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {
			pNode = &(pList->headerNode);
			for (i = 0; i <= position; i++) {
				pNode = pNode->pLink;
			}
			pReturn = pNode;
		}
	}
	return pReturn;
}

//����Ʈ ����
void deleteLinkedList(LinkedList *pList) {
	int i = 0;
	if (pList != NULL) {
		clearLinkedList(pList);
		free(pList);
	}
}

//������ �ʱ�ȭ
void clearLinkedList(LinkedList *pList) {
	if (pList != NULL) {
		if (pList->currentElementCount > 0) {
			removeLLElement(pList, 0);
		}
	}
}

//��� ���� ��ȯ
int getLinkedListLengh(LinkedList *pList) {
	int ret = 0;

	if (pList != NULL) {
		ret = pList->currentElementCount;
	}
	return ret;
}

//����Ʈ ���� Ȯ��
int isEmpty(LinkedList *pList) {
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {
			ret = TRUE;
		}
	}
	return ret;
}


// ����Ʈ Ȯ��
void displayLinkedList(LinkedList *pList) {
	int i = 0;

	if (pList != NULL) {
		printf("���� ���� ���� : %d\n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getLLElement(pList, i)->data);
		}
	}
	else {
		printf("���Ұ� �����ϴ�\n");
	}
}