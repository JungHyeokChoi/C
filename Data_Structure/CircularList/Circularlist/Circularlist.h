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

CircularList* createCircularList(); // ����Ʈ ����
int addCLElement(CircularList* pList, int position, CircularListNode element); // ��� �߰�
int removeCLElement(CircularList* pList, int position); //��� ����
CircularListNode* getCLElement(CircularList* pList, int position); // ��� ������ Ȯ��
void displayCircularList(CircularList* pList); // ����Ʈ Ȯ��
int getCircularListLength(CircularList* pList); // ����Ʈ ���� Ȯ��
void deleteCircularList(CircularList* pList); // ����Ʈ ����
void clearCircularList(CircularList* pList); // ����Ʈ �ʱ�ȭ

#endif _CIRCULARLIST_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_LIST_DEF