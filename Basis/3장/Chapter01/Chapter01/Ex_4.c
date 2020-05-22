#include <stdio.h>

struct point
{
	int x;
	int y;
};

int main() {

	struct point s1 = { 10,10 };
	struct point* p = NULL;

	p = &s1;

	//*p.x 와 p->x는 같은 뜻
	printf("%d %d\n", p->x, p->y);
	printf("%d %d\n\n", s1.x, s1.y);
	
	return 0;
}