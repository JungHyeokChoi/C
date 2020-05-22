#include <stdio.h>

int main() {
	int r;
	double pi = 3.14;

	printf("반지름을 입력하세요 : ");
	scanf("%d", &r);

	printf("원의 넓이는 %f입니다. \n\n",r*r*pi);

	return 0;
}