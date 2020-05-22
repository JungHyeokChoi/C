#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graphlinkedlist.h"
#include "Graphtraversal.h"
#include "Linkedgraph.h"
#include "Linkedstack.h"
#include "Linkedqueue.h"

int pushLSForDFS(LinkedStack * pStack, int nodeID){
	StackNode node = { 0, };
	
	node.data = nodeID;

	return pushLS(pStack,node);
}

int enqueueLQFofBFS(LinkedQueue* pQueue, int nodeID) {
	QueueNode node = { 0, };

	node.data = nodeID;

	return enqueueLQ(pQueue, node);
}

//깊이 우선 탐색(Depth-First-Search)
void traversalDFS(LinkedGraph * pGraph, int startvertexID){
	int i = 0;
	int vertexID = 0;
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	ListNode* pListNode = NULL;
	int *pVisited = NULL;

	if (pGraph == NULL) {
		return;
	}

	pStack = createLinkedStack();
	if (pStack == NULL) {
		return;
	}

	pVisited = (int*)malloc(sizeof(int)*pGraph->maxVertexCount);
	if (pVisited == NULL) {
		printf("오류, 메모리 할당 in traversalDFS()\n");
		if (pStack != NULL) {
			deleteLinkedStack(pStack);
		}
		return;
	}

	memset(pVisited, FALSE, sizeof(int)*pGraph->maxVertexCount);

	pVisited[startvertexID] = TRUE;
	pushLSForDFS(pStack, startvertexID);
	
	while (isLinkedStackEmpty(pStack) == FALSE) {
		pStackNode = popLS(pStack);
		if (pStackNode != NULL) {
			vertexID = pStackNode->data;
			printf("[%d]-방문\n", vertexID);

			pListNode = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
			while (pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				
				if (pVisited[vertexID] == FALSE) {
					pVisited[vertexID] = TRUE;
					pushLSForDFS(pStack, vertexID);
				}

				pListNode = pListNode->pLink;
			}
		}
	}

	printf("\n");

	free(pVisited);
	deleteLinkedStack(pStack);
}

//넓이 우선 탐색(Breadth-First-Search)
void traversalBFS(LinkedGraph * pGraph, int startvertexID){
	int i = 0;
	int vertexID = 0;
	LinkedQueue* pQueue = NULL;
	QueueNode* pQueueNode = NULL;
	ListNode* pListNode = NULL;
	int *pVisited = NULL;

	if (pGraph == NULL) {
		return;
	}

	pQueue = createLinkedQueue();
	if (pQueue == NULL) {
		return;
	}

	pVisited = (int*)malloc(s
		izeof(int)*pGraph->maxVertexCount);
	if (pVisited == NULL) {
		printf("오류, 메모리 할당, in traversalBFS()\n");
		if (pQueue != NULL) {
			deleteLinkedQueue(pQueue);
			return;
		}
	}

	memset(pVisited, FALSE, sizeof(int)*pGraph->maxVertexCount);

	pVisited[startvertexID] = TRUE;
	enqueueLQFofBFS(pQueue, startvertexID);

	while (isLinkedQueueEmpty(pQueue) == FALSE) {
		pQueueNode = dequeueLQ(pQueue);
		if (pQueueNode != NULL) {
			vertexID = pQueueNode->data;
			printf("[%d]-방문\n", vertexID);

			pListNode = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
			while (pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				
				if (pVisited[vertexID] == FALSE) {
					pVisited[vertexID] = TRUE;
					enqueueLQFofBFS(pQueue, vertexID);
				}

				pListNode = pListNode->pLink;
			}
		}
	}
	printf("\n");

	free(pVisited);
	deleteLinkedQueue(pQueue);
}


