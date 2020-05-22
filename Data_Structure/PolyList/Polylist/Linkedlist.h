#ifndef _LINKEDLIST_
#define _LINKEDLIST_

/* �Ϲ� ����Ʈ
typedef struct ListNodeType {
	int data;
	struct ListNodeType* pLink;
}ListNode;
*/

//���׽� ����Ʈ
typedef struct ListNodeType {
	float coef; // ��(term)�� ���
	int	degree; // ��(term)�� ����

	struct ListNodeType* pLink;
}ListNode;

typedef struct LinkedListType {
	int currentElementCount;
	ListNode headerNode;
}LinkedList;

LinkedList* createLinkedList(); //�Ϲ� ���� ����Ʈ ����
int addLLElement(LinkedList* pList, int position, ListNode element); // ��� �߰�
int removeLLElement(LinkedList* pList, int position); // ��� ����
ListNode* getLLElement(LinkedList* pList, int position); // ��� ��ȯ

void clearLinkedList(LinkedList* pList); // ������ �ʱ�ȭ
int getLinkedListLengh(LinkedList* pList); // ��� ���� ��ȯ
void deleteLinkedList(LinkedList* pList); // ����Ʈ ����
int isEmpty(LinkedList* pList); // ����Ʈ ���� Ȯ��
void displayLinkedList(LinkedList* pList); // ����Ʈ Ȯ��

#endif _LINKEDLIST_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_LIST_DEF_
