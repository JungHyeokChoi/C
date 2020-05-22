#include <stdio.h>

int main() {

	FILE* stream;
	int total = 0;

	stream = fopen("99_fprintf.txt", "w+");

	if (stream == NULL)
		printf("파일 열기 오류\n");

	for (int i = 1; i <= 9; i++) {
		fprintf(stream, "%d단\n\n", i);
		for (int j = 1; j <= 9; j++) {
			total = i * j;
			fprintf(stream, "%d * %d = %d\n",i,j,total);
		}
		fprintf(stream, "\n");
	}

	fclose(stream);

	printf("파일 쓰기 완료\n\n");

	return 0;
}