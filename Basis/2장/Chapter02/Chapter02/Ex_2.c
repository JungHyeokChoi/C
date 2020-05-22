#include <stdio.h>

int main() {

	int apartment[3][3] = {0,};
	int floor = 1, total_popul = 0;

	for (int i = 2; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			printf("%d층 %d호의 가족은 몇 명 입니까? : ", floor,j+1);
			scanf("%d", &apartment[i][j]);

			total_popul = total_popul + apartment[i][j];
		}

		floor++;
	}
	
	printf("열혈아파트 총 주민수는 %d명 입니다.\n\n", total_popul);

	return 0;
}