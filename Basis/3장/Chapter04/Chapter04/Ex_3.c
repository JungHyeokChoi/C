#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;
	int* ip = NULL;
	char* cp = NULL;
	float* fp = NULL;

	printf("�ʿ��� �޸� ���� : ");
	scanf("%d", &i);
	printf("���� ������ ���� (1)int, (2)char, (3)float : ");
	scanf("%d", &j);
	printf("\n");

	if (j == 1) {
		ip = (int*)calloc(i, sizeof(int));
		printf("�޸� ���� �ּ� %x \n", ip);
		printf("�Ҵ�� ��ü �޸� ���� %d Byte\n\n", i * sizeof(int));
		free(ip);
	}
	else if (j == 2) {
		cp = (char*)calloc(i, sizeof(char));
		printf("�޸� ���� �ּ� %x \n", cp);
		printf("�Ҵ�� ��ü �޸� ���� %d Byte\n\n", i * sizeof(char));
		free(cp);
	}
	else if (j == 3) {
		fp = (float*)calloc(i, sizeof(float));
		printf("�޸� ���� �ּ� %x \n", fp);
		printf("�Ҵ�� ��ü �޸� ���� %d Byte\n\n", i * sizeof(float));
		free(fp);
	}
	else
		printf("�߸��� �Է�\n\n");
}