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

	printf("�й�, ������, �÷�, �����Ը� ������� �Է��� �ּ���. : ");
	scanf("%d %c %lf %d", &s1.student_num, &s1.blood_type, &s1.eye_sight, &s1.weight);

	printf("�й�, ������, �÷�, �����Ը� ������� �Է��� �ּ���. : ");
	scanf("%d %c %lf %d", &s2.student_num, &s2.blood_type, &s2.eye_sight, &s2.weight);

	printf("�й�, ������, �÷�, �����Ը� ������� �Է��� �ּ���. : ");
	scanf("%d %c %lf %d", &s3.student_num, &s3.blood_type, &s3.eye_sight, &s3.weight);

	printf("�й�, ������, �÷�, �����Ը� ������� �Է��� �ּ���. : ");
	scanf("%d %c %lf %d", &s4.student_num, &s4.blood_type, &s4.eye_sight, &s4.weight);

	printf("�й�, ������, �÷�, �����Ը� ������� �Է��� �ּ���. : ");
	scanf("%d %c %lf %d", &s5.student_num, &s5.blood_type, &s5.eye_sight, &s5.weight);

	printf("\n");

	printf("S1  �й� : %d, ������ : %c, �÷� : %.1lf, ������ : %d\n", s1.student_num, s1.blood_type, s1.eye_sight, s1.weight);
	printf("S2  �й� : %d, ������ : %c, �÷� : %.1lf, ������ : %d\n", s2.student_num, s2.blood_type, s2.eye_sight, s2.weight);
	printf("S3  �й� : %d, ������ : %c, �÷� : %.1lf, ������ : %d\n", s3.student_num, s3.blood_type, s3.eye_sight, s3.weight);
	printf("S4  �й� : %d, ������ : %c, �÷� : %.1lf, ������ : %d\n", s4.student_num, s4.blood_type, s4.eye_sight, s4.weight);
	printf("S5  �й� : %d, ������ : %c, �÷� : %.1lf, ������ : %d\n\n", s5.student_num, s5.blood_type, s5.eye_sight, s5.weight);

	return 0;
}