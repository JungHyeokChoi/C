#include <stdio.h>

int main() {

	int x, y, z, output = 0;

	printf("input : ");
	scanf("%d", &x);

	printf("input : ");
	scanf("%d", &y);

	printf("input : ");
	scanf("%d", &z);

	output = (x > y) ? x : y;
	output = (output > z) ? output : z;

	printf("Bigger Number : %d \n\n", output);
	
	return 0;
}