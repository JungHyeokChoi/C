#include <stdio.h>

int main() {

	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0)
			continue;
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}