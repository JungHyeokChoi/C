#include <stdio.h>
#include <string.h>
int main() {

	char a[8] = "문자열";
	char b[8] = "문자열";
	
	if (strcmp(a, b) == 0)
		puts("a와 b는 같습니다.\n");
	else
		puts("a와 b는 같지 않습니다.\n");

	return 0;
}