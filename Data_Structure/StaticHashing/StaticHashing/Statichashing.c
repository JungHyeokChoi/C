#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Statichashing.h"

HashTable *createHashTable(int bucketSize){
	HashTable *pReturn = NULL;
	int i = 0;

	if (bucketSize <= 0) {
		printf("��Ŷ ũ��� 0���� Ŀ�� �մϴ�.\n");
		return NULL;
	}

	pReturn = (HashTable*)malloc(sizeof(HashTable));
	if (pReturn != NULL) {
		pReturn->currentElementCount = 0;
		pReturn->bucketSize = bucketSize;
		pReturn->pElement = NULL;
	}
	else {
		printf("����, �޸� �Ҵ�(1), in createHashTable()\n");
		return NULL;
	}

	pReturn->pElement = (HashElement*)malloc(sizeof(HashElement) * bucketSize);
	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(HashElement) * bucketSize);
	}
	else {
		if (pReturn != NULL) {
			free(pReturn);
		}

		printf("����, �޸� �Ҵ�(2), in createHashTable()\n");
		return NULL;
	}

	return pReturn;
}

int addElementSHT(HashTable *pHashTable, HashElement element){
	int ret = FALSE;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (pHashTable == NULL) {
		printf("HashTable is NULL\n");
		ret = FALSE;
		return ret;
	}

	bucketIndex = hashFuction(element.key, pHashTable->bucketSize);
	if (bucketIndex < 0 || bucketIndex >= pHashTable->bucketSize) {
		printf("����, �߸��� �ؽ� ���̺� �ּҰ� ���Ǿ����ϴ�.\n");
		ret = FALSE;
		return ret;
	}

	tempIndex = bucketIndex;
	do {
		pElement = &(pHashTable->pElement[tempIndex]);
		if (isEmptyOrDeletedBucket(pElement) == TRUE) {
			pHashTable->pElement[tempIndex] = element;
			pHashTable->pElement[tempIndex].status = USED;

			ret = TRUE;
			return ret;
		}
		else {
			if (strcmp(pElement->key, element.key) == 0) {
				printf("����, �ߺ��� Ű - [%s], in addElementSHT()\n", element.key);
				
				ret = FALSE;
				break;
			}
			else {
				tempIndex = (tempIndex + inc) % pHashTable->bucketSize;
				if (tempIndex == bucketIndex) {
					printf("����, �ؽ� ���̺��� ���� á���ϴ�, in addElementSHT()\n");
					ret = FALSE;
					break;
				}
			}
		}
	} while (tempIndex != bucketIndex);

	return ret;
}

int hashFuction(char *pKey, int bucketSize){
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

int isEmptyOrDeletedBucket(HashElement *pElement){
	int ret = FALSE;

	if (pElement != NULL) {
		if (pElement->status == EMPTY
			|| pElement->status == DELETED) {
			ret = TRUE;
		}
	}

	return ret;
}

HashElement *searchHT(HashTable *pHashTable, char *pKey){
	HashElement *pReturn = NULL;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (pHashTable == NULL) {
		printf("HashTable is NULL\n");
		pReturn = NULL;
		return pReturn;
	}

	bucketIndex = hashFuction(pKey, pHashTable->bucketSize);
	if (bucketIndex < 0) {
		printf("����, �߸��� �ؽ� ���̺� �ּҰ� ���Ǿ����ϴ�, in searchHT()\n");
		pReturn = NULL;
		return pReturn;
	}
	tempIndex = bucketIndex;
	do {
		pElement = &(pHashTable->pElement[tempIndex]);
		if (isEmptyBucket(pElement) == TRUE) {
			printf("�˻� ����, �˻� Ű - [%s]�� �������� �ʽ��ϴ�, in searchHT()\n", pKey);
			
			pReturn = NULL;
			return pReturn;
		}
		else {
			if (pElement->status == USED
				&& strcmp(pElement->key, pKey) == 0) {
				
				pReturn = pElement;
				break;
			}
			else {
				tempIndex = (tempIndex + 1) % pHashTable->bucketSize;
				if (tempIndex == bucketIndex) {
					printf("�˻� ����, �˻� Ű - [%s]�� �������� �ʽ��ϴ�, in searchHT()\n", pKey);

					pReturn = NULL;
					return pReturn;
				}
			}
		}
	} while (tempIndex != bucketIndex);

	return pReturn;
}

int isEmptyBucket(HashElement *pElement){
	int ret = FALSE;

	if (pElement != NULL) {
		if (pElement->status == EMPTY) {
			ret = TRUE;
		}
	}
	return ret;
}

int deleteElementHT(HashTable *pHashTable, char *pKey){
	int ret = FALSE;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (pHashTable != NULL) {
		pElement = searchHT(pHashTable, pKey);
		if (pElement != NULL) {
			pElement->status = DELETED;
			pElement->key[0] = '\0';
			pElement->value = 0;
			
			ret = TRUE;
		}
		else {
			printf("���� ����, �˻� Ű - [%s]�� �������� �ʽ��ϴ�, in deleteElementHt()\n",pKey);
		}
	}

	return ret;
}

int deleteHashTable(HashTable *pHashTable){
	int ret = FALSE;
	HashElement *pElement = NULL;

	if (pHashTable != NULL) {
		if (pHashTable->pElement != NULL) {
			free(pHashTable->pElement);
		}
		free(pHashTable);

		ret = TRUE;
	}
	else {
		printf("HashTable is NULL\n");
		return ret;
	}

	return ret;
}

void displayHashTable(HashTable *pHashTable){
	HashElement *pElement = NULL;
	int temp = 0;
	int i = 0;

	if (pHashTable != NULL) {
		for (i = 0; i < pHashTable->bucketSize; i++) {
			pElement = &(pHashTable->pElement[i]);
			if (pElement->status == USED) {
				temp = hashFuction(pElement->key, pHashTable->bucketSize);
				printf("[%d], %s, <%d -> %d>, [%d]\n",i,pElement->key,temp,i, pElement->value);
			}
			else {
				printf("[%d], ������ϴ�.\n", i);
			}
		}
		printf("\n");
	}
}0
