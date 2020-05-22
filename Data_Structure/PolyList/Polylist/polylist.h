#ifndef  _POLYLIST_
#define _POLYLIST_

int addPolyNodeList(LinkedList* pList, float coef, int degree); // 다항식 항 추가
LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB); // 다항식 덧셈
LinkedList* polySubtraction(LinkedList* pListA, LinkedList* pListB); // 다항식 뺄셈
void displayPolyList(LinkedList* pList); //다항식 확인

#endif _POLYLIST_
