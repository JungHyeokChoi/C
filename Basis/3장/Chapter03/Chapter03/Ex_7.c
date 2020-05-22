#include <stdio.h>
#include <string.h>

int main() {

	FILE* stream_w;

	char stu_num[9];
	char name[8];
	int mid_score;
	int final_score;
	int attend;
	int report;
	int total;
	char* credit;
	
	stream_w = fopen("studen infomation.txt", "w");

	if (stream_w == NULL) {
		printf("���� ���� ����\n\n");
		return 0;
	}

	fprintf(stream_w, "%s	%s	%s       %s        %s        %s        %s       %s\n\n", "�й�", "�̸�", "�߰����", "�⸻���", "�⼮", "����", "����", "����");
	
	printf("�й� �Է¶��� 00�� �Է��Ͻø� ���� �˴ϴ�.\n");
	printf("���� ���� �� ������ �ȵ� ���� �ֽ��ϴ�.\n\n");

	while (1) {	
		printf("�й� : ");
		fscanf(stdin, "%s", stu_num);

		if (strstr(stu_num,"00"))
			break;

		printf("�̸� : ");
		fscanf(stdin, "%s", name);

		printf("�߰����, �⸻���, �⼮, ���� ���� : ");
		fscanf(stdin, "%d %d %d %d", &mid_score, &final_score, &attend, &report);
		total = mid_score + final_score + attend + report;


		if (total <= 100 && total >= 95)
			credit = "A+";
		else if (total < 95 && total >= 90)
			credit = "A";
		else if (total < 90 && total >= 85)
			credit = "B+";
		else if (total < 85 && total >= 80)
			credit = "B+";
		else if (total < 80 && total >= 75)
			credit = "C+";
		else if (total < 75 && total >= 70)
			credit = "C";
		else if (total < 70 && total >= 60)
			credit = "D";
		else
			credit = "F";

		fprintf(stream_w, "%s  %s	    %d	          %d                %d           %d          %d          %s\n", stu_num, name, mid_score, final_score, attend, report, total, credit);

		printf("\n");
	}
	

	fclose(stream_w);

	return 0;
}