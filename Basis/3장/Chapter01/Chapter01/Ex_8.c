#include <stdio.h>

struct student {
	char last_name[4];
	int grade;
	struct student* left_link;
	struct student* right_link;
};

int main() {

	struct student stu1 = { "Kim",90,NULL,NULL }, stu2 = { "Lee",80,NULL,NULL }, stu3 = { "Goo",60,NULL,NULL };
	
	stu1.left_link = &stu2;
	stu1.right_link = &stu3;

	printf("stu1   %s  %d\n", stu1.last_name, stu1.grade);
	printf("stu2   %s  %d\n", stu1.left_link->last_name, stu1.left_link->grade);
	printf("stu3   %s  %d\n\n", stu1.right_link->last_name, stu1.right_link->grade);

	return 0;
}