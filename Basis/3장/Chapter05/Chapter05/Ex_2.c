#include <stdio.h>

#define ADD

/*
#ifndef ADD
	#define ADD
#endif
*/

int main() {
	int result = 0, num1 = 10, num2 = 30;


	#ifdef ADD
		result = num1 + num2;
		printf("ADD(����) ��� : %d \n\n", result);
	#endif

	return 0;
}