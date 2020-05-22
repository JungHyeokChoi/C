#include <stdio.h>

int getArea(int x, int y);

int main() {

	int a = 0, b = 0;
	int result = 0;

	printf("밑변 길이 : ");
	scanf("%d", &a);

	printf("높이 : ");
	scanf("%d", &b);

	result = getArea(a, b);

	printf("사각형의 넓이는 %d입니다.\n\n", result);

	return 0;
}

int getArea(int x, int y) {

	return x * y;
}