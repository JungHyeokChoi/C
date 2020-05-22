#ifndef _LINKED_DEQUE_
#define _LINKDE_DEQUE_

typedef struct DequeNodeType {
	char data;
	struct DequeNodeType* pRLink; // ¾Õ
	struct DequeNodeType* pLLink; // µÚ 
}DequeNode;

typedef struct LinkedDequeType {
	int currentElementCount;
	DequeNode* pFrontNode;
	DequeNode* pRearNode;
}LinkedDeque;

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);
void displayLinkedDeque(LinkedDeque* pDeque);
int insertFrontLDchar(LinkedDeque* pDeque, char data);
int insertRearLDchar(LinkedDeque* pDeque, char data);

#endif _LINKED_DEQUE_

#ifndef _COMMON_DEQUE_DEF_
#define _COMMON_DEQUE_DEF

#define TRUE	1
#define FALSE	0

#endif _COMMON_DEQUE_DEF_