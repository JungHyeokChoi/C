#ifndef _GRAPH_MST_KRUSKAL_
#define _GRAPH_MST_KRUSKAL_

#include "Linkedgraph.h"
#include "Grapharrayheap.h"

LinkedGraph* mstKruskal(LinkedGraph* pGraph);
ArrayHeap* orderEdges(LinkedGraph* pGraph);
int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int checkEdge(LinkedGraph * pGraph, int fromVertexID, int toVertexID);

#endif _GRAPH_MST_KRUSKAL_

#ifndef _COMMON_GRAPHMST_DEF_
#define _COMMON_GRAPHMST_DEF_

#define VISITED		1
#define NOT_VISITED	0

#endif _COMMON_GRAPHMST_DEF_
