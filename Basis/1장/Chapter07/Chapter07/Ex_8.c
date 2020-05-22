#include <stdio.h>

int main() {

	int input = 0, result = 0;

	while (1) {
		printf("정수를 입력해 주세요 : ");
		scanf("%d", &input);

		result = result + input;

		if (input == 0)
			break;
	}

	printf("입력한 정수의 총합은 % d입니다. \n", result);

	return 0;
}