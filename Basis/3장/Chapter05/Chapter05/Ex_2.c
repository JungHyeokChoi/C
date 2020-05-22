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
		printf("ADD(µ¡¼À) °á°ú : %d \n\n", result);
	#endif

	return 0;
}