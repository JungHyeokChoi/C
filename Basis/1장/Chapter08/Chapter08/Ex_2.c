#include <stdio.h>

int main() {

	int input = 0;
	int i = 0;

	printf("3�ڸ� �������� �Է��ϼ��� : ");
	scanf("%d", &input);

	for (i = 1; ; i++) {
		input = input - 100;

		if (input < 100)
			break;
	}

	if(i % 2 == 0)
		printf("%d : ¦�� ",i);
	else
		printf("%d : Ȧ�� ", i);


	for (i= 1; ; i++) {
		input = input - 10;

		if (input < 10)
			break;
	}

	if (i % 2 == 0)
		printf("%d : ¦�� ", i);
	else
		printf("%d : Ȧ�� ", i);


	if(input % 2 == 0)
		printf("%d : ¦��\n\n", input);
	else
		printf("%d : Ȧ��\n\n", input);

	return 0;
}