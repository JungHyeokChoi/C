#include <stdio.h>

int main() {

	const int Year = 2010;
	const int My_Old = 20;
	const int Bro_Old = 18;

	printf("올해는 %d년 입니다.\n", Year);
	printf("내 나이는 %d살 입니다.\n", My_Old);
	printf("나는 %d년에 태어나 %d번째 해가 되었습니다.\n", Year - My_Old, My_Old);
	printf("내 동생의 나이는 %d살 입니다.\n", Bro_Old);
	printf("내 동생은 %d년에 태어나 %d번째 해가 되었습니다.\n\n", Year - Bro_Old, Bro_Old);

	return 0;
}