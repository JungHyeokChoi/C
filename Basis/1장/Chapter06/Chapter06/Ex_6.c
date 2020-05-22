#include <stdio.h>

#define Pi 3.14

int main() {
	float radius = 0,speed_per_hour = 0, finish_time = 0;

	printf("원형 트랙의 반지름(Km) : ");
	scanf("%f", &radius);

	printf("시속(Km/h) : ");
	scanf("%f", &speed_per_hour);

	finish_time = (float)(2 * Pi * radius) / (float)(speed_per_hour / 60) ;

	printf("반지름 %.3f의 원형 트랙을 시속 %.3fKm/h로 완주하는데 걸리는 시간은 %.3f분 입니다. \n\n", radius, speed_per_hour, finish_time);

	return 0;
}