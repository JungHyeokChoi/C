#include <stdio.h>

int main() {

	int input = 0, i;
	double result = 0.00;

	printf("�� ������ ������ ����� ����մϴ�.\n");

	for (i = 1; i <= 10; i++) {
		printf("������ �Է��� �ּ��� : ");
		scanf("%d", &input);

		result = result + input;
	}

	result = result / (i-1);

	printf("�� ���� ������ ����� %.1lf�� �Դϴ�.\n", result);

	return 0;
}