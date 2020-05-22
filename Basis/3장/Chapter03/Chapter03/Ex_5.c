#include <stdio.h>

void search(FILE* r);

int main() {

	FILE* stream_r;
	FILE* stream_w;

	char search_name[10], temp_1[10];
	double search_total, temp_2;

	stream_r = fopen("add score.txt", "r");

	printf("찾을 사람의 번호,이름을 입력해 주세요.(Ex 1.기성용) : ");
	scanf("%s", search_name);

	while (!feof(stream_r)) {
		fscanf(stream_r, "%s %lf", temp_1, &temp_2);

		if (strstr(temp_1, search_name) != NULL)
			fprintf(stdout, "%s %.1lf\n\n", temp_1, temp_2);
	}

	fclose(stream_r);

	return 0;
}