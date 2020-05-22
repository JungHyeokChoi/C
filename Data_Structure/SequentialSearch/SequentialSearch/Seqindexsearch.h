#ifndef _SEQUENTIAL_INDEX_SEARCH_
#define _SEQUENTIAL_INDEX_SEARCH_

typedef struct IndexTableTyep {
	int position;
	int key;
}IndexTable;

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key); //���� ���� �˻�
int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key); //���� �˻�
IndexTable* createIndexTable(int value[], int size, int indexSize); //���� ����

#endif

#ifndef _COMMON_SEARCH_DEF_
#define _COMMON_SEARCH_DEF_

#define	FAIL	-1

#endif