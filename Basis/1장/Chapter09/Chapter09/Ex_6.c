#include <stdio.h>

void Add(int i, int j);
int Count();

int count;

int main() {

	int a = 0, b = 0;
	int temp = 0;

	while (1) {
		printf("���� �� ���� �Է��ϼ���.(0 0 -> Exit) : ");
		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0 || count >= 100)
			break;

		Add(a, b);
		Count();
	}

	printf("�� ���� �� : %d \n", count);
	
	
	return 0;
}

void Add(int i, int j)
{
	printf("���� ��� : %d\n",i+j);
}

int Count()
{	
	count++;

	return count;
}
