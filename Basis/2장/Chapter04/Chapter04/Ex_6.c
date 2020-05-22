#include <stdio.h>

int main() {

	char* array1 = &"ABCD";
	char array2[] = "ABCD";

	printf("array1 : %s, array2 : %s\n", array1, array2);
	
	array1 = &"XBCD";
	array2[0] = 'X';

	printf("array1 : %s, array2 : %s\n\n", array1, array2);

	return 0;
}