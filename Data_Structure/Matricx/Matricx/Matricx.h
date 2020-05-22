#ifndef _MATRICXDOUBLYLIST_
#define _MATRICXDOUBLYLIST_

DoublyList* createMatricDoublyList(int maxColumn, int maxRow);// 행렬 리스트 추가
int addMatricxNodeDoublyList(DoublyList* pList, int column, int row, int data); // 행렬 원소 추가
DoublyList* matricxTransposed(DoublyList* pList); // 행렬 전치
void displayMatricxDoublyList(DoublyList* pList); // 행렬 확인

#endif	_MATRICXDOUBLYLIST_
