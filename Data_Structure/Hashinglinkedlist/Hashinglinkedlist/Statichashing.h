#ifndef _STATIC_HASING_CHAIN_
#define _STATIC_HASING_CHAIN_

#include "Hashingdef.h"
#include "Hashinglinkedlist.h"

typedef struct HashTableType {
	int bucketSize;
	int currentElementCount;
	struct LinkedListType **ppElement;
}HashTable;

HashTable *createHashTable(int bucketSize); //해시테이블 생성
int addElementSHT(HashTable *pHashTable, HashElement element); //자료 저장
int hashFuction(char *pKey, int bucketSize); //주소 계산(나머지 연산)
unsigned int stringToInt(char *pKey); //문자열을 숫자로 변환(호너의 방법)
HashElement *searchHT(HashTable *pHashTable, char *pKey); //자료 검색
LinkedList *searchBucket(HashTable *pHashTable, char *pKey); // 2차원 포인터 검색
HashElement *searchSlot(LinkedList *pList, char *key, int *pPosition); // 1차원 포인터 검색
int deleteElementHT(HashTable *pHashTable, char *pKey); //자료 삭제
int deleteHashTable(HashTable *pHashTable); //해시테이블 삭제
void displayHashTable(HashTable *pHashTable); //해시테이블 출력

#endif

#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE	1
#define FALSE	0

#endif
