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

HashTable *createHashTable(int bucketSize); //해시테이블 생성
int addElementSHT(HashTable *pHashTable, HashElement element); //자료 저장
int hashFuction(char *pKey, int bucketSize); //주소 계산(나머지 연산)
unsigned int stringToInt(char *pKey); //문자열을 숫자로 변환(호너의 방법)
int isEmptyOrDeletedBucket(HashElement *pElement); //상태 확인
HashElement *searchHT(HashTable *pHashTable, char *pKey); //자료 검색
int isEmptyBucket(HashElement *pElement); //상태 확인
int deleteElementHT(HashTable *pHashTable, char *pKey); //자료 삭제
int deleteHashTable(HashTable *pHashTable); //해시테이블 삭제
void displayHashTable(HashTable *pHashTable); //해시테이블 출력

#endif


#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE	1
#define FALSE	-1

#endif