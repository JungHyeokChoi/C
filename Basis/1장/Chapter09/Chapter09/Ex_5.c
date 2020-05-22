#include <stdio.h>

int square(int i);
int cube(int i);
int quartic(int i);
int quintic(int i);

int main() {

	int temp = 0;

	printf("A TABLE OF POWERS \n");
	printf("-------------------------------------------------------------------------------\n");
	printf("         INTEGER         SQUARE         CUBE         QUARTIC         QUINTIC \n");
	printf("-------------------------------------------------------------------------------\n");

	for (int k = 1; k <= 3; k++) {
		temp = k;
		printf("               %d", temp);

		temp = square(k);
		printf("              %d", temp);

		temp = cube(k);
		printf("            %d", temp);

		temp = quartic(k);
		printf("               %d", temp);

		temp = quintic(k);
		printf("               %d\n", temp);
	}

	printf("\n");

	return 0;
}

int square(int i) {
	return i * i;
}

int cube(int i) {
	return i * i * i;
}

int quartic(int i) {
	return cube(i) * i;
}

int quintic(int i) {
	return cube(i) * square(i);
}
