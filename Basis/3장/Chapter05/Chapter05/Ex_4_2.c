#include <stdio.h>
#include "Ex_4.h"

int main() {

	POINT sp;

	printf("�� ���� �Է��ϼ��� : ");
	scanf("%d %d", &sp.x, &sp.y);


	printf("�� : %d �� %d \n\n", add(sp.x, sp.y), subtract(sp.x, sp.y));
	
	return 0;
}