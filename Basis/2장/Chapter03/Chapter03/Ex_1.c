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

	printf("num�� �ּ� : %x, num�� �� : %d \n", &num, num);
	printf("ip�� �� : %x, ip�� ���� ���� �� : %d \n\n", ip, *ip);
	
	printf("c�� �ּ� : %x, c�� �� : %c \n", &c, c);
	printf("cp�� �� : %x, cp�� ���� ���� �� : %c \n\n", cp, *cp);

	return 0;
}