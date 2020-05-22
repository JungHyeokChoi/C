#include <stdio.h>

void func(int* k, int(*p)[2]);

int main() {

	int array1[4] = { 10,20,30,40 };
	int array2[2][2] = { 50,60,70,80 };

	func(array1, array2);

	return 0;
}

void func(int* k, int (*p)[2])
{
	for (int i = 0; i < 4; i++)
		printf("%d ", *(k + i));
	printf("\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", *(p[i]+j));
		}
	}
	printf("\n\n");
}
