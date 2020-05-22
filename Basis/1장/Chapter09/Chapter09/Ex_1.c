#include <stdio.h>

int abs(int);

int main() {

	int input = 0, result = 0;

	printf("정수를 입력하세요 : ");
	scanf("%d", &input);

	result = abs(input);

	printf("절대값은 : %d입니다.\n\n", result);

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