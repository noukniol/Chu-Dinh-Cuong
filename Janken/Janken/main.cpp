#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MISENTAKU		0
#define NUM_OVER		3
#define RESULT_PATTERN	3
#define HAND_PATTERN	3
#define FIX_HAND		1

#define DRAW			0
#define	WIN				1
#define LOOSE			2

int checkHand[RESULT_PATTERN][RESULT_PATTERN] = {
	//Player|Computer�O�[(0) �`���L(1) �p�[(2)
	/*�O�[(0)*/		{ DRAW,		WIN,	LOOSE },
	/*�`���L(1)*/	{ LOOSE,	DRAW,	WIN },
	/*�p�[(2)*/		{ WIN,		LOOSE,	DRAW },
};
int main() {
	int input, player, computer;
	const char* message[] = { "��������","����","����" };
	const char* hand[] = { "�O�[","�`���L","�p�[" };
	int senseki[RESULT_PATTERN] = { NULL };

	while (true)
	{
		printf("\n�W�����P���Q�[���I\n");
		printf("0:���I���A1:�O�[�A2:�`���L�A3:�p�[ :->");
		scanf("%d", &input);

		if (input == MISENTAKU || input > NUM_OVER) {
			printf("�G���[\n");
			printf("�đI�����Ă�������!\n");
		}
		else {
			srand((unsigned int)time(NULL));
			player = input - FIX_HAND;
			computer = rand() % HAND_PATTERN;
			printf("�v�����[�̎�F%s\n�R���s���[�^�[�̎�F%s\n", hand[player], hand[computer]);

			int result = checkHand[player][computer];
			printf("%s\n", message[result]);

			senseki[result]++;
			printf("\n���݂̐�сF %d ���A%d �s�A%d ���������I\n",
				senseki[WIN], senseki[LOOSE], senseki[DRAW]);
		}

	}
	return 0;
}