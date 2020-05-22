#include <stdio.h>

int main() {

	char temp[7] = "ABC";

	temp[3] = temp[2];
	temp[4] = temp[1];
	temp[5] = temp[0];

	printf("%s", temp);

	return 0;
}