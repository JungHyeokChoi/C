#include <stdio.h>

int main() {

	int apartment[3][3] = {0,};
	int floor = 1, total_popul = 0;

	for (int i = 2; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			printf("%d�� %dȣ�� ������ �� �� �Դϱ�? : ", floor,j+1);
			scanf("%d", &apartment[i][j]);

			total_popul = total_popul + apartment[i][j];
		}

		floor++;
	}
	
	printf("��������Ʈ �� �ֹμ��� %d�� �Դϴ�.\n\n", total_popul);

	return 0;
}