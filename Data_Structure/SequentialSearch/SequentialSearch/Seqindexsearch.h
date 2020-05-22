#ifndef _SEQUENTIAL_INDEX_SEARCH_
#define _SEQUENTIAL_INDEX_SEARCH_

typedef struct IndexTableTyep {
	int position;
	int key;
}IndexTable;

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key); //색인 순차 검색
int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key); //순차 검색
IndexTable* createIndexTable(int value[], int size, int indexSize); //색인 생성

#endif

#ifndef _COMMON_SEARCH_DEF_
#define _COMMON_SEARCH_DEF_

#define	FAIL	-1

#endif