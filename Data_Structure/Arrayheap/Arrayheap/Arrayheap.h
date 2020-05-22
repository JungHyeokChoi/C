#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapElementType {
	int key;
	char data;
}HeapNode;

typedef struct ArrayHeapType {
	int maxElementCount;
	int currentElementCount;
	HeapNode *pElement;
}ArrayHeap;

ArrayHeap* createArrayHeap(int maxElementCount);
void insertMaxHeapAH(ArrayHeap* pHeap, HeapNode element);
void insertMinHeapAH(ArrayHeap* pHeap, HeapNode element);
HeapNode* deleteMaxHeapAH(ArrayHeap* pHeap);
HeapNode* deleteMinHeapAH(ArrayHeap* pHeap);
void deleteArrayHeap(ArrayHeap* pHeap);
void displayArrayHeap(ArrayHeap*	pHeap);

#endif _ARRAY_HEAP_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE	1
#define FALSE	0

#endif	_COMMON_TREE_DEF
