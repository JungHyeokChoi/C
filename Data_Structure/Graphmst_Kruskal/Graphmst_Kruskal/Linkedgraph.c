#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graphlinkedlist.h"
#include "Linkedgraph.h"

//무방향 그래프 생성
LinkedGraph * createLinkedGraph(int maxVertexCount){
	int i = 0, j = 0;
	LinkedGraph* pReturn = NULL;
	
	//그래프 메모리 할당 및 초기화
	if (maxVertexCount > 0) {
		pReturn = (LinkedGraph*)malloc(sizeof(LinkedGraph));
		if (pReturn == NULL) {
			printf("오류, 메모리 할당(1), in createLinkedGraph\n");
			return NULL;
		}
		
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
		pReturn->currentVertexCount = 0;
		pReturn->currentEdgeCount = 0;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야합니다.\n");
		return NULL;
	}

	//노드 메모리 할당 및 초기화
	pReturn->pVertex = (int*)malloc(sizeof(int)*maxVertexCount);
	if (pReturn->pVertex == NULL) {
		printf("오류, 메모리 할당(2), in createLinkedGraph\n");
		free(pReturn);

		return NULL;
	}
	memset(pReturn->pVertex, NOT_USED, sizeof(int)*maxVertexCount);

	//간선 메모리 할당 및 초기화
	pReturn->ppAdjEdge = (LinkedList**)malloc(sizeof(LinkedList*)*maxVertexCount);
	if (pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리 할당(3), in createLinkedGraph\n");
		if (pReturn->pVertex != NULL) {
			free(pReturn->pVertex);
		}
		if (pReturn != NULL) {
			free(pReturn);
		}

		return NULL;
	}

	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = createLinkedList();
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리 할당(4), in createLinkedGraph\n");

			for (j = 0; j < i; j++) {
				if (pReturn->ppAdjEdge[j] != NULL) {
					free(pReturn->ppAdjEdge[j]);
				}
			}

			if (pReturn->pVertex != NULL) {
				free(pReturn->pVertex);
			}
			if (pReturn != NULL) {
				free(pReturn);
			}
			
			return NULL;
		}
	}

	
	return pReturn;
}

//방향 그래프 생성
LinkedGraph * createLinkedDirectedGraph(int maxVertexCount){
	LinkedGraph* pReturn = NULL;
	
	pReturn = createLinkedGraph(maxVertexCount);
	if (pReturn != NULL) {
		pReturn->graphType = GRAPH_DIRECTED;
	}

	return pReturn;
}

//노드 생성
int addVertexLG(LinkedGraph * pGraph, int vertexID){
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (vertexID < pGraph->maxVertexCount) {
			if (pGraph->pVertex[vertexID] == NOT_USED) {
				pGraph->pVertex[vertexID] = USED;
				pGraph->currentVertexCount++;
			}
			else {
				printf("오류, 노드 ID(1) [%d], in addVertexLG()\n", vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("오류, 노드 ID(2) 최대 생성 가능 노드 개수 : %d, in addVertexLG()\n", pGraph->maxVertexCount);
			ret = FAIL;
		}
	}

	return ret;
}

//간선 추가
int addEdgeLG(LinkedGraph * pGraph, int fromVertexID, int toVertexID){

	return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED);
}

int addLLElementForVertex(LinkedList *pList, int position, GraphVertex vertex){
	
	ListNode node = { 0, };
	node.data = vertex;

	return addLLElement(pList, position, node);
}

//간선 가중치 추가
int addEdgewithWeightLG(LinkedGraph * pGraph, int fromVertexID, int toVertexID, int weight){
	int ret = SUCCESS;
	GraphVertex toNode = { 0 , };

	if (pGraph != NULL) {
		if (pGraph->pVertex[fromVertexID] != USED || fromVertexID > pGraph->maxVertexCount) {
			ret = FAIL;
			return ret;
		}
		if (pGraph->pVertex[toVertexID] != USED || toVertexID > pGraph->maxVertexCount) {
			ret = FAIL;
			return ret;
		}

		toNode.vertexID = toVertexID;
		toNode.weight = weight;
		addLLElementForVertex(pGraph->ppAdjEdge[fromVertexID], 0, toNode);
		pGraph->currentEdgeCount++;

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			GraphVertex fromNode = { 0, };

			fromNode.vertexID = fromVertexID;
			fromNode.weight = weight;
			addLLElementForVertex(pGraph->ppAdjEdge[toVertexID], 0, fromNode);
			pGraph->currentEdgeCount++;
		}
	}

	return ret;
}

//노드 삭제
int removeVertexLG(LinkedGraph * pGraph, int vertexID){
	int ret = FAIL;
	int i = 0;

	if (pGraph != NULL) {
		if (pGraph->pVertex[vertexID] == USED && vertexID < pGraph->maxVertexCount){
			for (i = 0; i < pGraph->maxVertexCount; i++) {
				removeEdgeLG(pGraph, vertexID, i);
			}
			pGraph->pVertex[vertexID] = NOT_USED;
			pGraph->currentVertexCount--;

			ret = SUCCESS;
		}

	}
	
	return ret;
}

//간선 삭제
int removeEdgeLG(LinkedGraph * pGraph, int fromVertexID, int toVertexID){
	int ret = FAIL;

	if (pGraph != NULL) {
		if (pGraph->pVertex[fromVertexID] == USED
			&& pGraph->pVertex[toVertexID] == USED
			&& fromVertexID < pGraph->maxVertexCount
			&& toVertexID < pGraph->maxVertexCount) {

			deleteGraphNode(pGraph, pGraph->ppAdjEdge[fromVertexID], toVertexID);

			if (pGraph->graphType == GRAPH_UNDIRECTED) {
				deleteGraphNode(pGraph, pGraph->ppAdjEdge[toVertexID], fromVertexID);
			}

			ret = SUCCESS;
		}
	}
	return ret;
}

//간선 삭제
void deleteGraphNode(LinkedGraph* pGraph, LinkedList * pList, int delVertexID){
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	position = findGraphNodePosition(pList, delVertexID);
	if (position >= 0) {
		removeLLElement(pList, position);
		pGraph->currentEdgeCount--;
	}

}

//노드 검색
int findGraphNodePosition(LinkedList * pList, int vertexID){
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while (pNode != NULL) {
			if (pNode->data.vertexID == vertexID) {
				return position;
			}

			pNode = pNode->pLink;
			position++;
		}
	}

	return -1;
}

//그래프 공백 여부 확인
int isEmptyLG(LinkedGraph * pGraph){
	int ret = SUCCESS;

	if (pGraph->currentVertexCount == 0) {
		ret = FAIL;
	}

	return ret;
}

//그래프 삭제
void deleteLinkedGraph(LinkedGraph * pGraph){
	int i = 0;
	
	if (pGraph != NULL) {
		if (pGraph->currentVertexCount > 0) {
			for (i = 0; i < pGraph->maxVertexCount; i++) {
				removeVertexLG(pGraph, i);
			}
		}
		free(pGraph);
	}
	else {
		printf("오류, 그래프가 존재하지 않음\n");
	}
}

//그래프 정보 출력
void displayLinkedGraph(LinkedGraph * pGraph) {
	int i = 0, j = 0;
	int *ip = NULL;
	ListNode* pNode = NULL;

	if (pGraph != NULL) {
		if (pGraph->ppAdjEdge != NULL) {
			ip = (int*)malloc(sizeof(int)*pGraph->maxVertexCount);
			for (i = 0; i < pGraph->maxVertexCount; i++) {
				memset(ip, 0, sizeof(int)*pGraph->maxVertexCount);
				pNode = pGraph->ppAdjEdge[i]->headerNode.pLink;
				while (pNode != NULL) {
					ip[pNode->data.vertexID] = pNode->data.weight;
					pNode = pNode->pLink;
				}
				for (j = 0; j < pGraph->maxVertexCount; j++) {
					printf("%d ", ip[j]);
				}
				printf("\n");
			}
			free(ip);
		}
		printf("\n");
	}
	else {
		printf("오류, 그래프가 존재하지 않음\n");
	}
}