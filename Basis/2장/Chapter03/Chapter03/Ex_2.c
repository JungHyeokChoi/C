#include <stdio.h>

int main() {

	int a = 10;
	int b = 20;
	int temp;

	int* p1 = NULL;
	int* p2 = NULL;

	p1 = &a;
	p2 = &b;

	printf("a�� �� : %d, b�� �� : %d\n\n", a, b);

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	printf("a�� �� : %d, b�� �� : %d\n\n", a, b);

	return 0;
}