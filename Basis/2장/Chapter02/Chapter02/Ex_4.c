#include <stdio.h>

int main() {

	int array1[4][3] = {23,75,85,12,77,51,25,66,30,19,90,88};
	int array2[4][3] = {11,15,47,74,85,69,57,86,28,90,22,33};
	int sum[4][3] = { 0, };
	int mainus[4][3] = { 0, };


	printf("행렬의 합 \n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			sum[i][j] = array1[i][j] + array2[i][j];

			printf("%d행 %d열의 합 : %d\n", i+1, j+1, sum[i][j]);

		}
	}
	printf("\n");


	printf("행렬의 차 \n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			mainus[i][j] = array1[i][j] - array2[i][j];

			printf("%d행 %d열의 차 : %d\n", i+1, j+1, mainus[i][j]);
		}
	}

	printf("\n");

	return 0;
}
