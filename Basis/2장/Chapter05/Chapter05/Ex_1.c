#include <stdio.h>

void func(char c, char* p, int i, double j);

int main() {

	char c = 'A';
	char* str = "ABCD";
	int num1 = 10;
	double num2 = 3.14;

	func(c, str, num1, num2);

	return 0;
}


void func(char c, char* str, int i, double j)
{
	printf("%c %s %d %lf\n\n", c, str, i, j);
}

