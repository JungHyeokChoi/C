#ifndef _ARRAR_STACK_
#define _ARRAY_STACK_

typedef struct ArrayStackNodeType {
	char data;
}ArrayStackNode;

typedef struct ArrayStackType {
	int maxElementCount;
	int currentElementCount;
	ArrayStackNode *pElement;
}ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAs(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAs(ArrayStack* pStack);
ArrayStackNode* peekAs(ArrayStack* pStack);
void deletArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
void displayArrayStack(ArrayStack* pStack);

#endif _ARRAY_STACK_

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_STACK_DEF_