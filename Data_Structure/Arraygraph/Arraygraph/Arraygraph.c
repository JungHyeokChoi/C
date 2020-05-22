#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraygraph.h"

//무방향 그래프 생성
ArrayGraph * createArrayGraph(int maxVertexCount) {
	ArrayGraph* pReturn = NULL;
	int i = 0, j = 0;

	if (maxVertexCount > 0) {
		pReturn = (ArrayGraph*)malloc(sizeof(ArrayGraph));
		if (pReturn == NULL) {
			printf("오류, 메모리 할당(1), in createArrayGraph()\n");
			return NULL;
		}

		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야 합니다.\n");
		return NULL;
	}

	pReturn->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);
	if (pReturn->pVertex == NULL) {
		printf("오류, 메모리할당(2), in createArrayGraph()\n");
		if (pReturn != NULL) {
			free(pReturn);
		}
		return NULL;
	}

	pReturn->ppAdjEdge = (int**)malloc(sizeof(int*)* maxVertexCount);
	if (pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리 할당(3), in createArrayGraph()\n");

		if (pReturn->pVertex != NULL) {
			free(pReturn->pVertex);
		}
		if (pReturn != NULL) {
			free(pReturn);
		}

		return NULL;
	}

	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = (int*)malloc(sizeof(int)*maxVertexCount);
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리할당(4), in createArrayGraph()\n");

			for (j = 0; j < i - 1; j++) {
				if (pReturn->ppAdjEdge[j] != NULL) {
					free(pReturn->ppAdjEdge[j]);
				}
			}

			if (pReturn->ppAdjEdge != NULL) {
				free(pReturn->ppAdjEdge);
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

	memset(pReturn->pVertex,NOT_USED, sizeof(int)*maxVertexCount);
	for (i = 0; i < maxVertexCount; i++) {
		memset(pReturn->ppAdjEdge[i], 0, sizeof(int)*maxVertexCount);
	}
	return pReturn;
}

//방향 그래프 생성
ArrayGraph * createArrayDirectedGraph(int maxVertexCount){
	ArrayGraph* pReturn = NULL;

	pReturn = createArrayGraph(maxVertexCount);
	if (pReturn != NULL) {
		pReturn->graphType = GRAPH_DIRECTED;
	}

	return pReturn;
}

//노드 추가
int addVertexAG(ArrayGraph * pGraph, int vextexID){
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (vextexID < pGraph->maxVertexCount) {
			if (pGraph->pVertex[vextexID] == NOT_USED) {
				pGraph->pVertex[vextexID] = USED;
				pGraph->currentVertexCount++;
			}
			else {
				printf("오류, 이미 존재하는 노드[%d]\n", vextexID);
				ret = FAIL;
			}
		}
		else {
			printf("오류, 최대 노드 개수 초과[%d]",vextexID);
			ret = FAIL;
		}
	}
	return ret;
}

//간선 가중치 추가
int addEdgewithWeightAG(ArrayGraph * pGraph, int fromVertexID, int toVertexID, int weight){
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (chechkVertexVaild(pGraph, fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}

		if (chechkVertexVaild(pGraph, toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
		}
		else {
			pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
		}
		
	}

	return ret;
}

//노드 값 확인
int chechkVertexVaild(ArrayGraph *pGraph, int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= pGraph->maxVertexCount 
		|| pGraph->pVertex[vertexID] == NOT_USED) {
		printf("오류, 노드 정보[%d]\n",vertexID);
		ret = FAIL;

		return ret;
	}

	return ret;
}

//간선 추가
int addEdgeAG(ArrayGraph * pGraph, int fromVertexID, int toVertexID){

	return addEdgewithWeightAG(pGraph,fromVertexID,toVertexID,USED);
}

//간선 삭제
int removeEdgeAG(ArrayGraph * pGraph, int fromVertexID, int toVertexID){
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (chechkVertexVaild(pGraph, fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (chechkVertexVaild(pGraph, toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;

		if (pGraph->graphType == GRAPH_UNDIRECTED) {
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
		}
	}

	return ret;
}

//노드 삭제
int removeVertexAG(ArrayGraph * pGraph, int vertexID){
	int ret = SUCCESS;
	int i = 0;

	if (pGraph != NULL) {
		if (chechkVertexVaild(pGraph, vertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		for (i = 0; i < vertexID; i++) {
			removeEdgeAG(pGraph, vertexID, i);
			removeEdgeAG(pGraph, i, vertexID);
		}

		pGraph->pVertex[vertexID] = NOT_USED;
	}

	return ret;
}

//그래프 삭제
void deleteArrayGraph(ArrayGraph * pGraph){
	int i = 0, j = 0;
	
	if (pGraph != NULL) {
		if (pGraph->pVertex != NULL) {
			if (pGraph->ppAdjEdge != NULL) {
				for (i = 0; i < pGraph->currentVertexCount; i++) {
					for (j = 0; j < pGraph->currentVertexCount; j++) {
						free(pGraph->ppAdjEdge[i][j]);
					}
				}
			}
			else {
				printf("오류, 간선이 존재하지 않음, in deleteArrayGraph()\n");
			}
			for (i = 0; i < pGraph->currentVertexCount; i++) {
				free(pGraph->pVertex[i]);
			}

		}
		else {
			printf("오류, 노드가 존재하지 않음, in deleteArrayGraph()\n");
		}
		free(pGraph);
	}
	else {
		printf("오류, 그래프가 존재하지 않음, in deleteArrayGraph()\n");
	}
}

//그래프 공백 확인
int isEmptyAG(ArrayGraph * pGraph){
	int ret = FAIL;

	if (pGraph != NULL) {
		if (pGraph->currentVertexCount == 0) {
			ret = SUCCESS;
			return ret;
		}
	}

	return ret;
}

//그래프 정보 확인
void displayArrayGraph(ArrayGraph * pGraph){
	int i = 0, j = 0;
	
	if (pGraph != NULL) {
		for (i = 0; i < pGraph->maxVertexCount; i++) {
			for (j = 0; j < pGraph->maxVertexCount; j++) {
				printf("%d ", pGraph->ppAdjEdge[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else {
		printf("오류, 그래프 정보 출력 실패\n");
	}
}










