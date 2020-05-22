#include <stdio.h>

void Alpha(char c);

int main() {

	char input;

	printf("알파벳을 입력하세요 : ");
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

	printf("입력한 %c는 알파벳 순서로 %d번째 문자입니다.\n",c,result);
}
