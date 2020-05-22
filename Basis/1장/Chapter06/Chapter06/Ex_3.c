#include <stdio.h>

int main() {

	int i;
	float f;
	double d;

	i =	'a' + 1.3; //자동 형변환
	f = 2.49 + i;
	d = (double)f*i; //강제 형변환

	return 0;
}