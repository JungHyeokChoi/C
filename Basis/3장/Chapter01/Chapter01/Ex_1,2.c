#include <stdio.h>

struct student
{
	int student_num;
	char blood_type;
	double eye_sight;
	int weight;
};

int main() {

	
	struct student s1,s2,s3,s4,s5;

	printf("학번, 혈액형, 시력, 몸무게를 순서대로 입력해 주세요. : ");
	scanf("%d %c %lf %d", &s1.student_num, &s1.blood_type, &s1.eye_sight, &s1.weight);

	printf("학번, 혈액형, 시력, 몸무게를 순서대로 입력해 주세요. : ");
	scanf("%d %c %lf %d", &s2.student_num, &s2.blood_type, &s2.eye_sight, &s2.weight);

	printf("학번, 혈액형, 시력, 몸무게를 순서대로 입력해 주세요. : ");
	scanf("%d %c %lf %d", &s3.student_num, &s3.blood_type, &s3.eye_sight, &s3.weight);

	printf("학번, 혈액형, 시력, 몸무게를 순서대로 입력해 주세요. : ");
	scanf("%d %c %lf %d", &s4.student_num, &s4.blood_type, &s4.eye_sight, &s4.weight);

	printf("학번, 혈액형, 시력, 몸무게를 순서대로 입력해 주세요. : ");
	scanf("%d %c %lf %d", &s5.student_num, &s5.blood_type, &s5.eye_sight, &s5.weight);

	printf("\n");

	printf("S1  학번 : %d, 혈액형 : %c, 시력 : %.1lf, 몸무게 : %d\n", s1.student_num, s1.blood_type, s1.eye_sight, s1.weight);
	printf("S2  학번 : %d, 혈액형 : %c, 시력 : %.1lf, 몸무게 : %d\n", s2.student_num, s2.blood_type, s2.eye_sight, s2.weight);
	printf("S3  학번 : %d, 혈액형 : %c, 시력 : %.1lf, 몸무게 : %d\n", s3.student_num, s3.blood_type, s3.eye_sight, s3.weight);
	printf("S4  학번 : %d, 혈액형 : %c, 시력 : %.1lf, 몸무게 : %d\n", s4.student_num, s4.blood_type, s4.eye_sight, s4.weight);
	printf("S5  학번 : %d, 혈액형 : %c, 시력 : %.1lf, 몸무게 : %d\n\n", s5.student_num, s5.blood_type, s5.eye_sight, s5.weight);

	return 0;
}