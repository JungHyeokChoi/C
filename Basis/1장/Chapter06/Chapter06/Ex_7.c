#include <stdio.h>

#define Pi 3.14

int main() {

	double radius = 0;
	double area_of_circle, circumference;

	printf("���� ������(cm) : ");
	scanf("%lf", &radius);

	area_of_circle = Pi * radius *radius;
	circumference = 2 * Pi * radius;

	printf("���� ������ %.3f(������Ƽ����) �̸�, ���� �ѷ��� %.3f(��Ƽ����) �Դϴ�. \n\n", area_of_circle, circumference);


	return 0;
}