#include <stdio.h>

int main() {

	int input = 0, i;
	double result = 0.00;

	printf("열 과목의 점수의 평균을 계산합니다.\n");

	for (i = 1; i <= 10; i++) {
		printf("점수를 입력해 주세요 : ");
		scanf("%d", &input);

		result = result + input;
	}

	result = result / (i-1);

	printf("열 과목 점수의 평균은 %.1lf점 입니다.\n", result);

	return 0;
}