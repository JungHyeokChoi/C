#include <stdio.h>

int main() {

	int input = 0;

	printf("숫자를 입력하세요 : ");
	scanf("%d", &input);

	for (int i = 0; i <= 9; i++) {
		printf("%d * %d = %d 입니다.\n", input, i, input*i);
	}

	return 0;
}