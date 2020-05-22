#include <stdio.h>
#include "Ex_3.h"

int main() {

	int iKorean, iEnglish, iMath;

	printf("국어, 영어, 수학 점수를 입력하세요 : ");
	scanf("%d %d %d", &iKorean, &iEnglish, &iMath);

	score(iKorean, iEnglish, iMath);

	return 0;
}