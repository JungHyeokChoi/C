#ifndef _STATIC_HASING_CHAIN_
#define _STATIC_HASING_CHAIN_

#include "Hashingdef.h"
#include "Hashinglinkedlist.h"

typedef struct HashTableType {
	int bucketSize;
	int currentElementCount;
	struct LinkedListType **ppElement;
}HashTable;

HashTable *createHashTable(int bucketSize); //�ؽ����̺� ����
int addElementSHT(HashTable *pHashTable, HashElement element); //�ڷ� ����
int hashFuction(char *pKey, int bucketSize); //�ּ� ���(������ ����)
unsigned int stringToInt(char *pKey); //���ڿ��� ���ڷ� ��ȯ(ȣ���� ���)
HashElement *searchHT(HashTable *pHashTable, char *pKey); //�ڷ� �˻�
LinkedList *searchBucket(HashTable *pHashTable, char *pKey); // 2���� ������ �˻�
HashElement *searchSlot(LinkedList *pList, char *key, int *pPosition); // 1���� ������ �˻�
int deleteElementHT(HashTable *pHashTable, char *pKey); //�ڷ� ����
int deleteHashTable(HashTable *pHashTable); //�ؽ����̺� ����
void displayHashTable(HashTable *pHashTable); //�ؽ����̺� ���

#endif

#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE	1
#define FALSE	0

#endif
