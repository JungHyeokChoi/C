#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

//행렬 이중 리스트
typedef struct DoublyListNodeType {
	int column; // 행(column)
	int row;	// 열(row)
	int data; //데이터(data)

	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
}DoublyListNode;

//행렬 이중 리스트
typedef struct DoublyListType {
	int currentElementCount;
	int maxColumn;
	int maxRow;
	DoublyListNode headerNode;
}DoublyList;

DoublyList* createDoublyList(); // 리스트 생성
int addDLElement(DoublyList* pList, int position, DoublyListNode element); //노드 추가
int removeDLElement(DoublyList* pList, int position); //노드 삭제
DoublyListNode* getDLElement(DoublyList* pList,int position); //노드 데이터 확인
int getDoublyListLength(DoublyList* pList);//리스트 길이 확인
void displayDoublyList(DoublyList* pList);//리스트 확인
void clearDoublyList(DoublyList* pList);//리스트 초기화
void deleteDoublyList(DoublyList* pList);//리스트 삭제

#endif _DOUBLYLIS_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_LIST_DEF