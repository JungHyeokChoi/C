#include <stdio.h>

int main() {
	int a, b;

	printf("두 정수를 입력하세요 : ");
	scanf("%d %d", &a, &b);

	printf("합 : %d + %d = %d\n",a,b,a+b);
	printf("차 : %d - %d = %d\n\n", a, b, a-b);

	return 0;
}