#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum RESULT
{
	DRAW,
	WIN,
	LOOSE,
	RESULT_PARTEN
};
enum HAND
{
	NO_CHOOSE,
	ROCK = 0,
	SCISSORS,
	PAPER,
	HAND_PATTERN
};

HAND getHand(int move) {
	switch (move)
	{
	case 1:
		return ROCK;
		break;
	case 2:
		return SCISSORS;
		break;
	case 3:
		return PAPER;
		break;
	}
	return NO_CHOOSE;
}
int checkHand[HAND_PATTERN][HAND_PATTERN] = {
	//Player|Computer�O�[(0) �`���L(1) �p�[(2)
	/*�O�[(0)*/		{ DRAW,		WIN,	LOOSE },
	/*�`���L(1)*/	{ LOOSE,	DRAW,	WIN },
	/*�p�[(2)*/		{ WIN,		LOOSE,	DRAW },
};
int main() {
	int input, player, computer;
	const char* message[] = { "��������","����","����" };
	const char* hand[] = { "�O�[","�`���L","�p�[" };
	int senseki[RESULT_PARTEN] = { NULL };

	while (true)
	{
		printf("\n�W�����P���Q�[���I\n");
		printf("0:���I���A1:�O�[�A2:�`���L�A3:�p�[ :->");
		scanf("%d", &input);

		if (input <= NO_CHOOSE || input > HAND_PATTERN) {
			printf("�G���[\n");
			printf("�đI�����Ă�������!\n");
		}
		else {
			srand((unsigned int)time(NULL));
			player = getHand(input);
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