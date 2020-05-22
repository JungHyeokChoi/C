#include <stdio.h>
#include <stdlib.h>
#include "Seqsearch.h"
#include "Seqindexsearch.h"

int main(int argc, char *args[]) {
	int values[] = { 10,20,50,60,70,80 };
	int result = FAIL;
	IndexTable *pTable = NULL;

	/*
	result = sequentialSearchNotSorted(values, 6, 30);
	printf("검색 결과 : [%d] - %d\n", result, values[result]);

	result = sequentialSearchAsendingSorted(values, 6, 20);
	printf("검색 결과 : [%d] - %d\n", result, values[result]);
	*/

	pTable = createIndexTable(values, 6, 2);
	result = sequentialIndexSearch(values, 6, pTable, 2, 50);
	printf("검색 결과 : [%d] - %d\n", result, values[result]);

	free(pTable);

	return 0;
}