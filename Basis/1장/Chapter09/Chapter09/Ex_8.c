#include <stdio.h>

int Add(int i);

int main() {

	int input = 0, result = 0;

	printf("Input your number : ");
	scanf("%d", &input);

	result = Add(input);

	printf("1부터 %d까지의 합 = %d\n\n", input, result);

	return 0;
}

int Add(int i)
{
	if (i <= 1)
		return 1;

	return i + Add(i - 1);
}
