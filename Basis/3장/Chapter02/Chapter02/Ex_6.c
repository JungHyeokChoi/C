#include <stdio.h>
#include <ctype.h>

int main() {

	char string[50];
	int lenght = 0;

	printf("���ĺ��� �Է��ϼ��� : ");
	gets(string);

	lenght = strlen(string);

	for (int i = 0; i < lenght; i++) {
		if (isupper(string[i]))
			string[i] = tolower(string[i]);

		else if (islower(string[i]))
			string[i] = toupper(string[i]);
	}

	printf("���ڿ��� ���� : %d, ��,�ҹ��� ���� �� ���ڿ� : %s\n\n", lenght, string);

	return 0;
}