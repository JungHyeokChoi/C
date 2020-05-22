#include <stdio.h>

void alphabet_count(char* s, int length);

int main() {

	char array[100];

	printf("단어를 입력하세요 : ");
	gets(array);

	alphabet_count(array, strlen(array));

	return 0;
}

void alphabet_count(char* s, int length)
{
	int alphabet_count[26] = { 0, };

	for (int i = 0; i < length; i++) {
		switch (s[i]) {
			case 'A':
			case 'a':
				alphabet_count[0]++;
				break;
			case 'B':
			case 'b':
				alphabet_count[1]++;
				break;
			case 'C':
			case 'c':
				alphabet_count[2]++;
				break;
			case 'D':
			case 'd':
				alphabet_count[3]++;
				break;
			case 'E':
			case 'e':
				alphabet_count[4]++;
				break;
			case 'F':
			case 'f':
				alphabet_count[5]++;
				break;
			case 'G':
			case 'g':
				alphabet_count[6]++;
				break;
			case 'H':
			case 'h':
				alphabet_count[7]++;
				break;
			case 'I':
			case 'i':
				alphabet_count[8]++;
				break;
			case 'J':
			case 'j':
				alphabet_count[9]++;
			case 'K':
			case 'k':
				alphabet_count[10]++;
				break;
			case 'L':
			case 'l':
				alphabet_count[11]++;
				break;
			case 'M':
			case 'm':
				alphabet_count[12]++;
			case 'N':
			case 'n':
				alphabet_count[13]++;
				break;
			case 'O':
			case 'o':
				alphabet_count[14]++;
				break;
			case 'P':
			case 'p':
				alphabet_count[15]++;
				break;
			case 'Q':
			case 'q':
				alphabet_count[16]++;
				break;
			case 'R':
			case 'r':
				alphabet_count[17]++;
				break;
			case 'S':
			case 's':
				alphabet_count[18]++;
				break;
			case 'T':
			case 't':
				alphabet_count[19]++;
				break;
			case 'U':
			case 'u':
				alphabet_count[20]++;
				break;
			case 'V':
			case 'v':
				alphabet_count[21]++;
				break;
			case 'W':
			case 'w':
				alphabet_count[22]++;
				break;
			case 'X':
			case 'x':
				alphabet_count[23]++;
				break;
			case 'Y':
			case 'y':
				alphabet_count[24]++;
				break;
			case 'Z':
			case 'z':
				alphabet_count[25]++;
				break;
			default :
				break;

		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphabet_count[i] > 0)
			printf("%c : %d개\n", i + 97, alphabet_count[i]);
	}
		
}
