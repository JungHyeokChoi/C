#include <stdio.h>

int main() {
	
	FILE* stream_r;

	stream_r = fopen("score.txt", "rb");

	if (stream_r == NULL) {
		printf("���� ���� ����\n\n");
		return 0;
	}

	fseek(stream_r, 0, SEEK_END);

	printf("������ ũ�� : %dbyte \n\n", ftell(stream_r));

	fclose(stream_r);

	return 0;
}