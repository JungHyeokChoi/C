#include <stdio.h>
#include <string.h>

struct student {
	char student_num[9];
	char name[5];
	int english_grade;
	int korean_grade;
};

int main() {

	char* p = NULL;
	char search[5] = "2010";

	struct student s1 = { "20107341","Kim",90,85 },
		s2 = { "20109762","Lee",85,60 },
		s3 = { "20117201","Choi",100,90 },
		s4 = { "20137852","Jung",50,40 };
	
	p = strstr(s1.student_num, search);
	
	if (p != NULL)
		printf("이름 : %s, 영어점수 : %d, 국어점수 : %d\n",s1.name,s1.english_grade,s1.korean_grade);

	p = strstr(s2.student_num, search);

	if (p != NULL)
		printf("이름 : %s, 영어점수 : %d, 국어점수 : %d\n", s2.name, s2.english_grade, s2.korean_grade);

	p = strstr(s3.student_num, search);

	if (p != NULL)
		printf("이름 : %s, 영어점수 : %d, 국어점수 : %d\n", s3.name, s3.english_grade, s3.korean_grade);

	p = strstr(s4.student_num, search);

	if (p != NULL)
		printf("이름 : %s, 영어점수 : %d, 국어점수 : %d\n", s4.name, s1.english_grade, s4.korean_grade);

	printf("\n");

	return 0;
}