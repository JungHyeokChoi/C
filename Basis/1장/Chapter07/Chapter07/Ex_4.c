#include <stdio.h>

int main() {

	int input = 0;

	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &input);

	for (int i = 0; i <= 9; i++) {
		printf("%d * %d = %d �Դϴ�.\n", input, i, input*i);
	}

	return 0;
}