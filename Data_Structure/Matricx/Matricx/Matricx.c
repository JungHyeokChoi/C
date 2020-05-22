#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Doublylist.h"
#include "Matricx.h"


//��� ����Ʈ �߰�
DoublyList* createMatricDoublyList(int maxColumn, int maxRow) {
	DoublyList* pReturn = NULL;
	int i = 0;

	pReturn = (DoublyList*)malloc(sizeof(DoublyList));

	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(DoublyList));
		pReturn->maxColumn = maxColumn;
		pReturn->maxRow = maxRow;

		pReturn->headerNode.pLLink = &(pReturn->headerNode);
		pReturn->headerNode.pRLink = &(pReturn->headerNode);
	}
	else {
		printf("����, �޸��Ҵ� createMatricxLinkedList()\n");
		return NULL;
	}

	return pReturn;
}

//��� ���� �߰�
int addMatricxNodeDoublyList(DoublyList * pList, int column, int row, int data) {
	int ret = FALSE;
	int i = 0, j = 0;
	DoublyListNode node = { 0, };

	node.column = column;
	node.row = row;
	node.data = data;

	if (pList != NULL) {
		if ((column > 0 && column <= pList->maxColumn) && (row > 0 && row <= pList->maxRow)) {
			int length = getDoublyListLength(pList);
			ret = addDLElement(pList, length, node);
		}
		else {
			printf("����, �޸��Ҵ� addMatricxNodeList()\n");
			return ret;
		}
	}
	else {
		printf("����, ��ġ �ε���-[%d][%d],addMatricxNodeList()\n", column, row);
	}
	return ret;
}

//��� ��ġ
DoublyList* matricxTransposed(DoublyList * pList) {
	int i = 0, j = 0, position = 0, count = 0;
	DoublyList *pReturn = NULL;
	DoublyListNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;

	if (pList != NULL) {
		pReturn = createMatricDoublyList(pList->maxRow, pList->maxColumn);

		if (pReturn != NULL) {
			pNodeA = pList->headerNode.pRLink;

			for (i = 0; i < pList->currentElementCount; ) {
				if (position == 0) {
					DoublyListNode node = { 0, };
					node.column = pNodeA->row;
					node.row = pNodeA->column;
					node.data = pNodeA->data;

					addDLElement(pReturn, position, node);

					pNodeA = pNodeA->pRLink;
					
					if (i == 0) {
						pNodeB = pReturn->headerNode.pRLink;
						position++;
					}
					else {
						pNodeB = pReturn->headerNode.pLLink;
						position = position + count + 1;
						count = 0;
					}

					i++;
				}
				else {
					if (pNodeA->row > pNodeB->column) {

						DoublyListNode node = { 0, };
						node.column = pNodeA->row;
						node.row = pNodeA->column;
						node.data = pNodeA->data;

						addDLElement(pReturn, position, node);

						pNodeA = pNodeA->pRLink;
						if (count == 0) {
							pNodeB = pNodeB->pRLink;
							position++;
						}
						else {
							pNodeB = pReturn->headerNode.pLLink;
							position = position + count + 1;
						}
						
						i++;
					}
					else if (pNodeA->row == pNodeB->column) {
						if (pNodeA->column > pNodeB->row) {
							DoublyListNode node = { 0, };
							node.column = pNodeA->row;
							node.row = pNodeA->column;
							node.data = pNodeA->data;
	
							addDLElement(pReturn, position, node);

							pNodeA = pNodeA->pRLink;
							pNodeB = pNodeB->pRLink;
							position = position + count + 1;
							i++;
						}
						else {
							pNodeB = pNodeB->pLLink;
							position--;
							count++;
							}
					}
					else {
						pNodeB = pNodeB->pLLink;
						count++;
						position--;
					}
				}
			}
		}
		else {
			printf("����, �޸��Ҵ� matricxTransposed()\n");
			return pReturn;
		}
	}
	else {
		printf("����, �޸��Ҵ� matricxTransposed()\n");
		return pReturn;
	}

	return pReturn;
}

//��� Ȯ��
void displayMatricxDoublyList(DoublyList * pList) {
	int i = 0, j = 0, count = 0;

	if (pList != NULL) {
		for (i = 0; i < pList->maxColumn; i++) {
			for (j = 0; j < pList->maxRow; j++) {
				DoublyListNode *pNode = getDLElement(pList, count);
				if ((pNode->column - 1) == i && (pNode->row - 1) == j) {
					printf("%d ", pNode->data);

					if (count < pList->currentElementCount - 1) {
						count++;
					}
				}
				else {
					printf("0 ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	else {
		printf("�� ��� �Դϴ�.\n");
	}
}