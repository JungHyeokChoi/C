#include <stdio.h>
#include "Ex_1.h"

int main() {

	int a, b;

	printf("�� ���� �Է��ϼ��� : ");
	scanf("%d %d", &a, &b);

	printf("�� : %d \n�� : %d \n���� : %d \n������ : %lf\n\n", add(a, b), subtraction(a,b), multiply(a,b), divide((double)a, (double)b));

	return 0;
}