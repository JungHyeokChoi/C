#include <stdio.h>
#include "Ex_4.h"

int main() {

	POINT sp;

	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &sp.x, &sp.y);


	printf("합 : %d 차 %d \n\n", add(sp.x, sp.y), subtract(sp.x, sp.y));
	
	return 0;
}