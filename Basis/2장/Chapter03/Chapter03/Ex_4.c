#include <stdio.h>

int main() {

	int num = 10;
	int* ip1 = NULL;
	int** ip2 = NULL;
	int*** ip3 = NULL;

	printf("%d\n", num);

	ip1 = &num;
	*ip1 = 20;

	printf("%d %d\n", num, *ip1);

	ip2 = &ip1;
	**ip2 = 30;

	printf("%d %d %d\n", num, *ip1, **ip2);

	ip3 = &ip2;
	***ip3 = 40;

	printf("%d %d %d %d\n\n", num, *ip1, **ip2, ***ip3);

	return 0;
}