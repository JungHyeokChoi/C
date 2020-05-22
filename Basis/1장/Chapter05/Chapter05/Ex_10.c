#include <stdio.h>

int main() {

	const float Cm_Per_Feet = 30.48;
	int height = 0;

	printf("현재 고도(피트) : ");
	scanf("%d", &height);

	printf("현재 고도는 %.2fM 입니다.\n\n", (Cm_Per_Feet*height) / 100);

	return 0;
}