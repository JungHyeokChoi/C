#ifndef  _POLYLIST_
#define _POLYLIST_

int addPolyNodeList(LinkedList* pList, float coef, int degree); // ���׽� �� �߰�
LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB); // ���׽� ����
LinkedList* polySubtraction(LinkedList* pListA, LinkedList* pListB); // ���׽� ����
void displayPolyList(LinkedList* pList); //���׽� Ȯ��

#endif _POLYLIST_
