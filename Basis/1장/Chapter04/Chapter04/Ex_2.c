#include <stdio.h>

int main() {

	const int Year = 2010;
	const int My_Old = 20;
	const int Bro_Old = 18;

	printf("���ش� %d�� �Դϴ�.\n", Year);
	printf("�� ���̴� %d�� �Դϴ�.\n", My_Old);
	printf("���� %d�⿡ �¾ %d��° �ذ� �Ǿ����ϴ�.\n", Year - My_Old, My_Old);
	printf("�� ������ ���̴� %d�� �Դϴ�.\n", Bro_Old);
	printf("�� ������ %d�⿡ �¾ %d��° �ذ� �Ǿ����ϴ�.\n\n", Year - Bro_Old, Bro_Old);

	return 0;
}