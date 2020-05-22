#include <stdio.h>

#define Pi 3.14

int main() {

	double radius = 0;
	double area_of_circle, circumference;

	printf("원의 반지름(cm) : ");
	scanf("%lf", &radius);

	area_of_circle = Pi * radius *radius;
	circumference = 2 * Pi * radius;

	printf("원의 면적은 %.3f(제곱센티미터) 이며, 원의 둘레는 %.3f(센티미터) 입니다. \n\n", area_of_circle, circumference);


	return 0;
}