#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Polylist.h"

//���׽� �� �߰�
int addPolyNodeList(LinkedList * pList, float coef, int degree){
	int ret = FALSE, i = 0;

	ListNode node = { 0, };
	node.coef = coef;
	node.degree = degree;

	if (pList != NULL) {
		int length = getLinkedListLengh(pList);
		ret = addLLElement(pList, length, node);
	}

	return ret;
}

//���׽� ����
LinkedList * polyAdd(LinkedList * pListA, LinkedList * pListB){
	LinkedList* pReturn = NULL;
	ListNode *pNodeA = NULL, *pNodeB = NULL;
	float coefSum = 0;

	if (pListA != NULL && pListB != NULL) {
		pReturn = createLinkedList();
		if (pReturn == NULL) {
			printf("����, �޸��Ҵ�, polyAdd()\n");
			return NULL;
		}

		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;

		while (pNodeA != NULL && pNodeB != NULL) {
			int degreeA = pNodeA->degree;
			int degreeB = pNodeB->degree;

			if (degreeA > degreeB) {
				coefSum = pNodeA->coef;
				addPolyNodeList(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}

			else if (degreeA == degreeB) {
				coefSum = pNodeA->coef + pNodeB->coef;
				addPolyNodeList(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}

			else if (degreeA < degreeB) {
				coefSum = pNodeB->coef;
				addPolyNodeList(pReturn, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}

			else {
				coefSum = pNodeB->coef;
				addPolyNodeList(pReturn, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}
		
		while (pNodeA != NULL) {
			coefSum = pNodeA->coef;
			addPolyNodeList(pReturn, coefSum, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while (pNodeB != NULL) {
			coefSum = pNodeB->coef;
			addPolyNodeList(pReturn, coefSum, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}
		
	 }
	else {
		printf("����, NULL ���׽��� ���޵Ǿ����ϴ�, polyAdd()\n");
	}

	return pReturn;
}

//���׽� ����
LinkedList* polySubtraction(LinkedList * pListA, LinkedList * pListB){
	LinkedList* pReturn = NULL;
	ListNode *pNodeA = NULL, *pNodeB = NULL;
	float coefSum = 0;

	if (pListA != NULL && pListB != NULL) {
		pReturn = createLinkedList();
		if (pReturn == NULL) {
			printf("����, �޸��Ҵ�, polyAdd()\n");
			return NULL;
		}

		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;

		while (pNodeA != NULL && pNodeB != NULL) {
			int degreeA = pNodeA->degree;
			int degreeB = pNodeB->degree;

			if (degreeA > degreeB) {
				coefSum = pNodeA->coef;
				addPolyNodeList(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}

			else if (degreeA == degreeB) {
				coefSum = pNodeA->coef - pNodeB->coef;
				addPolyNodeList(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}

			else {
				coefSum = pNodeB->coef;
				addPolyNodeList(pReturn, -coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}

		while (pNodeA != NULL) {
			coefSum = pNodeA->coef;
			addPolyNodeList(pReturn, coefSum, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while (pNodeB != NULL) {
			coefSum = pNodeB->coef;
			addPolyNodeList(pReturn, -coefSum, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}

	}
	else {
		printf("����, NULL ���׽��� ���޵Ǿ����ϴ�, polyAdd()\n");
	}

	return pReturn;
}

//���׽� Ȯ��
void displayPolyList(LinkedList * pList) {
	int i = 0;
	float fCoef = 0;

	if (pList != NULL) {
		for (i = 0; i < pList->currentElementCount; i++) {
			ListNode *pNode = getLLElement(pList, i);
			if (pNode != NULL) {
				fCoef = pNode->coef;
				if (fCoef < 0) {
					printf(" - ");
					printf("%4.1fx^%d", -fCoef, pNode->degree);
					
				}
				else {
					if (i == 0) {
						printf("%4.1fx^%d", fCoef, pNode->degree);
					}
					
					else {
						printf(" + ");
						printf("%4.1fx^%d", fCoef, pNode->degree);
					}
					
					
				}
			}
		}
		printf("\n");
	}
	else {
		printf("�� ���׽� �Դϴ�.\n");
	}
}

