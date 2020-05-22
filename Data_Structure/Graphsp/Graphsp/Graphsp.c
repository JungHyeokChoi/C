#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedgraph.h"
#include "Graphlinkedlist.h"
#include "Graphsp.h"

//Dijstra 알고리즘
int *shortestPathDijstra(LinkedGraph *pGraph, int startVertexID){
	int *pReturn = NULL;
	int *pSelected = NULL;
	int nodeCount = 0, maxNodeCount = 0;
	int i = 0, j = 0, weight = 0;
	int vertexID = 0, y_v = 0, y_w = 0;
	ListNode *pListNode = NULL;
	LinkedList *pEdgeList = NULL;

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return pReturn;
	}

	maxNodeCount = pGraph->maxVertexCount;
	nodeCount = pGraph->currentVertexCount;
	
	pReturn = (int*)malloc(sizeof(int) * maxNodeCount);
	pSelected = (int*)malloc(sizeof(int) * maxNodeCount);

	if (pReturn == NULL || pSelected == NULL) {
		printf("오류, 메모리 할당 in shortestPathDijstra()\n");
		return NULL;
	}

	//초기화
	for (i = 0; i < maxNodeCount; i++) {
		if (i == startVertexID) {
			pSelected[i] = FALSE;
			pReturn[i] = 0;
		}
		else {
			if (pGraph->pVertex[i] == USED) {
				pSelected[i] = TRUE;
				pReturn[i] = getEdgeWeight(pGraph, startVertexID, i);
			}
			else {
				pSelected[i] = FALSE;
				pReturn[i] = MAX_INT;
			}
		}
	}

	//초기값 확인
	printf("초기값\n\n");
	for (i = 0; i < maxNodeCount; i++) {
		printf("(%d,%d) -> %d\n", startVertexID, i, pReturn[i]);
	}
	
	printf("\nDijstra Algorithm\n\n");
	for (i = 0; i < nodeCount - 1; i++) {
		printf("[%d] - Iteration\n", i + 1);

		weight = MAX_INT;
		for (j = 0; j < nodeCount; j++) {
			if (pReturn[j] != 0) {
				if (weight > pReturn[j] && pSelected[j] == TRUE) {
					weight = pReturn[j];
					vertexID = j;
				}
			}
		}	
		pSelected[vertexID] = FALSE;

		pEdgeList = pGraph->ppAdjEdge[vertexID];

		pListNode = pEdgeList->headerNode.pLink;
		while (pListNode != NULL) {
			int toVertexID = pListNode->data.vertexID;
			int weight = pListNode->data.weight;

			y_v = pReturn[vertexID];
			y_w = pReturn[toVertexID];
			
			if (y_v + weight < y_w) {
				pReturn[toVertexID] = y_v + weight;
			}

			pListNode = pListNode->pLink;
		}

		for (j = 0; j < maxNodeCount; j++) {
			printf("\t (%d,%d) -> %d\n", startVertexID, j, pReturn[j]);
		}
		
	}
	free(pSelected);

	printf("\n");
	return pReturn;
}

int getEdgeWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID){
	int Return = MAX_INT;
	ListNode *pListNode = NULL;
	LinkedList *pEdgeList = NULL;

	pEdgeList = pGraph->ppAdjEdge[fromVertexID];
	pListNode = pEdgeList->headerNode.pLink;

	while (pListNode != NULL) {
		if (pListNode->data.vertexID == toVertexID) {
			Return = pListNode->data.weight;
		}
		pListNode = pListNode->pLink;
	}

	return Return;
}

//Floyd 알고리즘
int** shortestPathFloyd(LinkedGraph * pGraph){
	int **pReturn = NULL;
	int r = 0, s = 0, v = 0;
	int weight = 0;
	int maxNodeCount = 0;

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return NULL;
	}

	maxNodeCount = pGraph->maxVertexCount;
	printf("노드 개수 : %d\n\n", pGraph->currentVertexCount);

	pReturn = (int**)malloc(sizeof(int*) * maxNodeCount);
	if (pReturn == NULL) {
		printf("오류,메모리 할당(1) in shortestPathFloyd()\n");

		return NULL;
	}

	for (r = 0; r < maxNodeCount; r++) {
		pReturn[r] = (int*)malloc(sizeof(int) * maxNodeCount);
		if (pReturn[r] == NULL) {
			printf("오류,메모리 할당(2) in shortestPathFloyd()\n");
			 
			free(pReturn);
			return NULL;
		}
	}

	for (r = 0; r < maxNodeCount; r++) {
		for (s = 0; s < maxNodeCount; s++) {
			if (r == s) {
				pReturn[r][s] = 0;
			}
			else {
				pReturn[r][s] = getEdgeWeight(pGraph, r, s);
			}
		}
	}
	printMatrix(pReturn, maxNodeCount);
	
	for (v = 0; v < maxNodeCount; v++) {
		for (r = 0; r < maxNodeCount; r++) {
			for (s = 0; s < maxNodeCount; s++) {
				if (pReturn[r][v] + pReturn[s][v] < pReturn[r][s]) {
					pReturn[r][s] = pReturn[r][v] + pReturn[s][v];
				}
			}
		}
		printf("[%d] Loop\n",v+1);
		printMatrix(pReturn,maxNodeCount);
	}
	
	
	return pReturn;
}

void printMatrix(int ** A, int maxNodeCount){
	int i = 0, j = 0;

	for (i = 0; i < maxNodeCount; i++) {
		for (j = 0; j < maxNodeCount; j++) {
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int **checkReachability(int **A, int maxNodeCount){
	int r = 0, s = 0, v = 0;
	int** pReturn = NULL;

	pReturn = (int**)malloc(sizeof(int*) * maxNodeCount);
	if (pReturn == NULL) {
		printf("오류,메모리 할당(1) in checkReachability()\n");

		return NULL;
	}

	for (r = 0; r < maxNodeCount; r++) {
		pReturn[r] = (int*)malloc(sizeof(int) * maxNodeCount);
		if (pReturn[r] == NULL) {
			printf("오류,메모리 할당(2) in checkReachability()\n");

			free(pReturn);
			return NULL;
		}
	}

	for (v = 0; v < maxNodeCount; v++) {
		for (r = 0; r < maxNodeCount; r++) {
			if (A[r][v] > 0 && A[r][v] < 99999) {
				for (s = 0; s < maxNodeCount; s++) {
					if (A[v][s] > 0 && A[v][s] < 99999) {
						pReturn[r][s] = 1;
					}
				}
			}
		}
	}

	printMatrix(pReturn,maxNodeCount);

	return pReturn;
}
