#include <stdio.h>

int main() {

	int input = 0;
	int temp = 1;

	printf("�Է�(���� ����) : ");
	scanf("%d", &input);


	printf("%d�� ��� :",input);
	while (input * temp < 101) {
		printf(" %d", input * temp);

		temp++;
	}

	printf("\n%d�� ��� ���� : %d\n\n", input, temp-1);


	return 0;
}