#include <stdio.h>

void fibo(int n);

int main() {

	fibo(12);

	return 0;
}

void fibo(int input) {

	int a = 1, b = 1,temp = 0;

	for (int i = 1; i <= input; i++) {

		if (i == 1 || i == 2) {
			printf("1 ");

		}
	
		else{
			temp = a + b;
			printf("%d ", temp);
			a = b;
			b = temp;
		}
	}
}