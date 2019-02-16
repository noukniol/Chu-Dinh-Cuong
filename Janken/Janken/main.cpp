#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum MESSAGE {
	DRAW,LOOSE,WIN,OVER
};
void CheckHand(int player, int comp);

int senseki[3] = { 0,0,0 };

int main() {

	int player, computer;

	char hand[4][7] = { "未選択","グー","チョキ","パー" };

	while (1)
	{
		printf("\nジャンケンゲーム！\n");
		printf("0:未選択、1:グー、2:チョキ、3:パー :->");
		scanf("%d", &player);
		
		if (player == 0) {
			printf("再選択してください！\n");
		}
		else
		{
			srand((unsigned int)time(NULL));
			computer = rand() % 3 + 1;
			printf("プレヤーの手： %s \nコンピューターの手： %s \n", 
				hand[player], hand[computer]);

			CheckHand(player, computer);
		}

		if (player > OVER) {
			break;
		}
	}
	return 0;
}
void CheckHand(int player, int comp) {

	char message[3][9] = { "引き分け","負け","勝ち" };
	int result = (player - comp + 3) % 3;
	printf("%s", message[result]);
	
	senseki[result]++;
	printf("\n現在の戦績： %d 勝、%d 敗、%d 引き分け！\n", 
		senseki[WIN],senseki[LOOSE],senseki[DRAW]);
}