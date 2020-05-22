#include <stdio.h>
#include <stdlib.h>
#include "Doublylist.h"
#include "Matricx.h"

int main() {
	DoublyList* pListA = NULL, *pListB = NULL;

	pListA = createMatricDoublyList(4, 4);

	if (pListA != NULL) {
		//희소 행렬
		/* { 0 0 0 3
			 0 1 0 0
			 5 0 0 0
			 0 0 7 0 }*/

		printf("희소 행렬\n\n");
		addMatricxNodeDoublyList(pListA, 1, 4, 3);
		addMatricxNodeDoublyList(pListA, 2, 2, 1);
		addMatricxNodeDoublyList(pListA, 3, 1, 5);
		addMatricxNodeDoublyList(pListA, 4, 3, 7);

		displayMatricxDoublyList(pListA);
		printf("노드 개수 : %d\n\n", getDoublyListLength(pListA));

		//희소 행렬 전치
		/* { 0 0 5 0
			 0 1 0 0
			 0 0 0 7
			 3 0 0 0 }*/

		printf("전치 행렬\n\n");
		pListB = matricxTransposed(pListA);
		displayMatricxDoublyList(pListB);
		printf("노드 개수 : %d\n\n", getDoublyListLength(pListB));

		deleteDoublyList(pListA);
		deleteDoublyList(pListB);
	}

	return 0;
}