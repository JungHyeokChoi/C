#include <stdio.h>

int main() {

	const float Exchange_Rate = 1123.00;
	int dollar = 0;

	printf("ȯ�� �� �ݾ�(�޷� -> ��ȭ) : ");
	scanf("%d", &dollar);

	printf("ȯ�� �ݾ� : %.2f \n\n", dollar * Exchange_Rate);

	return 0;
}