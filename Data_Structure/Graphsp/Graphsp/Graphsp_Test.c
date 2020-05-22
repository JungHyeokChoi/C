#include <stdio.h>
#include <stdlib.h>
#include "Linkedgraph.h"
#include "Graphlinkedlist.h"
#include "Graphsp.h"

int main(int argc, char *args[]) {
	LinkedGraph *pG1 = NULL;
	int i = 0;

	int **A = NULL;

	pG1 = createLinkedGraph(6);

	if (pG1 != NULL) {
		for (i = 0; i < pG1->maxVertexCount; i++) {
			addVertexLG(pG1,i);
		}

		addEdgewithWeightLG(pG1, 0, 1, 1);
		addEdgewithWeightLG(pG1, 0, 2, 4);
		addEdgewithWeightLG(pG1, 1, 2, 2);
		addEdgewithWeightLG(pG1, 2, 3, 1);
		addEdgewithWeightLG(pG1, 3, 4, 8);
		addEdgewithWeightLG(pG1, 3, 5, 3);
		addEdgewithWeightLG(pG1, 4, 5, 4);

		printf("pG1 : \n");
		displayLinkedGraph(pG1);
		printf("After Dijstra  : \n");
		shortestPathDijstra(pG1, 0);
		printf("After Floyd  : \n");
		A = shortestPathFloyd(pG1);
		printf("도달 가능성  : \n");
		checkReachability(A, pG1->maxVertexCount);
		
	}

	if (A != NULL) {
		for (i = 0; i < pG1->maxVertexCount; i++) {
			free(A[i]);
		}
		free(A);
	}

	deletLinkedGraph(pG1);
	
	return 0;
}