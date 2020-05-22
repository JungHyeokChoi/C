#include <stdio.h>
#include <stdlib.h>

void allocate(int i);

int main() {

	int i;

	printf("필요한 메모리 공간 : ");
	scanf("%d", &i);
	allocate(i);

	return 0;
}

void allocate(int i)
{
	int* p = (int*)malloc(i*sizeof(int));

	if(p == NULL)
		printf("힙 영역에 동작 메모리 할당 실패 \n");
	
	else {
		printf("\n%d의 공간을 할당 \n\n", i);

		for (int iLoop = 0; iLoop < i; iLoop++) {
			p[iLoop] = 10 * (iLoop + 1);
			printf("할당된 p[%d]의 주소 / 값 : %x / %d \n", iLoop, (p + iLoop),p[iLoop]);
		}
	}
	free(p);

	printf("\n공간 할당 해제 후 \n\n");
	
	for (int iLoop = 0; iLoop < i; iLoop++) {
		printf("할당된 p[%d]의 주소 / 값 : %x / %d \n", iLoop, (p + iLoop), p[iLoop]);
	}
	
	printf("\n");
}
