#ifndef _GRAPH_SP_
#define _GRAPH_SP_

#define		MAX_INT		99999

//Dijstra 알고리즘
int *shortestPathDijstra(LinkedGraph* pGraph, int startVertexID);
int getEdgeWeight(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

//Floyd 알고리즘
int **shortestPathFloyd(LinkedGraph* pGraph);
void printMatrix(int **A, int maxNodeCount);

//도달 가능성(보통 방향성 그래프에서 사용)
int **checkReachability(int **A,int maxNodeCount);

#endif
