#include <stdio.h>

int main() {

	int input = 0, result = 1;

	printf("팩토리얼 연산을 원하는 숫자를 입력하세요 : ");
	scanf("%d", &input);

	for (int i = input; i > 1; i--)
		result = result * i;

	printf("%d의 팩토리얼 연산 결과는 %d입니다.\n", input, result);

	return 0;
}