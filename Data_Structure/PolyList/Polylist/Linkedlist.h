#ifndef _LINKEDLIST_
#define _LINKEDLIST_

/* 일반 리스트
typedef struct ListNodeType {
	int data;
	struct ListNodeType* pLink;
}ListNode;
*/

//다항식 리스트
typedef struct ListNodeType {
	float coef; // 항(term)의 계수
	int	degree; // 항(term)의 차수

	struct ListNodeType* pLink;
}ListNode;

typedef struct LinkedListType {
	int currentElementCount;
	ListNode headerNode;
}LinkedList;

LinkedList* createLinkedList(); //일반 연결 리스트 생성
int addLLElement(LinkedList* pList, int position, ListNode element); // 노드 추가
int removeLLElement(LinkedList* pList, int position); // 노드 삭제
ListNode* getLLElement(LinkedList* pList, int position); // 노드 반환

void clearLinkedList(LinkedList* pList); // 데이터 초기화
int getLinkedListLengh(LinkedList* pList); // 노드 개수 반환
void deleteLinkedList(LinkedList* pList); // 리스트 삭제
int isEmpty(LinkedList* pList); // 리스트 공백 확인
void displayLinkedList(LinkedList* pList); // 리스트 확인

#endif _LINKEDLIST_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_LIST_DEF_
