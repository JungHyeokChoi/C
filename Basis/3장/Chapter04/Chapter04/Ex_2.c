#include <stdio.h>
#include <stdlib.h>

void allocate(int i);

int main() {

	int i;

	printf("�ʿ��� �޸� ���� : ");
	scanf("%d", &i);
	allocate(i);

	return 0;
}

void allocate(int i)
{
	int* p = (int*)malloc(i*sizeof(int));

	if(p == NULL)
		printf("�� ������ ���� �޸� �Ҵ� ���� \n");
	
	else {
		printf("\n%d�� ������ �Ҵ� \n\n", i);

		for (int iLoop = 0; iLoop < i; iLoop++) {
			p[iLoop] = 10 * (iLoop + 1);
			printf("�Ҵ�� p[%d]�� �ּ� / �� : %x / %d \n", iLoop, (p + iLoop),p[iLoop]);
		}
	}
	free(p);

	printf("\n���� �Ҵ� ���� �� \n\n");
	
	for (int iLoop = 0; iLoop < i; iLoop++) {
		printf("�Ҵ�� p[%d]�� �ּ� / �� : %x / %d \n", iLoop, (p + iLoop), p[iLoop]);
	}
	
	printf("\n");
}
