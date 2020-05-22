#include <stdio.h>

void shift(int* p,int k);

int main() {

	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	int row_size = 0;

	row_size = sizeof(array) / sizeof(int);

	printf("실행 전 : ");
	for (int i = 0; i < row_size; i++)
		printf("%d ", array[i]);
	printf("\n");

	shift(array, row_size);

	printf("실행 후 : ");
	for (int i = 0; i < row_size; i++)
		printf("%d ", array[i]);
	printf("\n\n");

	return 0;
}

void shift(int* p,int k)
{
	int temp = 0;

	for (int i = 0; i < k-1; i++) {
		if (i == 0) {
			temp = p[i+1];
			p[i+1] = p[i];
			p[i] = temp;
		}
		else {
			temp = p[i+1];
			p[i+1] = p[0];
			p[0] = temp;
		}
		
	}
}
