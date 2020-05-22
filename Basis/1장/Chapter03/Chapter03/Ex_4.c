#include <stdio.h>

int main() {

	int year, month, day;

	printf("연도 : ");
	scanf("%d", &year);

	printf("월 : ");
	scanf("%d", &month);

	printf("일 : ");
	scanf("%d", &day);

	printf("생년월일 : %d%d%d \n\n", year, month, day);

	return 0;
}