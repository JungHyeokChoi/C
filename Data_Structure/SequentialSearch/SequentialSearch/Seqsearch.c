#include <stdio.h>
#include <stdlib.h>
#include "Seqsearch.h"

int sequentialSearchNotSorted(int value[], int size, int key) {
	int ret = FAIL;
	int i = 0;

	for (i = 0; i < size && value[i] != key; i++) {
		//do nothing
	}

	if (i < size) {
		ret = i;
	}

	return ret;
}

int sequentialSearchAsendingSorted(int value[], int size, int key) {
	int ret = FAIL;
	int i = 0;

	for (i = 0; i < size && value[i] < key; i++) {
		//do nothing
	}

	if (i < size && value[i] == key) {
		ret = i;
	}

	return ret;
}
