#include <stdio.h>

int main() {

	char array_1[5] = { 'A','B','C','D','E' };
	int array_2[5] = { 10,20,30,40,50 };
	double array_3[5] = { 10.1,20.2,30.3,40.4,50.5 };

	printf("배열의 주소\n");
	for (int i = 0; i < 5; i++) {
		printf("array_1[%d]의 주소 : %x\n",i,&array_1[i]);
	}
	
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("array_2[%d]의 주소 : %x\n",i, &array_2[i]);
	}

	printf("\n");
	
	for (int i = 0; i < 5; i++) {
		printf("array_3[%d]의 주소 : %x\n",i, &array_3[i]);
	}

	printf("\n\n");

	printf("배열의 실제 값\n");
	for (int i = 0; i < 5; i++) {
		printf("array_1[%d]의 실제 값 : %c\n",i, *&array_1[i]);
	}

	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("array_2[%d]의 실제 값 : %d\n",i, *&array_2[i]);
	}

	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("array_3[%d]의 실제 값 : %.1lf\n",i, *&array_3[i]);
	}

	printf("\n");

	return 0;
}