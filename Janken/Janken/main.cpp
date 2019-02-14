#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum HAND
{
	MISENTAKU,
	GU,
	CHOKI,
	PA
};
void CheckHand(int player, int comp);

int win = 0, loose = 0, draw = 0;

int main() {

	int player, computer;

	char hand[4][10] = { "未選択","グー","チョキ","パー" };

	while (1)
	{
		printf("\nジャンケンゲーム！\n");
		printf("0:未選択、1:グー、2:チョキ、3:パー :->");
		scanf("%d", &player);
		
		if (player == MISENTAKU) {
			printf("再選択してください！\n");
		}
		else
		{
			srand((unsigned int)time(NULL));
			computer = rand() % 3 + 1;
			printf("プレヤーの手： %s \nコンピューターの手： %s \n", hand[player], hand[computer]);

			CheckHand(player, computer);
		}
		printf("\n現在の戦績： %d 勝、%d 負、%d 引き分け！\n", win, loose, draw);

		if (player > PA) {
			break;
		}
	}
	return 0;
}
void CheckHand(int player, int comp) {
	switch (player)
	{
	case GU:
		switch (comp)
		{
		
		case CHOKI:
			printf("-------勝ち-------\n");
			win++;
			break;
		case PA:
			printf("-------負け-------\n");
			loose++;
			break;
		default:
			printf("------引き分け------\n");
			draw++;
			break;
		}
		break;
	case CHOKI:
		switch (comp)
		{
		case GU:
			printf("-------負け-------\n");
			loose++;
			break;
		case PA:
			printf("-------勝ち-------\n");
			win++;
			break;
		default:
			printf("------引き分け------\n");
			draw++;
			break;
		
		}
		break;
	case PA:
		switch (comp)
		{
		case GU:
			printf("-------勝ち-------\n");
			win++;
			break;
		case CHOKI:
			printf("-------負け-------\n");
			loose++;
			break;
		default:
			printf("------引き分け------\n");
			draw++;
			break;
		}
		break;
	}
}