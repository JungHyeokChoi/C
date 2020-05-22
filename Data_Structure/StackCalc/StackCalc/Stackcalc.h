#ifndef _STACK_CALC_
#define _STACK_CALC_

int pushLSExprtoken(LinkedStack *pStack, ExprToken data);
void calcExpr(ExprToken *pExprTokens, int tokenCount);
ExprToken* converStringToExprToken(char *array,int *arrayCount);
ExprToken *converInfixToPostfix(ExprToken *pExprtokens, int tokenCount, int *pRetTokenCount);
int inStackPrecedence(Precedence oper);
int outStackPrecedence(Precedence oper);
void printToken(ExprToken element);

#endif _STACK_CALC_
