#include <stdio.h>
#include <string.h>
int main() {

	char a[8] = "���ڿ�";
	char b[8] = "���ڿ�";
	
	if (strcmp(a, b) == 0)
		puts("a�� b�� �����ϴ�.\n");
	else
		puts("a�� b�� ���� �ʽ��ϴ�.\n");

	return 0;
}