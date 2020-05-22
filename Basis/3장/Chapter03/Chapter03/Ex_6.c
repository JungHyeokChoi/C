#include <stdio.h>

int main() {
	
	FILE* stream_r;

	stream_r = fopen("score.txt", "rb");

	if (stream_r == NULL) {
		printf("파일 열기 오류\n\n");
		return 0;
	}

	fseek(stream_r, 0, SEEK_END);

	printf("파일의 크기 : %dbyte \n\n", ftell(stream_r));

	fclose(stream_r);

	return 0;
}