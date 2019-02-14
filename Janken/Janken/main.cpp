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

	char hand[4][10] = { "���I��","�O�[","�`���L","�p�[" };

	while (1)
	{
		printf("\n�W�����P���Q�[���I\n");
		printf("0:���I���A1:�O�[�A2:�`���L�A3:�p�[ :->");
		scanf("%d", &player);
		
		if (player == MISENTAKU) {
			printf("�đI�����Ă��������I\n");
		}
		else
		{
			srand((unsigned int)time(NULL));
			computer = rand() % 3 + 1;
			printf("�v�����[�̎�F %s \n�R���s���[�^�[�̎�F %s \n", hand[player], hand[computer]);

			CheckHand(player, computer);
		}
		printf("\n���݂̐�сF %d ���A%d ���A%d ���������I\n", win, loose, draw);

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
			printf("-------����-------\n");
			win++;
			break;
		case PA:
			printf("-------����-------\n");
			loose++;
			break;
		default:
			printf("------��������------\n");
			draw++;
			break;
		}
		break;
	case CHOKI:
		switch (comp)
		{
		case GU:
			printf("-------����-------\n");
			loose++;
			break;
		case PA:
			printf("-------����-------\n");
			win++;
			break;
		default:
			printf("------��������------\n");
			draw++;
			break;
		
		}
		break;
	case PA:
		switch (comp)
		{
		case GU:
			printf("-------����-------\n");
			win++;
			break;
		case CHOKI:
			printf("-------����-------\n");
			loose++;
			break;
		default:
			printf("------��������------\n");
			draw++;
			break;
		}
		break;
	}
}