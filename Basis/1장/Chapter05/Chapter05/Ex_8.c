#include <stdio.h>

int main() {

	int hour = 0, min = 0, sec = 0;
	int temp = 0;

	printf("���� ���� �Է����ּ��� : ");
	scanf("%d", &hour);

	printf("���� ���� �Է����ּ��� : ");
	scanf("%d", &min);

	printf("���� ���� �Է����ּ��� : ");
	scanf("%d", &sec);

	temp = (3600 * 60 * hour) + (60 * min) + sec;

	printf("00�� 00�� 00�ʺ��� %d�� �������ϴ�. \n\n", temp);

	return 0;
}