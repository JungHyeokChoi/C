#ifndef _MATRICXDOUBLYLIST_
#define _MATRICXDOUBLYLIST_

DoublyList* createMatricDoublyList(int maxColumn, int maxRow);// ��� ����Ʈ �߰�
int addMatricxNodeDoublyList(DoublyList* pList, int column, int row, int data); // ��� ���� �߰�
DoublyList* matricxTransposed(DoublyList* pList); // ��� ��ġ
void displayMatricxDoublyList(DoublyList* pList); // ��� Ȯ��

#endif	_MATRICXDOUBLYLIST_
