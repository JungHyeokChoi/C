//������ �Ϸ� �󸶳� �ǿ�� ���� ��õǾ� ���� �����Ƿ� �Ϸ� 1���� ���
//1 ���� �� 2������ ���� �� ũ�� ��ȭ�� ����

#include <stdio.h>

int main() {

	//���� ����(�� ����), �� ���� �� ���� ����(�� ����), ���� ����(�� ����)
	const int Lifespan = 100;
	const int Cigarette_Per_Life = 2;

	int smoke_period = 0;
	float remaining_life = 0;

	printf("��� �� �Ⱓ(�� ����) : ");
	scanf("%d", &smoke_period);

	//���� ����(�� ����) - �پ�� ����(�� ����) - ��� �� ����
	remaining_life = ((((Lifespan - 20) * 365) - ((smoke_period * 365 * 40) /3600)) / 365) - smoke_period;

	printf("���� ������ %.2f�� �Դϴ�.\n\n", remaining_life);


	return 0;
}