#include <stdio.h>
#include <stdlib.h>
#include "Linkedheap.h"
#include "Heaplinkedstack.h"

//히프 생성
LinkedHeap *createLinkedHeap(){
	LinkedHeap* pReturn = NULL;
	
	pReturn = (LinkedHeap*)malloc(sizeof(LinkedHeap));
	if (pReturn != NULL) {
		pReturn->pRootNode = NULL;
		pReturn->currentElementCount = 0;
	}
	else {
		printf("오류, 메모리 할당, makeLinkedHeap()\n");
	}
	
	return pReturn;

}

//최대 히프 노드 삽입
int insertMaxHeapLH(LinkedHeap *pMaxHeap, LinkedHeapNode element){
	int ret = TRUE, Count = 0, nodeNum = 0, iLoop = 0;
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	LinkedHeapNode* pParentNode = NULL, *pChildNode = NULL;
	LinkedHeapNode* pNewNode = NULL;

	if (pMaxHeap == NULL) {
		ret = FALSE;
		return ret;
	}

	pStack = createLinkedStack();
	if (pStack == NULL) {
		ret = FALSE;
		return ret;
	}

	pMaxHeap->currentElementCount++;
	Count = pMaxHeap->currentElementCount;

	pParentNode = pMaxHeap->pRootNode;
	pushLSHeapNode(pStack, pParentNode);

	while ((Count != 1) && pParentNode->pLeftChild != NULL && pParentNode->pRightChild != NULL) {
		if (element.key == pParentNode->key) {
			printf("오류, 중복된 키 - [%d]\n", element.key);
			pMaxHeap->currentElementCount--;

			deleteLinkedStack(pStack);
			ret = FALSE;
			return ret;
		}

		while (Count > 3) {
			Count /= 2;
			iLoop++;
		}

		Count = pMaxHeap->currentElementCount;
		
		while(iLoop > 0) {
			int ret = FALSE;
			
			nodeNum = Count;
			for (int i = 1; i <= iLoop; i++) {
				nodeNum /= 2;
			}

			if (nodeNum % 2 == 0 && pParentNode->pLeftChild != NULL) {
				pParentNode = pParentNode->pLeftChild;
				pushLSHeapNode(pStack, pParentNode);
			}
			else if (nodeNum % 2 == 1 && pParentNode->pRightChild != NULL) {
				pParentNode = pParentNode->pRightChild;
				pushLSHeapNode(pStack, pParentNode);
			}

			iLoop--;
			
		}
	}

	pNewNode = (LinkedHeapNode*)malloc(sizeof(LinkedHeapNode));
	if (pNewNode != NULL) {
		*pNewNode = element;
		pNewNode->pLeftChild = NULL;
		pNewNode->pRightChild = NULL;

		if (pParentNode == NULL) {
			pMaxHeap->pRootNode = pNewNode;
		}
		else {
			if (pParentNode->pLeftChild != NULL) {
				pParentNode->pRightChild = pNewNode;
			}
			else {
				pParentNode->pLeftChild = pNewNode;
			}

			pChildNode = pNewNode;
			while (isLinkedStackEmpty(pStack) == FALSE) {
				pStackNode = popLS(pStack);
				pParentNode = pStackNode->data;

				if (pParentNode->key < pChildNode->key) {
					pChildNode->key = pParentNode->key;
					pChildNode->data = pParentNode->data;

					pParentNode->key = element.key;
					pParentNode->data = element.data;
				}
				else {
					break;
				}
				pChildNode = pParentNode;
			}
		}
		ret = TRUE;
	}
	else {
		printf("오류, 메모리 할당, insertMaxHeapLH()\n");
		pMaxHeap->currentElementCount--;
		ret = FALSE;
	}

	deleteLinkedStack(pStack);

	return ret;
}

//최소 히프 노드 삽입
int insertMinHeapLH(LinkedHeap *pMinHeap, LinkedHeapNode element){
	int ret = TRUE, Count = 0, nodeNum = 0, iLoop = 0;
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	LinkedHeapNode* pParentNode = NULL, *pChildNode = NULL;
	LinkedHeapNode* pNewNode = NULL;

	if (pMinHeap == NULL) {
		ret = FALSE;
		return ret;
	}

	pStack = createLinkedStack();
	if (pStack == NULL) {
		ret = FALSE;
		return ret;
	}

	pMinHeap->currentElementCount++;
	Count = pMinHeap->currentElementCount;

	pParentNode = pMinHeap->pRootNode;
	pushLSHeapNode(pStack, pParentNode);

	while ((Count != 1) && pParentNode->pLeftChild != NULL && pParentNode->pRightChild != NULL) {
		if (element.key == pParentNode->key) {
			printf("오류, 중복된 키 - [%d]\n", element.key);
			pMinHeap->currentElementCount--;

			deleteLinkedStack(pStack);
			ret = FALSE;
			return ret;
		}

		while (Count > 3) {
			Count /= 2;
			iLoop++;
		}

		Count = pMinHeap->currentElementCount;

		while (iLoop > 0) {
			int ret = FALSE;

			nodeNum = Count;
			for (int i = 1; i <= iLoop; i++) {
				nodeNum /= 2;
			}

			if (nodeNum % 2 == 0 && pParentNode->pLeftChild != NULL) {
				pParentNode = pParentNode->pLeftChild;
				pushLSHeapNode(pStack, pParentNode);
			}
			else if (nodeNum % 2 == 1 && pParentNode->pRightChild != NULL) {
				pParentNode = pParentNode->pRightChild;
				pushLSHeapNode(pStack, pParentNode);
			}

			iLoop--;
			
		}
	}

	pNewNode = (LinkedHeapNode*)malloc(sizeof(LinkedHeapNode));
	if (pNewNode != NULL) {
		*pNewNode = element;
		pNewNode->pLeftChild = NULL;
		pNewNode->pRightChild = NULL;

		if (pParentNode == NULL) {
			pMinHeap->pRootNode = pNewNode;
		}
		else {
			if (pParentNode->pLeftChild != NULL) {
				pParentNode->pRightChild = pNewNode;
			}
			else {
				pParentNode->pLeftChild = pNewNode;
			}

			pChildNode = pNewNode;
			while (isLinkedStackEmpty(pStack) == FALSE) {
				pStackNode = popLS(pStack);
				pParentNode = pStackNode->data;

				if (pParentNode->key > pChildNode->key) {
					pChildNode->key = pParentNode->key;
					pChildNode->data = pParentNode->data;

					pParentNode->key = element.key;
					pParentNode->data = element.data;
				}
				else {
					break;
				}
				pChildNode = pParentNode;
			}
		}
		ret = TRUE;
	}
	else {
		printf("오류, 메모리 할당, insertMaxHeapLH()\n");
		pMinHeap->currentElementCount--;
		ret = FALSE;
	}

	deleteLinkedStack(pStack);

	return ret;
}


//최대 히프 노드 삭제
int deleteMaxHeapLH(LinkedHeap *pMaxHeap) {
	int ret = FALSE, Count = 0, nodeNum = 0, iLoop = 0;
	LinkedHeapNode *pParentNode = NULL, *pChildNode = NULL;
	LinkedHeapNode temp = { 0, };

	if (pMaxHeap == NULL) {
		ret = FALSE;
		return ret;
	}

	pParentNode = pMaxHeap->pRootNode;
	if (pParentNode != NULL) {
		if (pMaxHeap->currentElementCount == 1) {
			deleteLinkedHeapNode(pMaxHeap->pRootNode);

			pMaxHeap->pRootNode = NULL;

			pMaxHeap->currentElementCount--;

			ret = TRUE;
			return ret;
		}
		else if (pMaxHeap->currentElementCount < 4) {
			if (pParentNode->pRightChild == NULL) {
				pParentNode->key = pParentNode->pLeftChild->key;
				pParentNode->data = pParentNode->pLeftChild->data;

				deleteLinkedHeapNode(pParentNode->pLeftChild);

				pParentNode->pLeftChild = NULL;

				pMaxHeap->currentElementCount--;
			}
			else {
				if (pParentNode->pLeftChild->key > pParentNode->pRightChild->key) {
					pParentNode->key = pParentNode->pLeftChild->key;
					pParentNode->data = pParentNode->pLeftChild->data;

					pParentNode->pLeftChild->key = pParentNode->pRightChild->key;
					pParentNode->pLeftChild->key = pParentNode->pRightChild->data;
				}
				else {
					pParentNode->key = pParentNode->pRightChild->key;
					pParentNode->data = pParentNode->pRightChild->data;

				}
				deleteLinkedHeapNode(pParentNode->pRightChild);

				pParentNode->pRightChild = NULL;

				pMaxHeap->currentElementCount--;
			}
		}
		else {
			Count = pMaxHeap->currentElementCount;
			pParentNode = pMaxHeap->pRootNode;

			while (Count > 3) {
				Count /= 2;
				iLoop++;
			}

			Count = pMaxHeap->currentElementCount;

			while (iLoop > 0) {
				int ret = FALSE;

				nodeNum = Count;
				for (int i = 1; i <= iLoop; i++) {
					nodeNum /= 2;
				}

				if (nodeNum % 2 == 0 && pParentNode->pLeftChild != NULL) {
					pParentNode = pParentNode->pLeftChild;
				}
				else if (nodeNum % 2 == 1 && pParentNode->pRightChild != NULL) {
					pParentNode = pParentNode->pRightChild;
				}
				iLoop--;
			}

			if (pParentNode->pRightChild == NULL) {
				temp.key = pParentNode->pLeftChild->key;
				temp.data = pParentNode->pLeftChild->data;


				deleteLinkedHeapNode(pParentNode->pLeftChild);
				pParentNode->pLeftChild = NULL;
			}
			else {
				temp.key = pParentNode->pRightChild->key;
				temp.data = pParentNode->pRightChild->data;

				deleteLinkedHeapNode(pParentNode->pRightChild);
				pParentNode->pRightChild = NULL;
			}

			pMaxHeap->currentElementCount--;

			pParentNode = pMaxHeap->pRootNode;
			
			pChildNode = pParentNode->pLeftChild;

			while (pParentNode != NULL) {
				if (pParentNode->pLeftChild != NULL && pParentNode->pRightChild != NULL) {
					if (pParentNode->pLeftChild->key > pParentNode->pRightChild->key) {
						pChildNode = pParentNode->pLeftChild;

						if (temp.key < pChildNode->key) {
							pParentNode->key = pChildNode->key;
							pParentNode->data = pChildNode->data;

							pParentNode = pParentNode->pLeftChild;
						}
						else {
							break;
						}
					}
					else {
						pChildNode = pParentNode->pRightChild;

						if (temp.key < pChildNode->key) {
							pParentNode->key = pChildNode->key;
							pParentNode->data = pChildNode->data;

							pParentNode = pParentNode->pRightChild;
						}
						else {
							break;
						}
					}
				}
				else {
					if (pParentNode->pLeftChild != NULL &&pParentNode->pRightChild == NULL) {
						pChildNode = pParentNode->pLeftChild;

						if (temp.key < pChildNode->key) {
							pParentNode->key = pChildNode->key;
							pParentNode->data = pChildNode->data;
						}
						else {
							break;
						}

					}
					else {
						break;
					}
				}
			}
			pParentNode->key = temp.key;
			pParentNode->data = temp.data;
			
			ret = TRUE;
		}
	}
	
	return ret;
}

//최소 히프 노드 삭제
int deleteMinHeapLH(LinkedHeap *pMinHeap){
	int ret = FALSE, Count = 0, nodeNum = 0, iLoop = 0;
	LinkedHeapNode *pParentNode = NULL, *pChildNode = NULL;
	LinkedHeapNode temp = { 0, };

	if (pMinHeap == NULL) {
		ret = FALSE;
		return ret;
	}

	pParentNode = pMinHeap->pRootNode;
	if (pParentNode != NULL) {
		if (pMinHeap->currentElementCount == 1) {
			deleteLinkedHeapNode(pMinHeap->pRootNode);

			pMinHeap->pRootNode = NULL;

			pMinHeap->currentElementCount--;

			ret = TRUE;
			return ret;
		}
		else if (pMinHeap->currentElementCount < 4) {
			if (pParentNode->pRightChild == NULL) {
				pParentNode->key = pParentNode->pLeftChild->key;
				pParentNode->data = pParentNode->pLeftChild->data;

				deleteLinkedHeapNode(pParentNode->pLeftChild);

				pParentNode->pLeftChild = NULL;

				pMinHeap->currentElementCount--;
			}
			else {
				if (pParentNode->pLeftChild->key < pParentNode->pRightChild->key) {
					pParentNode->key = pParentNode->pLeftChild->key;
					pParentNode->data = pParentNode->pLeftChild->data;

					pParentNode->pLeftChild->key = pParentNode->pRightChild->key;
					pParentNode->pLeftChild->key = pParentNode->pRightChild->data;
				}
				else {
					pParentNode->key = pParentNode->pRightChild->key;
					pParentNode->data = pParentNode->pRightChild->data;

				}
				deleteLinkedHeapNode(pParentNode->pRightChild);

				pParentNode->pRightChild = NULL;

				pMinHeap->currentElementCount--;
			}
		}
		else {
			Count = pMinHeap->currentElementCount;
			pParentNode = pMinHeap->pRootNode;

			while (Count > 3) {
				Count /= 2;
				iLoop++;
			}

			Count = pMinHeap->currentElementCount;

			while (iLoop > 0) {
				int ret = FALSE;

				nodeNum = Count;
				for (int i = 1; i <= iLoop; i++) {
					nodeNum /= 2;
				}

				if (nodeNum % 2 == 0 && pParentNode->pLeftChild != NULL) {
					pParentNode = pParentNode->pLeftChild;
				}
				else if (nodeNum % 2 == 1 && pParentNode->pRightChild != NULL) {
					pParentNode = pParentNode->pRightChild;
				}
				iLoop--;
			}

			if (pParentNode->pRightChild == NULL) {
				temp.key = pParentNode->pLeftChild->key;
				temp.data = pParentNode->pLeftChild->data;


				deleteLinkedHeapNode(pParentNode->pLeftChild);
				pParentNode->pLeftChild = NULL;
			}
			else {
				temp.key = pParentNode->pRightChild->key;
				temp.data = pParentNode->pRightChild->data;

				deleteLinkedHeapNode(pParentNode->pRightChild);
				pParentNode->pRightChild = NULL;
			}

			pMinHeap->currentElementCount--;

			pParentNode = pMinHeap->pRootNode;

			pChildNode = pParentNode->pLeftChild;

			while (pParentNode != NULL) {
				if (pParentNode->pLeftChild != NULL && pParentNode->pRightChild != NULL) {
					if (pParentNode->pLeftChild->key < pParentNode->pRightChild->key) {
						pChildNode = pParentNode->pLeftChild;

						if (temp.key > pChildNode->key) {
							pParentNode->key = pChildNode->key;
							pParentNode->data = pChildNode->data;

							pParentNode = pParentNode->pLeftChild;
						}
						else {
							break;
						}
					}
					else {
						pChildNode = pParentNode->pRightChild;

						if (temp.key > pChildNode->key) {
							pParentNode->key = pChildNode->key;
							pParentNode->data = pChildNode->data;

							pParentNode = pParentNode->pRightChild;
						}
						else {
							break;
						}
					}
				}
				else {
					if (pParentNode->pLeftChild != NULL && pParentNode->pRightChild == NULL) {
						pChildNode = pParentNode->pLeftChild;

						if (temp.key > pChildNode->key) {
							pParentNode->key = pChildNode->key;
							pParentNode->data = pChildNode->data;
						}
						else {
							break;
						}

					}
					else {
						break;
					}
				}
			}
			pParentNode->key = temp.key;
			pParentNode->data = temp.data;

			ret = TRUE;
		}
	}

	return ret;
}

//히프 삭제
void deleteLinkedHeap(LinkedHeap *pHeap){
	if (pHeap != NULL) {
		deleteLinkedHeapNode(pHeap->pRootNode);
		free(pHeap);
	}
}

void deleteLinkedHeapNode(LinkedHeapNode* pNode) {
	if (pNode != NULL) {
		deleteLinkedHeapNode(pNode->pLeftChild);
		deleteLinkedHeapNode(pNode->pRightChild);
		free(pNode);
	}

}

//히프 순회
void displayLinkedHeap(LinkedHeap *pHeap){
	if (pHeap != NULL) {
		displayLinkedHeapNode(pHeap->pRootNode, 0, 'R');
	}
	else {
		printf("트리가 NULL입니다.\n");
	}
}

void displayLinkedHeapNode(LinkedHeapNode *pNode, int level, char type){
	int i = 0;

	for (i = 0; i < level; i++) {
		printf("	");
	}

	if (pNode != NULL) {
		printf("-[%i,%c]%d\n", level, type, pNode->key);

		displayLinkedHeapNode(pNode->pLeftChild, level + 1, 'L');
		displayLinkedHeapNode(pNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}


int pushLSHeapNode(LinkedStack* pStack, LinkedHeapNode* pNode) {
	StackNode node = { 0, };
	node.data = pNode;
	return pushLS(pStack, node);
}
