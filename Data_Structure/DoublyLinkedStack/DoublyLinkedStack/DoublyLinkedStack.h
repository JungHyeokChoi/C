#ifndef _DOUBLYLINKEDSTACK_
#define _DOUBLYLINKEDSTACK_

typedef struct DoublyLinkedStackNodeType {
	char data;
	struct DoublyLinkedStackNodeType* pTLink;
	struct DoublyLinkedStackNodeType* pBLink;
}DoublyLinkedStackNode;

typedef struct DoublyLinkedStackType {
	int currentElemnetCount;
	DoublyLinkedStackNode* pTopElement;
}DoublyLinkedStack;

DoublyLinkedStack* createDLStack();
int pushDLS(DoublyLinkedStack* pStack, DoublyLinkedStackNode element);
DoublyLinkedStackNode* popDLS(DoublyLinkedStack* pStack);
DoublyLinkedStackNode* peekDLS(DoublyLinkedStack* pStack);
void deleteDLStack(DoublyLinkedStack* pStack);
int isDLStackFull(DoublyLinkedStack* pStack);
int isDLStackEmpty(DoublyLinkedStack* pStack);
void displayDLStack(DoublyLinkedStack* pStack);

#endif _DOUBLYLINKEDSTACK_

#ifndef _COMMON_DOUBLYSTACK_DEF_
#define _COMMON_DOUBLYSTACK_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_DOUBLYSTACK_DEF_