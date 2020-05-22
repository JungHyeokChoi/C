#ifndef _GRAPH_SP_
#define _GRAPH_SP_

#define		MAX_INT		99999

//Dijstra �˰���
int *shortestPathDijstra(LinkedGraph* pGraph, int startVertexID);
int getEdgeWeight(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

//Floyd �˰���
int **shortestPathFloyd(LinkedGraph* pGraph);
void printMatrix(int **A, int maxNodeCount);

//���� ���ɼ�(���� ���⼺ �׷������� ���)
int **checkReachability(int **A,int maxNodeCount);

#endif
