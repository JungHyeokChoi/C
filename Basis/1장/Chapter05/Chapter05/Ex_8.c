#include <stdio.h>

int main() {

	int hour = 0, min = 0, sec = 0;
	int temp = 0;

	printf("현재 시을 입력해주세요 : ");
	scanf("%d", &hour);

	printf("현재 분을 입력해주세요 : ");
	scanf("%d", &min);

	printf("현재 초을 입력해주세요 : ");
	scanf("%d", &sec);

	temp = (3600 * 60 * hour) + (60 * min) + sec;

	printf("00시 00분 00초부터 %d초 지났습니다. \n\n", temp);

	return 0;
}