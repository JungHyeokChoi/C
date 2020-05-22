#include <stdio.h>

void func1(struct point a);
void func2(struct point* b);

struct point {
	int x;
	int y;
};

int main() {

	struct point p1 = { 10,10 };
	struct point p2 = { 20,20 };

	func1(p1);
	func2(&p2);

	return 0;
}

void func1(struct point a)
{
	printf("%d %d\n", a.x, a.y);

}

void func2(struct point* b)
{
	printf("%d %d\n\n", b->x, b->y);
}
