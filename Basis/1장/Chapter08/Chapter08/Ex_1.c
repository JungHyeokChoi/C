#include <stdio.h>

int main() {

	int a = 0, b = 0;

	printf("�� ���� ������ �Է��ϼ��� : ");
	scanf("%d %d",&a,&b);

	if (a > b) 
		printf("ū ���� %d �Դϴ�. \n\n", a);
	
	else if(b < a)
		printf("ū ���� %d �Դϴ�. \n\n", b);

	else
		printf("�� ���� �����ϴ�.\n\n");

	return 0;
}