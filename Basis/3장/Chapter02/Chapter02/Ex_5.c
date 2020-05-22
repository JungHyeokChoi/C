#include <stdio.h>
#include <stdlib.h>

int main() {

	char* string = "12345";
	int a = 0;

	printf("%s\n", string);

	a = atoi(string);

	printf("%d\n\n", a);

	return 0;
}