#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include "Graphlinkedlist.h"

typedef struct LinkedGraphType {
	int maxVertexCount; //�ִ� ��� ����
	int currentVertexCount; // ���� ��� ����
	int currentEdgeCount;
	int graphType; // �׷��� ����
	LinkedList **ppAdjEdge; // ���� ������ ���� ���� ����Ʈ�� �迭
	int *pVertex; // ��� ������ ���� 1���� �迭
}LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);
int addVertexLG(LinkedGraph* pGraph, int vertexID);
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addLLElementForVertex(LinkedList* pList, int position, GraphVertex vertex);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int removeVertexLG(LinkedGraph* pGraph, int vertexID);
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedGraph* pGraph, LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);
int isEmptyLG(LinkedGraph* pGraph);
void deleteLinkedGraph(LinkedGraph* pGraph);
void displayLinkedGraph(LinkedGraph* pGraph);

#endif _GRAPH_ADJLIST_


#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

//��� ���� ����
#define USED	1
#define NOT_USED	0

//���� ���� ����
#define SUCCESS	1
#define FAIL	0

#define	TRUE	1
#define	FALSE	0

//�׷��� ���⼺
#define	GRAPH_UNDIRECTED	1 //����
#define GRAPH_DIRECTED	2 // ������

#endif _COMMON_GRAPH_DEF_