#include <stdio.h>

void arrinput(int array[], int row_size);

int main() {

	int array[5] = { 10,20,30,40,50 };

	void (*pfunc)(int, int);

	pfunc = arrinput;
	pfunc(array, 5);

	return 0;
}

void arrinput(int array[], int row_size)
{
	for (int i = 0; i < row_size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n\n");
}