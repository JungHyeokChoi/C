#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graphlinkedlist.h"
#include "Linkedgraph.h"
#include "Graphmst_Prim.h"
#include "Grapharrayheap.h"

LinkedGraph* mstPrim(LinkedGraph* pGraph, int startVertexID){
	LinkedGraph* pReturn = NULL;
	int i = 0;
	int nodeCount = 0;
	int mstNodeCount = 0;
	int maxNodeCount = 0;
	int fromVertexID = 0;
	GraphEdge minWeightEdge = { 0, };
	ArrayHeap *pEdgeList = NULL;

	if (pGraph == NULL){
		printf("Graph is NULL\n");
		return pReturn;
	}

	nodeCount = pGraph->currentVertexCount;
	maxNodeCount = pGraph->maxVertexCount;

	pReturn = createLinkedGraph(maxNodeCount);
	if (pReturn == NULL) {
		return pReturn;
	}

	addVertexLG(pReturn, startVertexID);

	fromVertexID = startVertexID;

	pEdgeList = createArrayHeap(pGraph->currentEdgeCount);

	while (pReturn->currentVertexCount < nodeCount) {
		minWeightEdge.vertexIDFrom = 0;
		minWeightEdge.vertexIDTo = 0;
		minWeightEdge.weight = MAX_INT;

		getMinWeightEdge(pGraph, pReturn, fromVertexID, &minWeightEdge, pEdgeList);

		printf("[%d], 최소 가중치 : (%d,%d) -> %d\n"
			,pReturn->currentVertexCount, minWeightEdge.vertexIDFrom, minWeightEdge.vertexIDTo,minWeightEdge.weight);
		//printf("-------------------------------------\n");


		addVertexLG(pReturn, minWeightEdge.vertexIDTo);
		addEdgewithWeightLG(pReturn, minWeightEdge.vertexIDFrom, 
			minWeightEdge.vertexIDTo, minWeightEdge.weight);

		fromVertexID = minWeightEdge.vertexIDTo;
	}

	deleteArrayHeap(pEdgeList);

	return pReturn;
}

void getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph *pMST, int mstVertexID, GraphEdge *pMinWeightEdge, ArrayHeap *pEdgeList){
	ListNode *pListNode = NULL;
	HeapNode node = { 0, };
	HeapNode *pHeapNode = NULL;
	int startVertexID = 0;
	int ret = TRUE;
	int i = 1;

	startVertexID = mstVertexID;
	//printf("\nStartVertexID : %d\n\n",startVertexID);

	pListNode = pGraph->ppAdjEdge[startVertexID]->headerNode.pLink;

	while (pListNode != NULL) {
		node.fromVertexID = startVertexID;
		node.toVertexID = pListNode->data.vertexID;
		node.weight = pListNode->data.weight;

		insertMinHeapAH(pEdgeList, node);

		pListNode = pListNode->pLink;
	}

	//displayArrayHeap(pEdgeList);
	while (ret != FALSE) {
		pHeapNode = &(pEdgeList->pElement[i]);
		//printf("\nin pEdgeList->pElement[%d] : %d,%d\n\n", i, pEdgeList->pElement[i].fromVertexID, pEdgeList->pElement[i].toVertexID);

		ret = checkCycle(pMST, pHeapNode->fromVertexID, pHeapNode->toVertexID);
		//printf("Ret : %d\n\n", ret);

		i++;
	}

	pMinWeightEdge->vertexIDFrom = pHeapNode->fromVertexID;
	pMinWeightEdge->vertexIDTo = pHeapNode->toVertexID;
	pMinWeightEdge->weight = pHeapNode->weight;
}

int checkCycle(LinkedGraph * pGraph, int fromVertexID, int toVertexID){
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

	if (pGraph != NULL){
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
