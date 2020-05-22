#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

typedef struct ArrayGraphType {
	int maxVertexCount; // �ִ� ��� ����
	int currentVertexCount; // ���� ��� ����
	int graphType; // �׷��� ����
	int **ppAdjEdge; // ���� ������ ���� 2���� �迭
	int *pVertex; // ��� ������ ���� 1���� �迭
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