#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Statichashing.h"
#include "Hashinglinkedlist.h"

HashTable *createHashTable(int bucketSize){
	HashTable *pReturn = NULL;
	int i = 0, j = 0;

	if (bucketSize <= 0) {
		printf("버킷 크기는 0보다 커야 합니다.\n");
		return NULL;
	}

	pReturn = (HashTable*)malloc(sizeof(HashTable));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(HashTable));
		pReturn->bucketSize = bucketSize;
	}
	else {
		printf("오류, 메모리 할당(1), in createHashTable()\n");
		return NULL;
	}

	pReturn->ppElement = (LinkedList**)malloc(sizeof(LinkedList*) * bucketSize);
	if (pReturn->ppElement != NULL) {
		memset(pReturn->ppElement, 0, sizeof(LinkedList*) * bucketSize);
		for (i = 0; i < bucketSize; i++) {
			pReturn->ppElement[i] = createLinkedList();

			if (pReturn->ppElement[i] == NULL) {
				printf("오류, 메모리 할당(3), in createHashTable()\n");
				for (j = 0; j < bucketSize; j++) {
					if (pReturn->ppElement[j] != NULL) free(pReturn->ppElement[j]);
				}
				
				if (pReturn->ppElement != NULL) free(pReturn->ppElement);
				if (pReturn != NULL) free(pReturn);

				return NULL;
			}
		}
	}
	else {
		if (pReturn != NULL) {
			free(pReturn);
		}

		printf("오류, 메모리 할당(2), in createHashTable()\n");
		return NULL;
	}

	return pReturn;
}

int addElementSHT(HashTable *pHashTable, HashElement element){
	int ret = FALSE;
	LinkedList *pList = NULL;

	if (pHashTable != NULL) {
		pList = searchBucket(pHashTable, element.key);
		if (pList != NULL) {
			addLLElementLast(pList, element);
			pHashTable->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, in addElementSHT()\n");
		}
	}
	
	return ret;
}

int hashFuction(char *pKey, int bucketSize) {
	int ret = FALSE;
	unsigned int temp_key = 0;

	if (pKey == NULL) {
		return ret;
	}

	temp_key = stringToInt(pKey);
	if (bucketSize > 0) {
		ret = temp_key % bucketSize;
	}

	return ret;
}

unsigned int stringToInt(char *pKey){
	unsigned int ret = 0;

	while (*pKey != '\0') {
		ret = (ret * 31) + (*pKey);
		*pKey++;
	}

	return ret;
}

HashElement *searchHT(HashTable *pHashTable, char *pKey){
	HashElement *pReturn = NULL;
	LinkedList * pList = NULL;
	int position = 0;

	pList = searchBucket(pHashTable, pKey);
	if (pList != NULL) {
		pReturn = searchSlot(pList, pKey, &position);
	}

	return pReturn;
}

LinkedList *searchBucket(HashTable *pHashTable, char *pKey){
	LinkedList *pReturn = NULL;
	int bucketIndex = 0;

	if (pHashTable != NULL) {
		bucketIndex = hashFuction(pKey, pHashTable->bucketSize);
		if (bucketIndex >= 0) {
			pReturn = pHashTable->ppElement[bucketIndex];
		}
		else {
			printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, in searchBucket()\n");
		}
	}
	return pReturn;
}

HashElement *searchSlot(LinkedList *pList, char *key, int *pPosition){
	HashElement *pReturn = NULL;
	HashElement *pElement = NULL;
	ListNode *pNode = NULL;
	int position = 0;

	if (pList != NULL && pPosition != NULL) {
		pNode = getLLElement(pList, 0);
		while (pNode != NULL) {
			if (strcmp(pNode->data.key, key) == 0) {
				pReturn = &(pNode->data);
				*pPosition = position;
				break;
;			}
			pNode = pNode->pLink;
			position++;
		}
		if (pReturn == NULL) {
			printf("검색 실패, 검색 키 - [%s]는 존재하지 않습니다, in searchSlot()\n",key);
		}
	}

	return pReturn;
}

int deleteElementHT(HashTable *pHashTable, char *pKey){
	int ret = FALSE;
	HashElement *pElement = NULL;
	LinkedList *pList = NULL;
	int position = 0;

	pList = searchBucket(pHashTable, pKey);
	if (pList != NULL) {
		pElement = searchSlot(pList, pKey, &position);
		if (pElement != NULL) {
			removeLLElement(pList, position);
			pHashTable->currentElementCount--;
			ret = TRUE;
		}
	}

	return ret;
}

int deleteHashTable(HashTable *pHashTable) {
	int ret = FALSE;
	int i = 0;
	LinkedList *pList = NULL;
	ListNode *pDelNode = NULL;

	if (pHashTable != NULL) {
		for (i = 0; i < pHashTable->bucketSize; i++) {
			pList = pHashTable->ppElement[i];
			if (pList != NULL) {
				deleteLinkedList(pList);
			}
		}
		free(pHashTable);

		ret = TRUE;
	}
	else {
		printf("HashTable is NULL\n");
	}

	return ret;
}

void displayHashTable(HashTable *pHashTable){
	int i = 0;
	int temp = 0;
	LinkedList *pList = NULL;
	ListNode *pNode = NULL;

	if (pHashTable != NULL) {
		for (i = 0; i < pHashTable->bucketSize; i++) {
			pList = pHashTable->ppElement[i];
			if (pList != NULL) {
				pNode = pList->headerNode.pLink;
				if (pNode != NULL) {
					while (pNode != NULL) {
						printf("[%d], %s, [%d]\n", i, pNode->data.key, pNode->data.value);
						pNode = pNode->pLink;
					}
				}
				else {
					printf("[%d], 비었습니다.\n", i);
				}
			}
			printf("\n");
		}
	}
}
