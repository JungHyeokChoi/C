#include <stdio.h>

struct student
{
	int studnet_num;
	char last_name[5];
	double height;
};

int main() {

	struct student stu = { 20101323,"Park",160.000000 };
	struct student* p = NULL;
	struct student** pp = NULL;

	p = &stu;
	pp = &p;

	printf("%d %s %.1lf\n", stu.studnet_num, stu.last_name, stu.height);
	printf("%d %s %.1lf\n", p->studnet_num, p->last_name, p->height);
	printf("%d %s %.1lf\n", (*pp)->studnet_num, (*pp)->last_name, (*pp)->height);

	return 0;
}