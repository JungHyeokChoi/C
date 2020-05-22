#include <stdio.h>

int main() {

	const float Kg_Per_Pound = 0.45;
	int wheat_flour = 0;

	printf("가지고 있는 밀가루(파운드) : ");
	scanf("%d", &wheat_flour);

	printf("가지고 있는 밀가루는 %.2fKg 입니다.\n\n", Kg_Per_Pound * wheat_flour);

	return 0;
}