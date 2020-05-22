#include <stdio.h>
#include <math.h>

int main() {

	int bin_num_0, bin_num_1, bin_num_2, bin_num_3 = 0;
	int dec_num = 0;


	printf("2^0 : ");
	scanf("%d", &bin_num_0);

	printf("2^1 : ");
	scanf("%d", &bin_num_1);

	printf("2^2 : ");
	scanf("%d", &bin_num_2);

	printf("2^3 : ");
	scanf("%d", &bin_num_3);

	dec_num = bin_num_3 * 8 + bin_num_2 * 4 + bin_num_1 * 2 + bin_num_0 * 1;

	printf("10Áø¼ö : %d\n\n", dec_num);

	return 0;
}