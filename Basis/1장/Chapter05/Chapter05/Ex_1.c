#include <stdio.h>

int main(){

	int x, y, z, output = 0;
	
	printf("input x : ");
	scanf("%d", &x);

	printf("input y : ");
	scanf("%d", &y);

	printf("input z : ");
	scanf("%d", &z);

	output = (x + y) * (x + z) / (y % z);

	printf("(x + y) * (x + z) / (y %% z) = %d\n\n", output);

	return 0;
}