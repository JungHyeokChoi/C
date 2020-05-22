#ifndef _EXPR_DEF_
#define _EXPR_DEF_

//(, ), *, /, +. -, ¼ýÀÚ
typedef enum PrecedenceType{lparen,rparen,times,divide,plus,minus,operand}Precedence;

typedef struct ExprTokenType {
	float value;
	Precedence type;
}ExprToken;

#endif _EXPR_DEF_
