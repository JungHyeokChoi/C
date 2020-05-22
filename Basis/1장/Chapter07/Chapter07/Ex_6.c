#include <stdio.h>

int main() {

	int a, b;

	while (1) {

		printf("첫 번쨰 수를 입력해 주세요 : ");
		scanf("%d", &a);

		printf("두 번쨰 수를 입력해 주세요 : ");
		scanf("%d", &b);

		printf("%d + %d = %d입니다.\n", a, b, a + b);

	}

	return 0;
}