#include <stdio.h>

int main() {

	int input = 0;
	int i = 0;

	printf("3ÀÚ¸® ½ÊÁø¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ");
	scanf("%d", &input);

	for (i = 1; ; i++) {
		input = input - 100;

		if (input < 100)
			break;
	}

	if(i % 2 == 0)
		printf("%d : Â¦¼ö ",i);
	else
		printf("%d : È¦¼ö ", i);


	for (i= 1; ; i++) {
		input = input - 10;

		if (input < 10)
			break;
	}

	if (i % 2 == 0)
		printf("%d : Â¦¼ö ", i);
	else
		printf("%d : È¦¼ö ", i);


	if(input % 2 == 0)
		printf("%d : Â¦¼ö\n\n", input);
	else
		printf("%d : È¦¼ö\n\n", input);

	return 0;
}