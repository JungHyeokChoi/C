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

ArrayList* createArrayList(int maxElementCount); //����Ʈ ����
void deleteArrayList(ArrayList* pList); // ����Ʈ ����
int isArrayListFull(ArrayList* pList); // ���� �߰� ���� ���� �Ǵ�
int addALElement(ArrayList* pList, int position, ArrayListNode element); // ���� �߰�
int removeALElement(ArrayList* pList, int position); // ���� ����
ArrayListNode* getALElement(ArrayList* pList, int position); // ���� ��ȯ
void displayArrayList(ArrayList* pList); // ����Ʈ ��ȸ
int getArrayListLength(ArrayList* pList); // ���� ���� ��ȯ
int addALElementFirst(ArrayList* pList, ArrayListNode element); // ����Ʈ ù��° ���� �߰�
int addALElementLast(ArrayList* pList, ArrayListNode element); // ����Ʈ ������ ���� �߰�

#endif _ARRAYLIST_


#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMONE_LIST_DEF_