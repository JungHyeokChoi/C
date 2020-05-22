#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraystack.h"

//���� ����
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
			printf("����, �޸��Ҵ� createArrayStack()\n");
			return pReturn;
		}

		pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode)*size);

		if (pReturn->pElement != NULL) {
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode)*size);
		}
		else {
			printf("����, �޸��Ҵ�2 createArrayStack()\n");
			free(pReturn);

			return pReturn;
		}
	}
	else {
		printf("����, ������ ũ��� 0 �̻��̿��� �մϴ�.\n");
		return NULL;
	}

	return pReturn;
}

//��� �߰�
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
		printf("����, ������ ���� á���ϴ�. pushAs()\n");
	}

	return ret;
}

//��� ����
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
				printf("����, �޸��Ҵ� popAs()\n");
			}
		}
	}
	return pReturn;
}

//Top ��� Ȯ��
ArrayStackNode * peekAs(ArrayStack * pStack){
	ArrayStackNode* pReturn = NULL;
	
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
		}
	}
	return pReturn;
}

//���� ����
void deletArrayStack(ArrayStack* pStack){
	if (pStack != NULL) {
		if (pStack->pElement != NULL) {
			free(pStack->pElement);
		}
		free(pStack);
	}
}

//���� Ȯ��(Full)
int isArrayStackFull(ArrayStack * pStack){
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == pStack->maxElementCount) {
			ret = TRUE;
		}
	}
	return ret;
}

//���� Ȯ��(Empty)
int isArrayStackEmpty(ArrayStack * pStack){
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {
			ret = TRUE;
		}
	}
	return ret;
}

//���� ��ü ������ Ȯ��
void displayArrayStack(ArrayStack * pStack){
	int i = 0;

	if (pStack != NULL) {
		int size = pStack->maxElementCount;
		int top = pStack->currentElementCount;

		printf("���� ũ�� : %d, ���� ��� ���� : %d\n", size, top);

		for (i = size - 1; i >= top; i--) {
			printf("[%d]-[Empty]\n",i);
		}

		for (i = top - 1; i >= 0; i--) {
			printf("[%d]-[%c]\n", i, pStack->pElement[i].data);
		}
		printf("\n");
	}
}













