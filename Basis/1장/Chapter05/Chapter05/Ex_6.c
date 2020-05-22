//문제에 하루 얼마나 피우는 지는 명시되어 있지 않으므로 하루 1갑로 계산
//1 개피 당 2분으로 했을 시 크게 변화가 없음

#include <stdio.h>

int main() {

	//원래 수명(년 단위), 한 개피 당 단축 수명(분 단위), 남은 수명(년 단위)
	const int Lifespan = 100;
	const int Cigarette_Per_Life = 2;

	int smoke_period = 0;
	float remaining_life = 0;

	printf("담배 핀 기간(년 단위) : ");
	scanf("%d", &smoke_period);

	//원래 수명(일 단위) - 줄어든 수명(일 단위) - 담배 핀 세월
	remaining_life = ((((Lifespan - 20) * 365) - ((smoke_period * 365 * 40) /3600)) / 365) - smoke_period;

	printf("남은 수명은 %.2f년 입니다.\n\n", remaining_life);


	return 0;
}