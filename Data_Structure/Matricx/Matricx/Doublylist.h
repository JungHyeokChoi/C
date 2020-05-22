#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

//��� ���� ����Ʈ
typedef struct DoublyListNodeType {
	int column; // ��(column)
	int row;	// ��(row)
	int data; //������(data)

	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
}DoublyListNode;

//��� ���� ����Ʈ
typedef struct DoublyListType {
	int currentElementCount;
	int maxColumn;
	int maxRow;
	DoublyListNode headerNode;
}DoublyList;

DoublyList* createDoublyList(); // ����Ʈ ����
int addDLElement(DoublyList* pList, int position, DoublyListNode element); //��� �߰�
int removeDLElement(DoublyList* pList, int position); //��� ����
DoublyListNode* getDLElement(DoublyList* pList,int position); //��� ������ Ȯ��
int getDoublyListLength(DoublyList* pList);//����Ʈ ���� Ȯ��
void displayDoublyList(DoublyList* pList);//����Ʈ Ȯ��
void clearDoublyList(DoublyList* pList);//����Ʈ �ʱ�ȭ
void deleteDoublyList(DoublyList* pList);//����Ʈ ����

#endif _DOUBLYLIS_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_LIST_DEF