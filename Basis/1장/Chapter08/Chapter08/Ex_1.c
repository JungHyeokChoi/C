#include <stdio.h>

int main() {

	int a = 0, b = 0;

	printf("두 개의 정수를 입력하세요 : ");
	scanf("%d %d",&a,&b);

	if (a > b) 
		printf("큰 수는 %d 입니다. \n\n", a);
	
	else if(b < a)
		printf("큰 수는 %d 입니다. \n\n", b);

	else
		printf("두 수는 같습니다.\n\n");

	return 0;
}