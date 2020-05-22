#include <stdio.h>
#include <ctype.h>

int main() {

	char string[50];
	int lenght = 0;

	printf("알파벳을 입력하세요 : ");
	gets(string);

	lenght = strlen(string);

	for (int i = 0; i < lenght; i++) {
		if (isupper(string[i]))
			string[i] = tolower(string[i]);

		else if (islower(string[i]))
			string[i] = toupper(string[i]);
	}

	printf("문자열의 길이 : %d, 대,소문자 반전 된 문자열 : %s\n\n", lenght, string);

	return 0;
}