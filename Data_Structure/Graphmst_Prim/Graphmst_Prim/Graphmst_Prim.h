#ifndef _GRAPH_MST_PRIM_
#define _GRAPH_MST_PRIM_

#include "Linkedgraph.h"
#include "Graphlinkedlist.h"
#include "Grapharrayheap.h"

typedef struct GraphEdgeType {
	int vertexIDFrom;
	int vertexIDTo;
	int weight;
	int edgeCount;
}GraphEdge;

LinkedGraph* mstPrim(LinkedGraph* pGraph, int startVertexID);
void getMinWeightEdge(LinkedGraph* pGraph, LinkedGraph* pMST, int mstVertexID, GraphEdge* pMinWeightEdge, ArrayHeap* pEdgeList);
int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int checkEdge(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

#define		MAX_INT		99999

#endif _GRAPH_MST_PRIM_

#ifndef _COMMON_GRAPHMST_DEF_
#define _COMMON_GRAPHMST_DEF_

#define VISITED		1
#define NOT_VISITED	0

#endif _COMMON_GRAPHMST_DEF_
