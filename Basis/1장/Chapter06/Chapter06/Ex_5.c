#include <stdio.h>

int main() {

	float result;
	int input1, input2;

	printf("input 2 numbers = ");
	scanf("%d %d", &input1, &input2);

	result = (float)input1 / (float)input2;
	printf("³ª´°¼À °á°ú = %.3f \n\n", result);

	return 0;
}