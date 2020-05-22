#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraygraph.h"

//������ �׷��� ����
ArrayGraph * createArrayGraph(int maxVertexCount) {
	ArrayGraph* pReturn = NULL;
	int i = 0, j = 0;

	if (maxVertexCount > 0) {
		pReturn = (ArrayGraph*)malloc(sizeof(ArrayGraph));
		if (pReturn == NULL) {
			printf("����, �޸� �Ҵ�(1), in createArrayGraph()\n");
			return NULL;
		}

		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
	}
	else {
		printf("����, �ִ� ��� ������ 0���� Ŀ�� �մϴ�.\n");
		return NULL;
	}

	pReturn->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);
	if (pReturn->pVertex == NULL) {
		printf("����, �޸��Ҵ�(2), in createArrayGraph()\n");
		if (pReturn != NULL) {
			free(pReturn);
		}
		return NULL;
	}

	pReturn->ppAdjEdge = (int**)malloc(sizeof(int*)* maxVertexCount);
	if (pReturn->ppAdjEdge == NULL) {
		printf("����, �޸� �Ҵ�(3), in createArrayGraph()\n");

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
			printf("����, �޸��Ҵ�(4), in createArrayGraph()\n");

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

//���� �׷��� ����
ArrayGraph * createArrayDirectedGraph(int maxVertexCount){
	ArrayGraph* pReturn = NULL;

	pReturn = createArrayGraph(maxVertexCount);
	if (pReturn != NULL) {
		pReturn->graphType = GRAPH_DIRECTED;
	}

	return pReturn;
}

//��� �߰�
int addVertexAG(ArrayGraph * pGraph, int vextexID){
	int ret = SUCCESS;

	if (pGraph != NULL) {
		if (vextexID < pGraph->maxVertexCount) {
			if (pGraph->pVertex[vextexID] == NOT_USED) {
				pGraph->pVertex[vextexID] = USED;
				pGraph->currentVertexCount++;
			}
			else {
				printf("����, �̹� �����ϴ� ���[%d]\n", vextexID);
				ret = FAIL;
			}
		}
		else {
			printf("����, �ִ� ��� ���� �ʰ�[%d]",vextexID);
			ret = FAIL;
		}
	}
	return ret;
}

//���� ����ġ �߰�
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

//��� �� Ȯ��
int chechkVertexVaild(ArrayGraph *pGraph, int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= pGraph->maxVertexCount 
		|| pGraph->pVertex[vertexID] == NOT_USED) {
		printf("����, ��� ����[%d]\n",vertexID);
		ret = FAIL;

		return ret;
	}

	return ret;
}

//���� �߰�
int addEdgeAG(ArrayGraph * pGraph, int fromVertexID, int toVertexID){

	return addEdgewithWeightAG(pGraph,fromVertexID,toVertexID,USED);
}

//���� ����
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

//��� ����
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

//�׷��� ����
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
				printf("����, ������ �������� ����, in deleteArrayGraph()\n");
			}
			for (i = 0; i < pGraph->currentVertexCount; i++) {
				free(pGraph->pVertex[i]);
			}

		}
		else {
			printf("����, ��尡 �������� ����, in deleteArrayGraph()\n");
		}
		free(pGraph);
	}
	else {
		printf("����, �׷����� �������� ����, in deleteArrayGraph()\n");
	}
}

//�׷��� ���� Ȯ��
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

//�׷��� ���� Ȯ��
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
		printf("����, �׷��� ���� ��� ����\n");
	}
}










