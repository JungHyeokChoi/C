#include <stdio.h>

int main() {
	
	FILE* stream;
	int result = 0;

	stream = fopen("99_fputs.txt", "w+");

	if (stream == NULL)
		printf("���� ���� ����\n\n");

	printf("������ �Է�\n");
	for (int i = 1; i <= 9; i++) {
		int input = 0;

		for (int j = 1; j <= 9; j++) {
			result = i * j;

			fputc((i+48), stream);
			input = 32;
			fputc(input, stream);
			input = 42;
			fputc(input, stream);
			input = 32;
			fputc(input, stream);
			fputc((j+48), stream);
			input = 32;
			fputc(input , stream);
			input = 61;
			fputc(input, stream);
			input = 32;
			fputc(input, stream);
		
			fprintf(stream, "%d", result);
			
			input = 13;
			fputc(input, stream);
			input = 10;
			fputc(input , stream);
		}
		input = 13;
		fputc(input, stream);
		input = 10;
		fputc(input, stream);
	}

	fclose(stream);

	printf("���� ���� �Ϸ�\n\n");

	return 0;
}