#include <stdio.h>

int main() {

	int input = 0;
	int gugudan[9] = { 0, };

	printf("���ڸ� �Է��ϼ���. : ");
	scanf("%d", &input);

	for (int i = 0; i < 9; i++) {
		gugudan[i] = input * (i + 1);
		printf("%d * %d = %d \n", input, i + 1, gugudan[i]);
	}

	printf("\n");

	return 0;
}