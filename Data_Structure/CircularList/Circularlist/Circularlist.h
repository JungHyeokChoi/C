#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

typedef struct CircularListNodeType {
	int data;
	struct CircularListNodeType* pLink;
}CircularListNode;

typedef struct CircularListType {
	int currentElementCount;
	CircularListNode headerNode;
}CircularList;

CircularList* createCircularList(); // 리스트 생성
int addCLElement(CircularList* pList, int position, CircularListNode element); // 노드 추가
int removeCLElement(CircularList* pList, int position); //노드 제거
CircularListNode* getCLElement(CircularList* pList, int position); // 노드 데이터 확인
void displayCircularList(CircularList* pList); // 리스트 확인
int getCircularListLength(CircularList* pList); // 리스트 길이 확인
void deleteCircularList(CircularList* pList); // 리스트 삭제
void clearCircularList(CircularList* pList); // 리스트 초기화

#endif _CIRCULARLIST_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_LIST_DEF