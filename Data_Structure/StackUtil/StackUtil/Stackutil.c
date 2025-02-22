#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedstack.h"
#include "Stackutil.h"

//역순 문자열
char* reverseString(char * pSource){
	char *pReturn = NULL;
	int i = 0, size = 0;
	LinkedStack *pStack = NULL;
	StackNode *pNode = NULL;

	if (pSource == NULL) {
		return NULL;
	}

	size = strlen(pSource);
	if (size == 0) {
		return NULL;
	}

	pReturn = (char*)malloc(sizeof(char)*size*(size+1));
	if (pReturn == NULL) {
		printf("오류, 메모리할당 reverseString()\n");
		return NULL;
	}

	pStack = createLinkedStack();
	if (pStack != NULL) {
		StackNode node;

		for (i = 0; i < size; i++) {
			node.data = pSource[i];
			pushLS(pStack, node);
		}

		for (i = 0; i < size; i++) {
			pNode = popLS(pStack);

			if (pNode != NULL) {
				pReturn[i] = pNode->data;
				free(pNode);
			}
			
		}
		pReturn[i] = '\0';

		deleteLinkedStack(pStack);
	}
	else {
		if (pReturn != NULL) {
			free(pReturn);
			pReturn = NULL;
		}
	}
	return pReturn;
}

//수식 괄호 검사
int checkBracketMatching(char * pSource){
	int ret = TRUE, i = 0, size = 0;
	char symbol = '\0', checkSymbol = '\0';
	LinkedStack *pStack = NULL;
	StackNode *pNode = NULL;

	if (pSource == NULL) {
		ret = TRUE;
		return ret;
	}

	size = strlen(pSource);
	if (size == 0) {
		ret = TRUE;
		return ret;
	}

	pStack = createLinkedStack();
	if (pStack != NULL) {
		StackNode node;
		
		for (i = 0; i < size && ret == TRUE; i++) {
			symbol = pSource[i];

			switch (symbol){
			case '(' :
			case '[' :
			case '{' :
				node.data = symbol;
				pushLS(pStack, node);
				break;

			case ')':
			case ']':
			case '}':
				pNode = popLS(pStack);
				if (pNode == NULL) {
					ret = FALSE;
					break;
				}
				else {
					checkSymbol = pNode->data;
					if ((symbol == ')' && checkSymbol == '(')
						|| (symbol == ']' && checkSymbol == '[')
						|| (symbol == '}' && checkSymbol == '{')) {

					}
					else {
						ret = FALSE;
					}

					free(pNode);
				}
				break;
			}
		}
		if (isLinkedStackEmpty(pStack) == FALSE) {
			ret = FALSE;
		}

		deleteLinkedStack(pStack);
	}
	else {
		printf("오류, LinkedStack이 NULL입니다, checkBracketMatching()\n");
		ret = FALSE;
	}

	return ret;
}
