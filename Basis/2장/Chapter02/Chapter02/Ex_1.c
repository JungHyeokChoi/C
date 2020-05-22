#include <stdio.h>

int main() {

	int array1[2][4] = {1,2,3,4,5,6,7,8};
	int array2[4][2] = {0, };

	for(int i = 0; i < 4; i++)
		printf("%d ", array1[0][i]);

	printf("\n");

	for (int i = 0; i < 4; i++)
		printf("%d ", array1[1][i]);

	printf("\n\n");

	for (int j = 0; j < 4; j++) {
		array2[j][0] = array1[1][j];
		array2[j][1] = array1[0][j];

		printf("%d %d\n", array2[j][0],array2[j][1]);
	}

	return 0;
}