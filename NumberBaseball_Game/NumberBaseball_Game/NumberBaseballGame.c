#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void doRandomNumber(int* pInput);

int main() {

	int iInput[4], iAnswer[4];
	int iStrike = 0, iBall = 0;
	int iLoop1, iLoop2, iCount = 0;
	char cCheak;

	//게임 규칙 설명
	printf("<게임 규칙>\n\n");
	printf("1. 유추한 숫자가 없을 시에는 X, 위치가 다르나 숫자가 있으면 Ball, 위치와 숫자가 같으면 Strike \n");
	printf("2. 3 Strike가 되면 게임 종료\n\n");

	//숫자 생성
	doRandomNumber(iInput);

	//게임 시작
	while (1) {

		printf("숫자 네 개를 입력하세요 : ");
		for (int i = 0; i < 4; i++)
			scanf_s("%d", &iAnswer[i]);

		for (iLoop1 = 0; iLoop1 < 4; iLoop1++) {
			for (iLoop2 = 0; iLoop2 < 4; iLoop2++) {
				if (iInput[iLoop1] == iAnswer[iLoop2]) {
					if (iLoop1 == iLoop2)
						iStrike++;
					else
						iBall++;
				}
			}
		}

		if (iStrike == 4) {
			printf("%d번만에 정답을 맞추셨습니다.\n\n",iCount);
			printf("다시 시작하시겠습니까? (Y/N) : ");

			//" %c" 이유는 순수하게 문자만 받기 위해서이다. "%c"를 사용 할 시 A(엔터) or A\n으로 인식이 됨.
			// 키워드 : white space
			scanf(" %c", &cCheak);

			if (cCheak == 'Y') {
				system("cls");
				doRandomNumber(iInput);
				iStrike = 0, iBall = 0, iCount = 0;
				
			}

			else
				break;
		}
		else {
			printf("%d Strike / %d Ball 입니다.\n", iStrike, iBall);
			iStrike = 0, iBall = 0;
			iCount++;
		}
	}

	printf("\n");

	return 0;
}

void doRandomNumber(int * pInput)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 4; i++) {
		pInput[i] = rand() % 9;

		for (int j = 0; j < i; j++) {
			if (pInput[i] == pInput[j]) {
				--i;
				break;
			}
		}
	}

	printf("숫자 야구를 시작합니다.\n\n");
}
