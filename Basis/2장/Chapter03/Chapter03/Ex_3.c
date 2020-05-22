#include <stdio.h>

int main() {

	int num = 10;
	int* ip1 = NULL;
	int** ip2 = NULL;
	int*** ip3 = NULL;

	ip1 = &num;
	ip2 = &ip1;
	ip3 = &ip2;

	printf("-------------------------------------------------------------------------------\n");
	printf(" 변수 이름	  자기 주소		  값		   간접 참조 값\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("   num		   %x		  %d			%d\n", &num, num, num);
	printf("   ip1		   %x		  %x		%d\n", &ip1, ip1, *ip1);
	printf("   ip2		   %x		  %x		%d\n", &ip2, ip2, **ip2);
	printf("   ip3		   %x		  %x		%d\n", &ip3, ip3, ***ip3);
	printf("-------------------------------------------------------------------------------\n\n");

	return 0;
}