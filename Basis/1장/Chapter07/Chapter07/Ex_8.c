#include <stdio.h>

int main() {

	int input = 0, result = 0;

	while (1) {
		printf("������ �Է��� �ּ��� : ");
		scanf("%d", &input);

		result = result + input;

		if (input == 0)
			break;
	}

	printf("�Է��� ������ ������ % d�Դϴ�. \n", result);

	return 0;
}