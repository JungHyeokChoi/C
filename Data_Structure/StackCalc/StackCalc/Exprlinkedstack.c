#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exprdef.h"
#include "Exprlinkedstack.h"

//���ø���Ʈ ����
LinkedStack * createLinkedStack() {
	LinkedStack* pReturn = NULL;
	int i = 0;

	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));

	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedStack));
	}
	else {
		printf("����, �޸��Ҵ� createLinkedStack()\n");
		return NULL;
	}

	return pReturn;
}

//��� �߰�
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
			printf("����, �޸��Ҵ� pushLS()\n");
		}
	}
	return ret;
}

//��� ����
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

//�ֻ��� ��� Ȯ��
StackNode * peekLS(LinkedStack * pStack) {
	StackNode* pReturn = NULL;

	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
		}
	}
	return pReturn;
}

//���ø���Ʈ ����
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

//���ø���Ʈ Ȯ��(Full)
int isLinkedStackFull(LinkedStack * pStack) {
	int ret = FALSE;

	return ret;
}

//���ø���Ʈ Ȯ��(Empty)
int isLinkedStackEmpty(LinkedStack * pStack) {
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElemnetCount == 0) {
			ret = TRUE;
		}
	}
	return ret;
}

//���ø���Ʈ ������ Ȯ��
void displayLinkedStack(LinkedStack * pStack) {
	StackNode* pNode = NULL;
	int i = 0;

	if (pStack != NULL) {
		printf("���� ��� ���� : %d\n\n", pStack->currentElemnetCount);

		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", pStack->currentElemnetCount - i, pNode->data);
			pNode = pNode->pLink;
			i++;
		}
		printf("\n");
	}
}








