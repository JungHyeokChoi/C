#include <stdio.h>

int main() {

	FILE* stream_r;
	FILE* stream_w;

	char name[10];
	double kor, eng, math, total;


	stream_r = fopen("score.txt", "r");
	stream_w = fopen("add score.txt", "w");

	if (stream_r == NULL || stream_w == NULL) {
		printf("파일 열기 오류\n\n");
		return 0;
	}

	while (!feof(stream_r)) {
		fscanf(stream_r, "%s %lf %lf %lf \n", name, &kor, &eng, &math);
		total = kor + eng + math;
		fprintf(stream_w, "%s %.1lf \n", name, total);
	}

	fclose(stream_r);
	fclose(stream_w);

	return 0;
}