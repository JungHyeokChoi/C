#include <stdio.h>

int main() {

	int input = 0, result = 1;

	printf("���丮�� ������ ���ϴ� ���ڸ� �Է��ϼ��� : ");
	scanf("%d", &input);

	for (int i = input; i > 1; i--)
		result = result * i;

	printf("%d�� ���丮�� ���� ����� %d�Դϴ�.\n", input, result);

	return 0;
}