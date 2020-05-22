#include <stdio.h>
#include <stdlib.h>
#include "Graphlinkedlist.h"
#include "Graphmst_Prim.h"
#include "Linkedgraph.h"

int main(int argc, char* argv[]) {
	int i = 0;
	LinkedGraph* pG1 = NULL;
	LinkedGraph* pMST1 = NULL;

	pG1 = createLinkedGraph(6);
	if (pG1 != NULL) {
		for (i = 0; i < 6; i++) {
			addVertexLG(pG1, i);
		}

		addEdgewithWeightLG(pG1, 0, 1, 4);
		addEdgewithWeightLG(pG1, 0, 2, 3);
		addEdgewithWeightLG(pG1, 1, 2, 2);
		addEdgewithWeightLG(pG1, 2, 3, 1);
		addEdgewithWeightLG(pG1, 3, 4, 1);
		addEdgewithWeightLG(pG1, 3, 6, 2);
		addEdgewithWeightLG(pG1, 4, 5, 6);

		printf("G1: \n\n");
		displayLinkedGraph(pG1);
		printf("G1 Edge Count : %d\n", pG1->currentEdgeCount);

		printf("\nPrim MST\n");
		pMST1 = mstPrim(pG1,1);
		printf("\n");
		displayLinkedGraph(pMST1);

		deletLinkedGraph(pG1);
		deletLinkedGraph(pMST1);

	}

	return 0;
}