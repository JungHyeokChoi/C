#include <stdio.h>

int main() {

	int a = 0, b = 0, c = 0;

	printf("input : ");
	scanf("%d", &a);

	printf("input : ");
	scanf("%d", &b);

	printf("input : ");
	scanf("%d", &c);

	if ((a > b) ? a : b) {
		if (a > c) {
			printf("resutl : %d\n\n",a);
		}
		else if(a < c){
			printf("resutl : %d\n\n", c);
		}
		else
			printf("resutl : %d\n\n", a);
	}

	else if ((b > c) ? b : c) {
		if (b > c) {
			printf("resutl : %d\n\n", b);
		}
		else if (b < c) {
			printf("resutl : %d\n\n", c);
		}
		else
			printf("resutl : %d\n\n", b);
	}

	else
		printf("resutl : %d\n\n", a);

	return 0;
}