#include <stdio.h>
#include <stdlib.h>

int main() {

	char string[20] = "ABCDEFG";

	puts(string);

	strrev(string);

	puts(string);

	return 0;
}