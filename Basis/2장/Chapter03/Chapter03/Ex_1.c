#include <stdio.h>

int main() {

	char c = 'B';
	int num = 10;

	char* cp = NULL;
	int* ip = NULL;

	cp = &c;
	ip = &num;

	*cp = 'A';
	*ip = 20;

	printf("num의 주소 : %x, num의 값 : %d \n", &num, num);
	printf("ip의 값 : %x, ip의 간접 참조 값 : %d \n\n", ip, *ip);
	
	printf("c의 주소 : %x, c의 값 : %c \n", &c, c);
	printf("cp의 값 : %x, cp의 간접 참조 값 : %c \n\n", cp, *cp);

	return 0;
}