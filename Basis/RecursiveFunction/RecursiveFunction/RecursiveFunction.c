#include <stdio.h>

int main() {
	int i = 0, n = 0, result = 0;

	printf("Input : ");
	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		if (i == 1) {
			result = n;
		}
		else {
			result = result + n;
		}
	}


	printf("Result : %d\n\n", result);
}

