//이름: 김윤진
//문제7: 체크 확인(Check the Check)

#define _CRT_SECURE_NO_WARNINGS

#define SIZE 8
#define true 1
#define false 0

#include <string.h>
#include <stdio.h>

char board[SIZE][SIZE + 1];

void check(int *check);
void turn();
char switch_case(char);
int look_for_K(int istart, int jstart, int di, int dj);

void main() {

	int game = 0;	//game횟수 -> 출력 위해 필요
	int num = 0;	//체스판의'.'문자 개수-> 체스판이 '.'문자만으로 구성되면 종료
	int check_whiteK, check_blackK;

	while (true)
	{
		num = 0;

		for (int i = 0; i < SIZE; i++)
		{
			if (!strcmp(gets(board[i]), "........"))
				num++;
		}

		if (num == SIZE)  //모든 체스판이 '.'문자 만으로 구성되면 종료
			break;

		game = game + 1;
		check_whiteK = false;
		check_blackK = false;

		check(&check_whiteK);

		if (check_whiteK == true)
		{
			printf("\nGame # %d: white king is in check.\n\n", game);
		}
		else
		{
			turn();
			check(&check_blackK);

			if (check_blackK == true)
				printf("\nGame # %d: black king is in check.\n\n", game);
			else
				printf("\nGame # %d: no king is in check.\n\n", game);

		}


	}//end while

}//end main

void check(int *check) {

	int i, j, temp1, temp2;

	for (i = 0; i < SIZE; i++)
	{
		if (*check == true)
			return;

		for (j = 0; j < SIZE; j++)
		{
			if (*check == true)
				return;

			switch (board[i][j])
			{
			case 'p':
				if (((i - 1) >= 0 && (j - 1) >= 0 && board[i - 1][j - 1] == 'K')
					|| ((i + 1) < SIZE && (j - 1) >= 0 && board[i + 1][j - 1] == 'K'))
					*check = true;

				break;

			case 'n':
				if (((i - 2) >= 0 && (j - 1) >= 0 && board[i - 2][j - 1] == 'K')
					|| ((i + 2) < SIZE && (j - 1) >= 0 && board[i + 2][j - 1] == 'K')
					|| ((i - 1) >= 0 && (j - 2) >= 0 && board[i - 1][j - 2] == 'K')
					|| ((i + 1) < SIZE && (j - 2) >= 0 && board[i + 1][j - 2] == 'K'))
					*check = true;

				break;

			case 'b':
				if (look_for_K(i, j, -1, 1) || look_for_K(i, j, 1, 1))
					*check = true;

				break;

			case 'r':
				if (look_for_K(i, j, -1, 0)
					|| look_for_K(i, j, 1, 0)
					|| look_for_K(i, j, 0, 1)
					|| look_for_K(i, j, 0, -1))
					*check = true;

				break;

			case 'q':
				if (look_for_K(i, j, -1, 1)
					|| look_for_K(i, j, 1, 1)
					|| look_for_K(i, j, -1, 0)
					|| look_for_K(i, j, 1, 0)
					|| look_for_K(i, j, 0, 1)
					|| look_for_K(i, j, 0, -1))
					*check = true;
				break;

			case 'k':
				for (temp1 = i - 1; temp1 <= i + 1; temp1++)
				{
					for (temp2 = j - 1; temp2 <= j + 1; temp2++)
					{
						if (temp1 >= 0 && temp1 < SIZE && temp2 >= 0 & temp2 < SIZE)
						{
							if (board[temp1][temp2] == 'K')
								*check = true;
						}
					}
				}
				break;

			default:
				break;

			}//end switch

		}//end for
	}//end for
}

void turn()
{
	char temp;

	for (int i = 0; i < SIZE / 2; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			temp = board[i][j];
			board[i][j] = switch_case(board[7 - i][7 - j]);
			board[7 - i][7 - j] = switch_case(temp);
		}
	}
}


char switch_case(char c)
{
	if (c != '.')
		c = (c <= 'Z' ? (c + 'a' - 'A') : (c + 'A' - 'a'));

	return c;
}

int look_for_K(int istart, int jstart, int di, int dj)
{
	int i = istart + di, j = jstart + dj;

	while (i >= 0 && i < SIZE && j >= 0 && j < SIZE && board[i][j] == '.')
	{
		i += di;
		j += dj;
	}

	return(i >= 0 && i < SIZE && j >= 0 && board[i][j] == 'K');
}