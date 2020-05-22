#include <stdio.h>

int main() {

	int i;

	for (i = 7; i > 0; i = i-2) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}

		printf("\n");

		for (int k = 8; k > i; k = k-2) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}