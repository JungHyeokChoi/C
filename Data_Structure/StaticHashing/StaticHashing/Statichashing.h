#ifndef _STATIC_HASING_DEF_
#define _STATIC_HASING_DEF_

#define HASH_KEY_SIZE	30

typedef enum HashElementStatusType {
	EMPTY = 0, USED, DELETED
}HashElementStatus;

typedef struct HashElementType {
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;
}HashElement;

typedef struct HashTableType {
	int bucketSize;
	int currentElementCount;
	HashElement *pElement;
}HashTable;

HashTable *createHashTable(int bucketSize); //�ؽ����̺� ����
int addElementSHT(HashTable *pHashTable, HashElement element); //�ڷ� ����
int hashFuction(char *pKey, int bucketSize); //�ּ� ���(������ ����)
unsigned int stringToInt(char *pKey); //���ڿ��� ���ڷ� ��ȯ(ȣ���� ���)
int isEmptyOrDeletedBucket(HashElement *pElement); //���� Ȯ��
HashElement *searchHT(HashTable *pHashTable, char *pKey); //�ڷ� �˻�
int isEmptyBucket(HashElement *pElement); //���� Ȯ��
int deleteElementHT(HashTable *pHashTable, char *pKey); //�ڷ� ����
int deleteHashTable(HashTable *pHashTable); //�ؽ����̺� ����
void displayHashTable(HashTable *pHashTable); //�ؽ����̺� ���

#endif


#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE	1
#define FALSE	-1

#endif