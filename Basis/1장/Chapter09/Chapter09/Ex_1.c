#include <stdio.h>

int abs(int);

int main() {

	int input = 0, result = 0;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &input);

	result = abs(input);

	printf("���밪�� : %d�Դϴ�.\n\n", result);

	return 0;
}

int abs(int input) {

	int result = 0;

	if (input < 0) 
		result = -input;
	else
		result = input;

	return result;
}