#include <stdio.h>

int main() {

	const float Exchange_Rate = 1123.00;
	int dollar = 0;

	printf("환전 할 금액(달러 -> 원화) : ");
	scanf("%d", &dollar);

	printf("환전 금액 : %.2f \n\n", dollar * Exchange_Rate);

	return 0;
}