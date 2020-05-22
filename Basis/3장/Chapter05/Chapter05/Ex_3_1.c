void score(int korean, int english, int math) {
	double average;
	char grade;

	average = ((double)korean + (double)english + (double)math) / 3;

	if (average < 100 && average >= 90) {
		grade = 'A';
	}

	else if (average < 90 && average >= 80) {
		grade = 'B';
	}

	else if (average < 80 && average >= 70) {
		grade = 'C';
	}

	else {
		grade = 'F';
	}

	printf("Æò±Õ : %.2lf ÇĞÁ¡ : %c \n\n", average, grade);
}