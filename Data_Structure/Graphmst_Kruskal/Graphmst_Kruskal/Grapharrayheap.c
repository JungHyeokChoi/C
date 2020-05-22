#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grapharrayheap.h"

//배열 히프 생성
ArrayHeap *createArrayHeap(int maxElementCount){
	ArrayHeap *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayHeap*)malloc(sizeof(ArrayHeap));
		if (pReturn != NULL) {
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;

			pReturn->pElement = (HeapNode*)malloc(sizeof(HeapNode)*(maxElementCount+1));

			if (pReturn->pElement == NULL) {
				printf("오류, 메모리 할당(2) createArrayHeap()\n");
				free(pReturn);
				return NULL;
			}

			memset(pReturn->pElement, 0, sizeof(HeapNode)*(maxElementCount+1));
		}
		else {
			printf("오류, 메모리 할당,createArrayList()\n");
		}
	}
	else {
		printf("최대 원소 개수는 0보다 커야 합니다.\n");
	}

	return pReturn;
}

//최소 히프 삽입 연산(중복 포함)
void insertMinHeapAH(ArrayHeap* pHeap, HeapNode element) {
	int i = 0, j = 0;
	int ret = TRUE;

	if (pHeap != NULL) {
		if (pHeap->currentElementCount == pHeap->maxElementCount) {
			printf("오류, 히프가 가득찼습니다(%d),insertMAxHeapAH()\n", pHeap->maxElementCount);
			return;
		}

		pHeap->currentElementCount++;
		i = pHeap->currentElementCount;

		for (j = pHeap->currentElementCount; j > 0; j--) {
			if ((element.fromVertexID == pHeap->pElement[j - 1].toVertexID)
				&& (element.toVertexID == pHeap->pElement[j - 1].fromVertexID)) {

				ret = FALSE;
			}
		}

		if (ret == TRUE) {
			while ((i != 1) && (element.key < pHeap->pElement[i - 1].key)) {
				if (element.key == pHeap->pElement[i - 1].key) {
					if (element.fromVertexID < pHeap->pElement[i - 1].fromVertexID) {
						pHeap->pElement[i] = pHeap->pElement[i - 1];
					}
					else if (element.fromVertexID == pHeap->pElement[i - 1].fromVertexID) {
						if (element.toVertexID < pHeap->pElement[i - 1].toVertexID) {
							pHeap->pElement[i] = pHeap->pElement[i - 1];
						}
					}
				}
				else {
					pHeap->pElement[i] = pHeap->pElement[i - 1];
				}
				i--;
			}
			pHeap->pElement[i] = element;
		}
		else {
			pHeap->currentElementCount--;
		}
		
	}
}

//최소 히프 노드 삭제 연산
HeapNode* deleteMinHeapAH(ArrayHeap* pHeap) {
	HeapNode *pReturn = NULL;
	HeapNode *pTemp = NULL;

	int i = 0;
	int parent = 0, child = 0;

	if (pHeap != NULL && pHeap->currentElementCount > 0) {
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn == NULL) {
			printf("오류, 메모리할당,deleteMinHeapAH()\n");
			return NULL;
		}

		*pReturn = pHeap->pElement[1];

		i = pHeap->currentElementCount;
		pTemp = &(pHeap->pElement[i]);
		pHeap->currentElementCount--;

		parent = 1;
		child = 2;

		while (child <= pHeap->currentElementCount) {
			if ((child < pHeap->currentElementCount)
				&& pHeap->pElement[child].key > pHeap->pElement[child + 1].key) {

				child++;
			}

			if (pTemp->key <= pHeap->pElement[child].key) {
				break;
			}

			pHeap->pElement[parent] = pHeap->pElement[child];
			parent = child;
			child *= 2;
		}
		pHeap->pElement[parent] = *pTemp;
	}

	return pReturn;

}

//히프 삭제
void deleteArrayHeap(ArrayHeap *pHeap){
	if (pHeap != NULL) {
		if (pHeap->pElement != NULL) {
			free(pHeap->pElement);
		}
		free(pHeap);
	}
}

//히프 검색
void displayArrayHeap(ArrayHeap* pHeap) {
	int i = 0;

	if (pHeap != NULL) {
		for (i = 1; i <= pHeap->currentElementCount; i++) {
			printf("(%d.%d) - %d\n"
				, pHeap->pElement[i].fromVertexID
				, pHeap->pElement[i].toVertexID
				, pHeap->pElement[i].key);
		}
	}
}