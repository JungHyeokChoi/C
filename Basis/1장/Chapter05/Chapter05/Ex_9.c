#include <stdio.h>

int main() {

	const float Kg_Per_Pound = 0.45;
	int wheat_flour = 0;

	printf("������ �ִ� �а���(�Ŀ��) : ");
	scanf("%d", &wheat_flour);

	printf("������ �ִ� �а���� %.2fKg �Դϴ�.\n\n", Kg_Per_Pound * wheat_flour);

	return 0;
}