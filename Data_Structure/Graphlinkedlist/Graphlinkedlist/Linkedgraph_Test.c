#include <stdio.h>
#include <stdlib.h>
#include "Linkedgraph.h"
#include "Graphlinkedlist.h"

int main(int argc, char *argv[]) {
	int i = 0;
	LinkedGraph* pG1 = NULL;
	LinkedGraph* pG2 = NULL;
	LinkedGraph* pG4 = NULL;

	pG1 = createLinkedGraph(6);
	pG2 = createLinkedDirectedGraph(6);
	pG4 = createLinkedDirectedGraph(6);
	
	if (pG1 != NULL && pG2 != NULL && pG4 != NULL) {
		for (i = 0; i < 6; i++) {
			addVertexLG(pG1, i);
			addVertexLG(pG2, i);
			addVertexLG(pG4, i);
		}
		
		//G1
		addEdgeLG(pG1, 0, 1);
		addEdgeLG(pG1, 0, 2);
		addEdgeLG(pG1, 1, 2);
		addEdgeLG(pG1, 2, 3);
		addEdgeLG(pG1, 3, 4);
		addEdgeLG(pG1, 3, 5);
		addEdgeLG(pG1, 4, 5);

		//G2
		addEdgeLG(pG2, 0, 1);
		addEdgeLG(pG2, 1, 2);
		addEdgeLG(pG2, 2, 0);
		addEdgeLG(pG2, 2, 1);
		addEdgeLG(pG2, 2, 3);
		addEdgeLG(pG2, 3, 2);
		addEdgeLG(pG2, 3, 4);
		addEdgeLG(pG2, 4, 5);
		addEdgeLG(pG2, 5, 3);

		//G4
		addEdgewithWeightLG(pG4, 0, 1, 4);
		addEdgewithWeightLG(pG4, 1, 2, 1);
		addEdgewithWeightLG(pG4, 2, 3, 2);
		addEdgewithWeightLG(pG4, 2, 0, 2);
		addEdgewithWeightLG(pG4, 2, 1, 3);
		addEdgewithWeightLG(pG4, 3, 2, 1);
		addEdgewithWeightLG(pG4, 3, 4, 1);
		addEdgewithWeightLG(pG4, 4, 5, 1);
		addEdgewithWeightLG(pG4, 5, 3, 2); 
		

		printf("G1 : Undirected\n\n");
		displayLinkedGraph(pG1);
		printf("G2 : Directed\n\n");
		displayLinkedGraph(pG2);
		printf("G4 : Directed Weighted\n\n");
		displayLinkedGraph(pG4);

		deletLinkedGraph(pG1);
		deletLinkedGraph(pG2);
		deletLinkedGraph(pG4);

	}
	else {
		printf("오류, 그래프 생성 실패\n");
	}

	return 0;
}