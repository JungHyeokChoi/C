#include <stdio.h>

void Alpha(char c);

int main() {

	char input;

	printf("���ĺ��� �Է��ϼ��� : ");
	scanf("%c", &input);

	Alpha(input);
	printf("\n");

	return 0;
}

void Alpha(char c)
{
	int result = 0;

	if (c >= 65 && c <= 90)
		result = c - 64;

	if (c >= 97 && c <= 122)
		result = c - 96;

	printf("�Է��� %c�� ���ĺ� ������ %d��° �����Դϴ�.\n",c,result);
}
