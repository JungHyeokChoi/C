#include <stdio.h>

int main() {

	char array_1[5] = { 'A','B','C','D','E' };
	int array_2[5] = { 10,20,30,40,50 };
	double array_3[5] = { 10.1,20.2,30.3,40.4,50.5 };

	printf("�迭�� �ּ�\n");
	for (int i = 0; i < 5; i++) {
		printf("array_1[%d]�� �ּ� : %x\n",i,&array_1[i]);
	}
	
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("array_2[%d]�� �ּ� : %x\n",i, &array_2[i]);
	}

	printf("\n");
	
	for (int i = 0; i < 5; i++) {
		printf("array_3[%d]�� �ּ� : %x\n",i, &array_3[i]);
	}

	printf("\n\n");

	printf("�迭�� ���� ��\n");
	for (int i = 0; i < 5; i++) {
		printf("array_1[%d]�� ���� �� : %c\n",i, *&array_1[i]);
	}

	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("array_2[%d]�� ���� �� : %d\n",i, *&array_2[i]);
	}

	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("array_3[%d]�� ���� �� : %.1lf\n",i, *&array_3[i]);
	}

	printf("\n");

	return 0;
}