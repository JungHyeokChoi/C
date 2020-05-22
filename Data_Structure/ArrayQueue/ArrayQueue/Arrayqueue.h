#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

typedef struct ArrayQueueNodeType {
	char element;
}ArrayQueueNode;

typedef struct ArrayQueueType {
	int maxElementCount;
	int currentElementCount;
	int front;
	int rear;
	ArrayQueueNode *pElement;
}ArrayQueue;


ArrayQueue *createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);
void displayArrayQueue(ArrayQueue* pQueue);
int enqueueAQChar(ArrayQueue* pQueue, char element);

#endif _ARRAY_QUEUE_

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_QUEUE_DEF_