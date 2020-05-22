#include <stdio.h>

int main() {

	int score_1[5] = { 90,78,77,98,98 };
	int score_2[5] = { 80,45,67,88,57 };
	int score_3[5] = { 88,99,65,55,74 };

	int result = 0, result_1 = 0, result_2 = 0;

	for (int i = 0; i < 5; i++) {
		result = score_1[i] + score_2[i] + score_3[i];
		printf("%d열의 합 : %d\n", i+1,result);
	}
	
	printf("\n");

	for (int i = 0; i < 5; i++) {
		result = result + score_1[i];
		result_1 = result_1 + score_2[i];
		result_2 = result_2 + score_3[i];

	}

	printf("1행의 합 : %d\n", result);
	printf("2행의 합 : %d\n", result_1);
	printf("3행의 합 : %d\n\n", result_2);

	printf("총 합 : %d\n\n", result + result_1 + result_2);

	return 0;
}