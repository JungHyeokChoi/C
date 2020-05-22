#ifndef _LINKED_HEAP_
#define _LINKED_HEAP_

typedef struct LinkedHeapNodeType {
	int key;
	char data;

	struct LinkedHeapNodeType* pLeftChild;
	struct LinkedHeapNodeType* pRightChild;
}LinkedHeapNode;

typedef struct LinkedHeapType {
	int currentElementCount;

	LinkedHeapNode* pRootNode;
}LinkedHeap;

LinkedHeap* createLinkedHeap();
int insertMaxHeapLH(LinkedHeap* pMaxHeap, LinkedHeapNode element);
int insertMinHeapLH(LinkedHeap* pMinHeap, LinkedHeapNode element);
int deleteMaxHeapLH(LinkedHeap* pMaxHeap);
int deleteMinHeapLH(LinkedHeap* pMinHeap);
void deleteLinkedHeap(LinkedHeap* pHeap);
void deleteLinkedHeapNode(LinkedHeapNode* pNode);
void displayLinkedHeap(LinkedHeap* pHeap);
void displayLinkedHeapNode(LinkedHeapNode* pNode, int level, char type);

#endif _LINKED_HEAP_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define	TRUE	1
#define FALSE	0

#endif _COMMON_TREE_DEF_