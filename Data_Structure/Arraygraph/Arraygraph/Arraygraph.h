#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

typedef struct ArrayGraphType {
	int maxVertexCount; // 최대 노드 개수
	int currentVertexCount; // 현재 노드 개수
	int graphType; // 그래프 종류
	int **ppAdjEdge; // 간선 저장을 위한 2차원 배열
	int *pVertex; // 노드 저장을 위한 1차원 배열
}ArrayGraph;

ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);
int addVertexAG(ArrayGraph* pGraph,int vextexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int chechkVertexVaild(ArrayGraph* pGraph, int vertexID);
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int removeVertexAG(ArrayGraph* pGraph, int vertexID);
void deleteArrayGraph(ArrayGraph* pGraph);
int isEmptyAG(ArrayGraph* pGraph);
void displayArrayGraph(ArrayGraph* pGraph);

#endif _GRAPH_ADJMATRIX_

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