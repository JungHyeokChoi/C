#include <stdio.h>

int main() {

	int array[5] = { 10,20,30,40,50 };
	int* p = NULL;

	p = NULL;
	p = array;

	printf("%d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]);
	printf("%d %d %d %d %d\n\n", *(p + 0), *(p + 1), *(p + 2), *(p + 3), *(p + 4));
}