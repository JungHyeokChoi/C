#include <stdio.h>
#include <string.h>

void ascending(char (*p)[10],int word_count);

int main() {

	char word[10][10];
	int i = 0;
	
	printf("입력을 종료하려면 그냥 엔터를 누르세요.\n");
	for (i = 0; i < 10; i++) {
		printf("%d번째? ", i+1);
		gets(word+i);

		if ((int)word[i][0] == 0)
			break;
	}

	ascending(word,i);
	
	return 0;
}


void ascending(char (*p)[10],int word_count)
{
	char* result[10];
	
	for (int j = 97; j < 123; j++) {
		for (int i = 0; i < word_count; i++) {
			if (j == p[i][0]) {
				result[i] = &p[i];
				printf("%s ", result[i]);
			}
		}
		
	}

	printf("\n\n");

	/*
	for (int i = 0; i < word_count; i++) {
		printf("%s %x %x\n ",result[i],result[i],&p[i]);
	}
	*/	
}
