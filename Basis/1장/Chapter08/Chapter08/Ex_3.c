#include <stdio.h>

int main() {

	int input = 0;

	printf("점수를 입력하세요 : ");
	scanf("%d", &input);

	switch (input) {

		case 100:
		case 99:
		case 98:
		case 97:
		case 96:
		case 95:
		case 94:
		case 93:
		case 92:
		case 91:
		case 90:
			printf("A\n");
			break;

		case 89:
		case 88:
		case 87:
		case 86:
		case 85:
		case 84:
		case 83:
		case 82:
		case 81:
		case 80:
			printf("B\n");
			break;

		default:
			printf("F\n");
			break;
	}

	return 0;
}