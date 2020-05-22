#include <stdio.h>

int main() {

	double temp = 0.00;

	double temp_1[5] = { 2.2,3.5,2.5,10.1,4.0 };
	double temp_2[5] = { 3.3,2.0,4.0,1.0,2.5 };

	for (int i = 0; i < 5; i++) {
		temp = temp_1[i] * temp_2[i];

		printf("%d¿­ÀÇ °ö : %.3lf\n", i + 1, temp);
	}

	printf("\n");

	return 0;
}