#ifndef _GRAPH_TRAVERSAL_
#define _GRAPH_TRAVERSAL_

#include "Linkedstack.h"
#include "Linkedgraph.h"
#include "Linkedqueue.h"

int pushLSForDFS(LinkedStack* pStack, int nodeID);
int enqueueLQFofBFS(LinkedQueue* pQueue, int nodeID);
void traversalDFS(LinkedGraph* pGraph, int startvertexID);
void traversalBFS(LinkedGraph* pGraph, int startvertexID);

#endif _GRAPH_TRAVERSAL_