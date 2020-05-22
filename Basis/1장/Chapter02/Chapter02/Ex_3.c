#include <stdio.h>

int main() {
	int a, b;
	
	printf("가로 길이를 입력하세요 : ");
	scanf("%d", &a);

	printf("세로 길이를 입력하세요 : ");
	scanf("%d", &b);

	printf("직사각형의 넓이는 %d입니다.\n\n",a*b);

	return 0;
}