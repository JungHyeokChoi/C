#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include "Graphlinkedlist.h"

typedef struct LinkedGraphType {
	int maxVertexCount; //최대 노드 개수
	int currentVertexCount; // 현재 노드 개수
	int currentEdgeCount;
	int graphType; // 그래프 종류
	LinkedList **ppAdjEdge; // 간선 저장을 위한 연결 리스트의 배열
	int *pVertex; // 노드 저장을 위한 1차원 배열
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

//노드 존재 유무
#define USED	1
#define NOT_USED	0

//생성 성공 여부
#define SUCCESS	1
#define FAIL	0

#define	TRUE	1
#define	FALSE	0

//그래프 방향성
#define	GRAPH_UNDIRECTED	1 //방향
#define GRAPH_DIRECTED	2 // 무방향

#endif _COMMON_GRAPH_DEF_