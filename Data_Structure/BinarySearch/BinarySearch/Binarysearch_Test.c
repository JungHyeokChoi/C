#include <stdio.h>
#include <stdlib.h>
#include "Binarysearch.h"

int main(int argc, char *args[]) {
	int values[] = { 10,20,50,60,70,80 };
	int result = 0;

	result = binarySearchRecursive(values, 0, 5, 60);
	printf("검색 결과 : [%d] - %d\n", result, values[result]);

	result = binarySearch(values, 0, 5, 20);
	printf("검색 결과 : [%d] - %d\n", result, values[result]);

	return 0;
}