#include <stdio.h>
#include <string.h>

void reverse_array(char* array, int string_length);

int main() {
	
	FILE* stream_w;
	FILE* stream_r;

	char buffer[50] = { 0, };

	stream_w = fopen("source.txt", "wt");

	if (stream_w == NULL) {
		printf("파일 열기 실패\n\n");
		return 0;
	}
		
	printf("데이터 입력 : ");
	fgets(buffer, sizeof(buffer), stdin);

	printf("데이터 쓰는 중...\n");
	fputs(buffer, stream_w);
	printf("데이터 쓰기 완료\n\n");

	fclose(stream_w);


	printf("데이터 읽기 시작\n");
	stream_r = fopen("source.txt", "rt");
	stream_w = fopen("dest.txt", "wt");

	if (stream_r == NULL || stream_w == NULL) {
		printf("파일 열기 실패\n\n");
		return 0;
	}

	printf("데이터 읽는 중..\n");
	
	fgets(buffer, sizeof(buffer), stream_r);
	reverse_array(buffer, strlen(buffer)-1);
	fputs(buffer, stream_w);

	printf("데이터 읽기 완료\n\n");

	fclose(stream_r);
	fclose(stream_w);

	return 0;
}


void reverse_array(char* array, int string_length)
{
	char temp;
	int byte = 5;
	int repeat;

	if(string_length % byte == 0)
		repeat = (string_length / byte);
	else
		repeat = (string_length / byte) + 1;


	for (int i = 0; i <= repeat*byte; i = i+byte) {
		for (int j = 0; j < (byte / 2); j++) {
			temp = array[i+j];
			array[i+j] = array[(i+(byte-1))-j];
			array[(i+(byte-1))-j] = temp;
		}
		
	}

	array[string_length] = '\0';

}


