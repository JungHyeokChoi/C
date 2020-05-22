#include <stdio.h>

int main() {
	
	int red = 1, blue = 2;
	int yellow;

	printf("Before \n");
	printf("red = %d, blue = %d \n\n", red, blue);
	
	yellow = red;
	blue = red;
	yellow = blue;

	printf("After \n");
	printf("red = %d, blue = %d \n\n", red, blue);

	return 0;
}