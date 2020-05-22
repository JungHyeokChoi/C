#include <stdio.h>

//데이터 영역(전역 변수)
char ch = 'c';
int in = 5;

int main() {
	//스택 영역(지역 변수)
	int i = 3;
	//코드 영역(실행 함수)
	func1(i, 5);
	return 0;
}

//코드 영역(실행 함수)
int func1(int i, int j) {

	//스택 영역(지역 변수)
	char c = 'a';
	func2(c);
}

//코드 영역(실행 함수)
int func2(char c) {

	//스택 영역(지역 변수)
	int k = 3;
}