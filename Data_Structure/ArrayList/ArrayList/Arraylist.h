#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType {
	int data;
}ArrayListNode;

typedef struct ArrayListType {
	int maxElementCount;
	int currentElementCount;
	ArrayListNode *pElement;
}ArrayList;

ArrayList* createArrayList(int maxElementCount); //리스트 생성
void deleteArrayList(ArrayList* pList); // 리스트 삭제
int isArrayListFull(ArrayList* pList); // 원소 추가 가능 여부 판단
int addALElement(ArrayList* pList, int position, ArrayListNode element); // 원소 추가
int removeALElement(ArrayList* pList, int position); // 원소 삭제
ArrayListNode* getALElement(ArrayList* pList, int position); // 원소 반환
void displayArrayList(ArrayList* pList); // 리스트 순회
int getArrayListLength(ArrayList* pList); // 원소 개수 반환
int addALElementFirst(ArrayList* pList, ArrayListNode element); // 리스트 첫번째 원소 추가
int addALElementLast(ArrayList* pList, ArrayListNode element); // 리스트 마지막 원소 추가

#endif _ARRAYLIST_


#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMONE_LIST_DEF_