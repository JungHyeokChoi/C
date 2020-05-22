#include <stdio.h>
#include "Ex_1.h"

int main() {

	int a, b;

	printf("µÎ ¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ");
	scanf("%d %d", &a, &b);

	printf("ÇÕ : %d \nÂ÷ : %d \n°ö¼À : %d \n³ª´°¼À : %lf\n\n", add(a, b), subtraction(a,b), multiply(a,b), divide((double)a, (double)b));

	return 0;
}