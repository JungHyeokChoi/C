#include <stdio.h>
#include <stdlib.h>
#include "Doublylist.h"
#include "Matricx.h"

int main() {
	DoublyList* pListA = NULL, *pListB = NULL;

	pListA = createMatricDoublyList(4, 4);

	if (pListA != NULL) {
		//��� ���
		/* { 0 0 0 3
			 0 1 0 0
			 5 0 0 0
			 0 0 7 0 }*/

		printf("��� ���\n\n");
		addMatricxNodeDoublyList(pListA, 1, 4, 3);
		addMatricxNodeDoublyList(pListA, 2, 2, 1);
		addMatricxNodeDoublyList(pListA, 3, 1, 5);
		addMatricxNodeDoublyList(pListA, 4, 3, 7);

		displayMatricxDoublyList(pListA);
		printf("��� ���� : %d\n\n", getDoublyListLength(pListA));

		//��� ��� ��ġ
		/* { 0 0 5 0
			 0 1 0 0
			 0 0 0 7
			 3 0 0 0 }*/

		printf("��ġ ���\n\n");
		pListB = matricxTransposed(pListA);
		displayMatricxDoublyList(pListB);
		printf("��� ���� : %d\n\n", getDoublyListLength(pListB));

		deleteDoublyList(pListA);
		deleteDoublyList(pListB);
	}

	return 0;
}