#include <stdio.h>

int plus(int i, int j);
int minus(int i, int j);
int multipy(int i, int j);
double divide(int i, int j);

int main() {

	int a, b;
	int result;
	double result2;

	printf("input two numbers : ");
	scanf("%d %d", &a, &b);

	result = plus(a, b);
	printf("a + b = %d\n", result);

	result = minus(a, b);
	printf("a - b = %d\n", result);

	result = multipy(a, b);
	printf("a * b = %d\n", result);

	result2 = divide(a, b);
	printf("a / b = %lf\n", result2);

	return 0;
}

int plus(int i, int j) {
	int result = 0;

	result = i + j;

	return result;
}

int minus(int i, int j) {
	int result = 0;

	result = i - j;

	return result;
}

int multipy(int i, int j) {
	int result = 0;

	result = i * j;

	return result;
}

double divide(int i, int j) {
	double result = 0;

	result = (double)i / (double)j;

	return result;
}