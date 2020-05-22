#include <stdio.h>

void swap(int* a, int* b);

int main() {

	int i = 10, j = 20;

	printf("main() : i = %d, j = %d \n", i, j);
	swap(&i, &j);
	printf("main() : i = %d, j = %d \n\n", i, j);

	return 0;
}

void swap(int * a, int * b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
