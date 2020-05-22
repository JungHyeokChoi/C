#include <stdio.h>

int main() {

	int x, y, output = 0;

	printf("input : ");
	scanf("%d", &x);

	printf("input : ");
	scanf("%d", &y);

	output = (x < y) ? x : y;

	printf("Smaller Number = %d \n\n", output);

	return 0;
}