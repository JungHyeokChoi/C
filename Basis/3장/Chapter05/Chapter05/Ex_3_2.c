#include <stdio.h>
#include "Ex_3.h"

int main() {

	int iKorean, iEnglish, iMath;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &iKorean, &iEnglish, &iMath);

	score(iKorean, iEnglish, iMath);

	return 0;
}