#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graphmst_Kruskal.h"
#include "Linkedgraph.h"
#include "Grapharrayheap.h"


//Kruskal 알고리즘
LinkedGraph* mstKruskal(LinkedGraph * pGraph){
	LinkedGraph* pReturn = NULL;
	int i = 0;
	int maxNodeCount = 0;
	int currentNodeCount = 0;
	int edgeCount = 0;
	int isCycle = FALSE;
	ArrayHeap* pMinHeap = NULL;
	HeapNode* pHeapNode = NULL;

	if (pGraph == NULL) {
		printf("Graph is Null\n");
		return NULL;
	}

	maxNodeCount = pGraph->maxVertexCount;
	currentNodeCount = pGraph->currentVertexCount;
	edgeCount = pGraph->currentEdgeCount;

	pReturn = createLinkedGraph(maxNodeCount);

	if (pReturn == NULL) {
		return NULL;
	}

	pMinHeap = orderEdges(pGraph);
	if (pMinHeap == NULL) {
		return  NULL;
	}

	for (i = 0; i < edgeCount; i++) {
		pHeapNode = deleteMinHeapAH(pMinHeap);

		if (pHeapNode != NULL) {
			isCycle = checkCycle(pReturn, pHeapNode->fromVertexID,
				pHeapNode->toVertexID);

			if (isCycle == FALSE) {
				if (pReturn->pVertex[pHeapNode->fromVertexID] != USED) {
					addVertexLG(pReturn, pHeapNode->fromVertexID);
				}
				if (pReturn->pVertex[pHeapNode->toVertexID] != USED) {
					addVertexLG(pReturn, pHeapNode->toVertexID);
				}

				addEdgewithWeightLG(pReturn, pHeapNode->fromVertexID,
					pHeapNode->toVertexID, pHeapNode->key);
				
				
				printf("(%d,%d)-%d\n",
					pHeapNode->fromVertexID,pHeapNode->toVertexID,pHeapNode->key);
			}
			free(pHeapNode);
		}

		if ((maxNodeCount - 1) * 2 == pReturn->currentEdgeCount) {
			break;
		}
	}
	return pReturn;
}


//기존 그래프의 간선을 가중치 값으로 오름차순으로 정렬
ArrayHeap* orderEdges(LinkedGraph *pGraph){
	int i = 0,j = 0;
	ArrayHeap* pReturn = NULL;
	ListNode* pListNode = NULL;
	HeapNode node = { 0, };

	pReturn = createArrayHeap((pGraph->currentEdgeCount / 2) + 1);
	if (pReturn == NULL) {
		printf("오류, 메모리 할당, in orderEdges()\n");
		return NULL;
	}
	
	if (pGraph != NULL) {
		for (i = 0; i < pGraph->maxVertexCount; i++) {
			pListNode = pGraph->ppAdjEdge[i]->headerNode.pLink;

			while (pListNode != NULL) {
				node.fromVertexID = i;
				node.toVertexID = pListNode->data.vertexID;
				node.key = pListNode->data.weight;

				insertMinHeapAH(pReturn, node);

				pListNode = pListNode->pLink;
			}
		}
	}
	return pReturn;
}

int checkCycle(LinkedGraph * pGraph, int fromVertexID, int toVertexID) {
	int i = 0;
	int ret = FALSE;
	int *ip_from = NULL, *ip_to = NULL;
	ListNode *pListNode = NULL;

	if (pGraph != NULL) {
		if (pGraph->currentEdgeCount >= 4) {
			ip_from = (int*)malloc(sizeof(int)*pGraph->maxVertexCount);
			ip_to = (int*)malloc(sizeof(int)*pGraph->maxVertexCount);

			memset(ip_from, NOT_VISITED, sizeof(int)*pGraph->maxVertexCount);
			memset(ip_to, NOT_VISITED, sizeof(int)*pGraph->maxVertexCount);

			pListNode = pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink;
			while (pListNode != NULL) {
				ip_from[pListNode->data.vertexID] = VISITED;

				pListNode = pListNode->pLink;
			}

			pListNode = pGraph->ppAdjEdge[toVertexID]->headerNode.pLink;
			while (pListNode != NULL) {
				ip_to[pListNode->data.vertexID] = VISITED;

				pListNode = pListNode->pLink;
			}

			ret = checkEdge(pGraph, fromVertexID, toVertexID);

			if (ret == TRUE) {
				return ret;
			}
			else {
				ret = FALSE;
				for (i = 0; i < pGraph->maxVertexCount; i++) {
					if (ip_from[i] == VISITED && ip_to[i] == VISITED) {
						printf("(%d,%d) - 기존의 경로가 존재 합니다.\n", fromVertexID, toVertexID);
						printf("(%d,%d) - 기존의 경로가 존재 합니다.\n", toVertexID, fromVertexID);

						ret = TRUE;
						return ret;
					}
				}
			}
		}


	}

	free(ip_from);
	free(ip_to);

	return ret;
}

int checkEdge(LinkedGraph * pGraph, int fromVertexID, int toVertexID) {
	int ret = FALSE;
	int i = 0;
	ListNode* pListNode = NULL;

	if (pGraph != NULL) {
		for (i = 0; i < pGraph->maxVertexCount; i++) {
			pListNode = pGraph->ppAdjEdge[i]->headerNode.pLink;
			while (pListNode != NULL) {
				if ((i == fromVertexID && pListNode->data.vertexID == toVertexID)
					|| (i == toVertexID && pListNode->data.vertexID == fromVertexID)) {

					ret = TRUE;
					return ret;
				}

				pListNode = pListNode->pLink;
			}
		}
	}

	return ret;
}
