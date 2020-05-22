#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void doRandomNumber(int* pInput);

int main() {

	int iInput[4], iAnswer[4];
	int iStrike = 0, iBall = 0;
	int iLoop1, iLoop2, iCount = 0;
	char cCheak;

	//���� ��Ģ ����
	printf("<���� ��Ģ>\n\n");
	printf("1. ������ ���ڰ� ���� �ÿ��� X, ��ġ�� �ٸ��� ���ڰ� ������ Ball, ��ġ�� ���ڰ� ������ Strike \n");
	printf("2. 3 Strike�� �Ǹ� ���� ����\n\n");

	//���� ����
	doRandomNumber(iInput);

	//���� ����
	while (1) {

		printf("���� �� ���� �Է��ϼ��� : ");
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
			printf("%d������ ������ ���߼̽��ϴ�.\n\n",iCount);
			printf("�ٽ� �����Ͻðڽ��ϱ�? (Y/N) : ");

			//" %c" ������ �����ϰ� ���ڸ� �ޱ� ���ؼ��̴�. "%c"�� ��� �� �� A(����) or A\n���� �ν��� ��.
			// Ű���� : white space
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
			printf("%d Strike / %d Ball �Դϴ�.\n", iStrike, iBall);
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

	printf("���� �߱��� �����մϴ�.\n\n");
}
