#include <stdio.h>

int getArea(int x, int y);

int main() {

	int a = 0, b = 0;
	int result = 0;

	printf("�غ� ���� : ");
	scanf("%d", &a);

	printf("���� : ");
	scanf("%d", &b);

	result = getArea(a, b);

	printf("�簢���� ���̴� %d�Դϴ�.\n\n", result);

	return 0;
}

int getArea(int x, int y) {

	return x * y;
}