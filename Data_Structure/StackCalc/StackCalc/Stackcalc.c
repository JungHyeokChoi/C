#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exprdef.h"
#include "Exprlinkedstack.h"
#include "Stackcalc.h"

//토큰 추가
int pushLSExprtoken(LinkedStack* pStack, ExprToken data){
	StackNode node = { 0, };
	node.data = data;

	return pushLS(pStack, node);
}

//토큰 연산(후위 표시)
void calcExpr(ExprToken* pExprTokens, int tokenCount){
	LinkedStack *pStack = NULL;
	StackNode *pNode1 = NULL, *pNode2 = NULL;
	Precedence tokenType;
	int i = 0;

	if (pExprTokens == NULL) {
		return;
	}

	pStack = createLinkedStack();
	if (pStack != NULL) {
		for (i = 0; i < tokenCount; i++) {
			tokenType = pExprTokens[i].type;

			if (tokenType == operand) {
				pushLSExprtoken(pStack, pExprTokens[i]);
			}
			else {
				pNode2 = popLS(pStack);
				if (pNode2 != NULL) {
					pNode1 = popLS(pStack);
					if (pNode1 != NULL) {
						float op1 = pNode1->data.value;
						float op2 = pNode2->data.value;

						ExprToken newToken;

						newToken.type = operand;
						switch (tokenType) {
						case plus:
							newToken.value = op1 + op2;
							break;
						case minus:
							newToken.value = op1 - op2;
							break;
						case times:
							newToken.value = op1 * op2;
							break;
						case divide:
							newToken.value = op1 / op2;
							break;
						}

						pushLSExprtoken(pStack, newToken);

						free(pNode1);
					}
					free(pNode2);
				}
			}
		}
		pNode1 = popLS(pStack);
		if (pNode1 != NULL) {
			printf("After calcExpr()\n\n");
			printf("수식 계산 결과 [%.1f]\n\n", pNode1->data.value);
			free(pNode1);
		}
		else {
			printf("오류, 수식에 오류가 있습니다.\n");
		}
		deleteLinkedStack(pStack);
	}
}

//String -> ExprTokens 변환
ExprToken* converStringToExprToken(char *array,int *arrayCount) {
	int i = 0, j = 0, tokenCount = 0;
	char *temp = NULL;

	ExprToken *pReturn = (ExprToken*)malloc(sizeof(ExprToken) * *arrayCount);

	for(i = 0; i < *arrayCount; i++){
		switch (array[i]) {
			case '(' :
				pReturn[tokenCount].type = lparen;
				pReturn[tokenCount].value = 0;
				tokenCount++;
				break;
			case ')' :
				pReturn[tokenCount].type = rparen;
				pReturn[tokenCount].value = 0;
				tokenCount++;
				break;
			case '*' :
				pReturn[tokenCount].type = times;
				pReturn[tokenCount].value = 0;
				tokenCount++;
				break;
			case '/' :
				pReturn[tokenCount].type = divide;
				pReturn[tokenCount].value = 0;
				tokenCount++;
				break;
			case '+' :
				pReturn[tokenCount].type = plus;
				pReturn[tokenCount].value = 0;
				tokenCount++;
				break;
			case '-' :
				pReturn[tokenCount].type = minus;
				pReturn[tokenCount].value = 0;
				tokenCount++;
				break;
			case ' ' :
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				temp = (char*)malloc(sizeof(char) * 10);

				for (j = 0; j < 10;) {
					if ((int)array[i + j] >= 48 && (int)array[i + j] < 58) {
						temp[j] = array[i + j];
						j++;
					}
					else {
						break;
					}
				}
				temp = (char*)realloc(temp, sizeof(char)* (j + 1));

				pReturn[tokenCount].type = operand;
				pReturn[tokenCount].value = atol(temp);
				tokenCount++;

				i = i + (j - 1);
				free(temp);
		}
		
	}
	pReturn = (ExprToken*)realloc(pReturn,sizeof(ExprToken) * tokenCount);

	*arrayCount = tokenCount;

	return pReturn;
}

//중위 표기 -> 후위 표기 변환
ExprToken *converInfixToPostfix(ExprToken *pExprtokens, int tokenCount, int *pRetTokenCount) {
	LinkedStack *pStack = NULL;
	ExprToken *pReturn = NULL;
	StackNode *pNode = NULL;
	Precedence tokenType;
	Precedence inStackTokenType;
	int i = 0, tokenCount_R = 0;

	if (pExprtokens == NULL) {
		return;
	}

	pStack = createLinkedStack();
	if (pStack != NULL) {
		pReturn = (ExprToken*)malloc(sizeof(ExprToken)*tokenCount);
		if (pReturn != NULL) {
			for (i = 0; i < tokenCount; i++) {
				tokenType = pExprtokens[i].type;
				switch (tokenType) {
				case operand:
					pReturn[tokenCount_R].type = operand;
					pReturn[tokenCount_R].value = pExprtokens[i].value;
					tokenCount_R++;
					break;
				case rparen:
					pNode = popLS(pStack);
					while (pNode != NULL && pNode->data.type != lparen) {
						pReturn[tokenCount_R].type = pNode->data.type;
						pReturn[tokenCount_R].value = pNode->data.value;
						tokenCount_R++;

						free(pNode);

						pNode = popLS(pStack);
					}
					if (pNode != NULL) {
						free(pNode);
					}
					break;
				default:
					while (isLinkedStackEmpty(pStack) == FALSE) {
						inStackTokenType = peekLS(pStack)->data.type;
						if (outStackPrecedence(tokenType) <= inStackPrecedence(inStackTokenType)) {
							pNode = popLS(pStack);
							if (pNode != NULL) {
								pReturn[tokenCount_R].type = pNode->data.type;
								pReturn[tokenCount_R].value = pNode->data.value;
								tokenCount_R++;
								free(pNode);
							}
						}
						else {
							break;
						}
					}
					pushLSExprtoken(pStack, pExprtokens[i]);
					break;
				}
			}
			while (isLinkedStackEmpty(pStack) == FALSE) {
				pNode = popLS(pStack);
				if (pNode != NULL) {
					pReturn[tokenCount_R].type = pNode->data.type;
					pReturn[tokenCount_R].value = pNode->data.value;
					tokenCount_R++;
					free(pNode);
				}
			}
		}
		
		deleteLinkedStack(pStack);
	}
	printf("After converInfixToPostfix()\n\n");
	printf("tokenCount_R : %d\n\n", tokenCount_R);

	for (i = 0; i < tokenCount_R; i++) {
		printToken(pReturn[i]);
	}
	printf("\n\n");

	*pRetTokenCount = tokenCount_R;
	return pReturn;
}

//스택 내부 우선순위
int inStackPrecedence(Precedence oper){
	switch (oper) {
		case lparen:
			return 0;
		case rparen:
			return 4;
		case times:
		case divide:
			return 2;
		case plus:
		case minus:
			return 1;
	}		
	return -1;
}

//스택 외부 우선순위
int outStackPrecedence(Precedence oper){
	switch (oper) {
		case lparen:
			return 5;
		case rparen:
			return 4;
		case times:
		case divide:
			return 2;
		case plus:
		case minus:
			return 1;
	}
	return -1;
}

//연산자 출력
void printToken(ExprToken element){
	switch (element.type) {
	case lparen:
		printf("( ");
		break;
	case rparen:
		printf(") ");
		break;
	case plus:
		printf("+ ");
		break;
	case minus:
		printf("- ");
		break;
	case times:
		printf("* ");
		break;
	case divide:
		printf("/ ");
		break;
	case operand:
		printf("%.0f ", element.value);
		break;
	}
}









