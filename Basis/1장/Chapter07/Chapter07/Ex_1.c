#include <stdio.h>

int main() {

	int input = 0;
	int temp = 1;

	printf("입력(양의 정수) : ");
	scanf("%d", &input);


	printf("%d의 배수 :",input);
	while (input * temp < 101) {
		printf(" %d", input * temp);

		temp++;
	}

	printf("\n%d의 배수 개수 : %d\n\n", input, temp-1);


	return 0;
}