#include <stdio.h>

int main() {

	int grade[10] = { 100,90,75,80,30,45,23,89,55,79 };
	int total_score = 0;
	double average = 0.00;

	for (int i = 0; i < 10; i++)
		total_score = total_score + grade[i];

	average = (double)total_score / 10.0;

	printf("10¸íÀÇ ÃÑÁ¡ : %d, Æò±Õ %.2lf\n\n",total_score, average);

	return 0;
}