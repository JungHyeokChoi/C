#include <stdio.h>

#define Pi 3.14

int main() {
	float radius = 0,speed_per_hour = 0, finish_time = 0;

	printf("���� Ʈ���� ������(Km) : ");
	scanf("%f", &radius);

	printf("�ü�(Km/h) : ");
	scanf("%f", &speed_per_hour);

	finish_time = (float)(2 * Pi * radius) / (float)(speed_per_hour / 60) ;

	printf("������ %.3f�� ���� Ʈ���� �ü� %.3fKm/h�� �����ϴµ� �ɸ��� �ð��� %.3f�� �Դϴ�. \n\n", radius, speed_per_hour, finish_time);

	return 0;
}