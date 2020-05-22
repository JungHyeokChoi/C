#include <stdio.h>

void swap(int** q1, int** q2);

int main() {

	int a = 10, b = 20;
	int *p1 = NULL, *p2 = NULL;

	p1 = &a;
	p2 = &b;

	printf("----------함수 호출 전----------\n");
	printf("a = %d, b = %d \n", a, b);
	printf("*p1 = %d, *p2 = %d \n", *p1, *p2);

	swap(&p1, &p2);

	printf("----------함수 호출 전----------\n");
	printf("a = %d, b = %d \n", a, b);
	printf("*p1 = %d, *p2 = %d \n\n", *p1, *p2);

	return 0;
}

void swap(int** q1, int** q2)
{
	int *temp = NULL;

	temp = *q1;
	*q1 = *q2;
	*q2 = temp;
}
