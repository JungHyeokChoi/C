#include <stdio.h>

void* add(int a, int b);
void* subtract(int a, int b);
void* multiply(int a, int b);
void* divide(int a, int b);

int main() {
	
	int i = 0, j = 0;
	void* result = NULL;

	printf("두 정수를 입력하세요 : ");
	scanf("%d %d", &i, &j);

	result = add(i, j);
	printf("두 수의 합 : %d\n", *(int*)result);
	result = subtract(i, j);
	printf("두 수의 차 : %d\n", *(int*)result);
	result = multiply(i, j);
	printf("두 수의 곱 : %d\n", *(int*)result);
	result = divide(i, j);
	printf("두 수의 나누기 : %.3lf\n", *(double*)result);

	return 0;
}

void * add(int a, int b)
{
	int result = 0;

	result = a + b;

	return &result;
}

void * subtract(int a, int b)
{
	int result = 0;

	result = a - b;

	return &result;
}

void * multiply(int a, int b)
{
	int result = 0;

	result = a * b;
	
	return &result;
}

void * divide(int a, int b)
{
	double result = 0;

	result = (double)a / (double)b;

	return &result;
}
