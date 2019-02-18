#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MISENTAKU		0
#define RESULT_PATTERN	3
#define HAND_PATTERN	3
#define FIX_HAND		1
#define NUM_OVER		HAND_PATTERN

#define DRAW			0
#define	WIN				1
#define LOOSE			2

int checkHand[RESULT_PATTERN][RESULT_PATTERN] = {
	//Player|Computerグー(0) チョキ(1) パー(2)
	/*グー(0)*/		{ DRAW,		WIN,	LOOSE },
	/*チョキ(1)*/	{ LOOSE,	DRAW,	WIN },
	/*パー(2)*/		{ WIN,		LOOSE,	DRAW },
};
int main() {
	int input, player, computer;
	const char* message[] = { "引き分け","勝ち","負け" };
	const char* hand[] = { "グー","チョキ","パー" };
	int senseki[RESULT_PATTERN] = { NULL };

	while (true)
	{
		printf("\nジャンケンゲーム！\n");
		printf("0:未選択、1:グー、2:チョキ、3:パー :->");
		scanf("%d", &input);

		if (input == MISENTAKU || input > NUM_OVER) {
			printf("エラー\n");
			printf("再選択してください!\n");
		}
		else {
			srand((unsigned int)time(NULL));
			player = input - FIX_HAND;
			computer = rand() % HAND_PATTERN;
			printf("プレヤーの手：%s\nコンピューターの手：%s\n", hand[player], hand[computer]);

			int result = checkHand[player][computer];
			printf("%s\n", message[result]);

			senseki[result]++;
			printf("\n現在の戦績： %d 勝、%d 敗、%d 引き分け！\n",
				senseki[WIN], senseki[LOOSE], senseki[DRAW]);
		}

	}
	return 0;
}