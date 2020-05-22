#ifndef _GRAPH_ARRAY_HEAP_
#define _GRAPH_ARRAY_HEAP_

typedef struct HeapElementType {
	int fromVertexID;
	int toVertexID;
	int key;
}HeapNode;

typedef struct ArrayHeapType {
	int maxElementCount;
	int currentElementCount;
	HeapNode *pElement;
}ArrayHeap;

ArrayHeap* createArrayHeap(int maxElementCount);
void insertMinHeapAH(ArrayHeap* pHeap, HeapNode element);
HeapNode* deleteMinHeapAH(ArrayHeap* pHeap);
void deleteArrayHeap(ArrayHeap* pHeap);
void displayArrayHeap(ArrayHeap*	pHeap);

#endif _GRAPH_ARRAY_HEAP_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE	1
#define FALSE	0

#endif	_COMMON_TREE_DEF
