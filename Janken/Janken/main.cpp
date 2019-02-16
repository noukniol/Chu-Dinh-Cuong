#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum MESSAGE {
	DRAW,LOOSE,WIN,OVER
};
void CheckHand(int player, int comp);

int win = 0, loose = 0, draw = 0;

int main() {

	int player, computer;

	char hand[4][7] = { "���I��","�O�[","�`���L","�p�[" };

	while (1)
	{
		printf("\n�W�����P���Q�[���I\n");
		printf("0:���I���A1:�O�[�A2:�`���L�A3:�p�[ :->");
		scanf("%d", &player);
		
		if (player == 0) {
			printf("�đI�����Ă��������I\n");
		}
		else
		{
			srand((unsigned int)time(NULL));
			computer = rand() % 3 + 1;
			printf("�v�����[�̎�F %s \n�R���s���[�^�[�̎�F %s \n", hand[player], hand[computer]);

			CheckHand(player, computer);
		}
		printf("\n���݂̐�сF %d ���A%d �s�A%d ���������I\n", win, loose, draw);

		if (player > OVER) {
			break;
		}
	}
	return 0;
}
void CheckHand(int player, int comp) {

	char message[3][9] = { "��������","����","����" };
	int result = (player - comp + 3) % 3;
	printf("%s", message[result]);

	switch (result)
	{
	case DRAW:
		draw++;
		break;
	case LOOSE:
		loose++;
		break;
	case WIN:
		win++;
		break;
	}
}