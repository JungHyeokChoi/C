#include <stdio.h>

int main() {

	const float Cm_Per_Feet = 30.48;
	int height = 0;

	printf("���� ��(��Ʈ) : ");
	scanf("%d", &height);

	printf("���� ���� %.2fM �Դϴ�.\n\n", (Cm_Per_Feet*height) / 100);

	return 0;
}