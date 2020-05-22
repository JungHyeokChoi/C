#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exprdef.h"
#include "Exprlinkedstack.h"
#include "Stackcalc.h"


int main() {
	int i = 0;
	int tokenCount_A = 0, tokenCount_B = 0;
	char array[50];

	printf("수식을 입력하세요 : ");
	gets(array);
	printf("\n");
	
	//String -> ExprTokens 변환
	ExprToken *pExprTokens = (ExprToken*)malloc(sizeof(ExprToken) * 50);

	tokenCount_A = strlen(array);
	pExprTokens = converStringToExprToken(array, &tokenCount_A);

	pExprTokens = (ExprToken*)realloc(pExprTokens,sizeof(ExprToken) * tokenCount_A);

	printf("After converStringToExprToken()\n\n");
	printf("tokenCount_A : %d\n\n", tokenCount_A);

	for (i = 0; i < tokenCount_A; i++) {
		printToken(pExprTokens[i]);
	}
	printf("\n\n");


	//중위 표기 -> 후위 표기 변환
	pExprTokens = converInfixToPostfix(pExprTokens, tokenCount_A, &tokenCount_B);

	//토큰 연산(후위 표시)
	calcExpr(pExprTokens, tokenCount_B);

	return 0;
}