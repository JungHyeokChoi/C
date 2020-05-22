#include <stdio.h>

int main() {

	int array1[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			array1[i][j] = (i + 1) * (j + 1);

			printf("%d ", array1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	return 0;
}