#include <stdio.h>
#include <stdlib.h>
#include "Graphlinkedlist.h"
#include "Linkedgraph.h"
#include "Grapharrayheap.h"
#include "Graphmst_kruskal.h"

int main(int argc, char *args[]) {
	int i = 0;
	LinkedGraph* pGraph = NULL;
	LinkedGraph* pResult = NULL;
	ArrayHeap* pMinHeap = NULL;

	pGraph = createLinkedGraph(10);
	
	if (pGraph != NULL) {
		for (i = 0; i < 10; i++) {
			addVertexLG(pGraph, i);
		}
		
		addEdgewithWeightLG(pGraph, 0, 1, 4);
		addEdgewithWeightLG(pGraph, 0, 2, 3);
		addEdgewithWeightLG(pGraph, 3, 4, 1);
		addEdgewithWeightLG(pGraph, 3, 5, 5);
		addEdgewithWeightLG(pGraph, 4, 5, 6);
		addEdgewithWeightLG(pGraph, 1, 2, 2);
		addEdgewithWeightLG(pGraph, 2, 3, 1);
		addEdgewithWeightLG(pGraph, 6, 5, 2);
		addEdgewithWeightLG(pGraph, 6, 3, 2);
		addEdgewithWeightLG(pGraph, 7, 1, 1);
		addEdgewithWeightLG(pGraph, 7, 8, 5);
		addEdgewithWeightLG(pGraph, 8, 4, 7);
		addEdgewithWeightLG(pGraph, 9, 2, 4);
		addEdgewithWeightLG(pGraph, 9, 6, 6);


		printf("Kruskal Before \n\n");
		displayLinkedGraph(pGraph);
		pMinHeap = orderEdges(pGraph);
		displayArrayHeap(pMinHeap);
		

		printf("\nKruskal After\n\n");
		pResult = mstKruskal(pGraph);
		printf("\n");
		displayLinkedGraph(pResult);

		int ret = FALSE;
		ret = checkCycle(pGraph, 3, 4);
		printf("Result : %d\n", ret);
	}

	deleteLinkedGraph(pGraph);
	deleteLinkedGraph(pResult);
}