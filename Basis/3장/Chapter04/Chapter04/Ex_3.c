#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;
	int* ip = NULL;
	char* cp = NULL;
	float* fp = NULL;

	printf("필요한 메모리 공간 : ");
	scanf("%d", &i);
	printf("저장 데이터 유형 (1)int, (2)char, (3)float : ");
	scanf("%d", &j);
	printf("\n");

	if (j == 1) {
		ip = (int*)calloc(i, sizeof(int));
		printf("메모리 시작 주소 %x \n", ip);
		printf("할당된 전체 메모리 공간 %d Byte\n\n", i * sizeof(int));
		free(ip);
	}
	else if (j == 2) {
		cp = (char*)calloc(i, sizeof(char));
		printf("메모리 시작 주소 %x \n", cp);
		printf("할당된 전체 메모리 공간 %d Byte\n\n", i * sizeof(char));
		free(cp);
	}
	else if (j == 3) {
		fp = (float*)calloc(i, sizeof(float));
		printf("메모리 시작 주소 %x \n", fp);
		printf("할당된 전체 메모리 공간 %d Byte\n\n", i * sizeof(float));
		free(fp);
	}
	else
		printf("잘못된 입력\n\n");
}