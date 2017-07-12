//날짜: 170524
//이름: 김윤진
//문제5: Graphic Editor

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAX 250

char image[MAX][MAX];

void main()
{
	char command[20]; //명령문
	char c;
	int m, n;	// 열 번호, 행 번호
	int x1, y1, x2, y2;	// 픽셀 위치(x,y)
	int i, j;
	char name[20];
	char *token;
	char *seps = " ";


	while (1)
	{
		gets(command);

		switch (command[0])
		{
		case'I':
			m = toascii(command[1]) - 48;
			n = toascii(command[2]) - 48;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					image[i][j] = 'o';
				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}
			break;

		case'C':
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					image[i][j] = 'o';
				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}
			break;

		case'L':
			y1 = toascii(command[1]) - 48 - 1;
			x1 = toascii(command[2]) - 48 - 1;
			c = command[3];

			image[x1][y1] = c;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}
			break;

		case'V':
			y1 = toascii(command[1]) - 48 - 1;
			x1 = toascii(command[2]) - 48 - 1;
			x2 = toascii(command[3]) - 48 - 1;
			c = command[4];

			for (i = x1, j = y1; i <= x2; i++)
			{
				image[i][j] = c;
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}

			break;

		case'H':
			y1 = toascii(command[1]) - 48 - 1;
			y2 = toascii(command[2]) - 48 - 1;
			x1 = toascii(command[3]) - 48 - 1;
			c = command[4];

			for (i = x1, j = y1; j <= y2; j++)
			{
				image[i][j] = c;
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}

			break;

		case'K':
			y1 = toascii(command[1]) - 48 - 1;
			x1 = toascii(command[2]) - 48 - 1;
			y2 = toascii(command[3]) - 48 - 1;
			x2 = toascii(command[4]) - 48 - 1;
			c = command[5];

			for (i = x1; i <= x2; i++)
			{
				for (j = y1; j <= y2; j++)
				{
					image[i][j] = c;
				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}

			break;

		case'F':
			y1 = toascii(command[1]) - 48 - 1;
			x1 = toascii(command[2]) - 48 - 1;
			c = command[3];
			char color = image[x1][y1];
			int k, l;
			int num;

			image[x1][y1] = c;

			do {
				num = 0;
				for (k = 0; k < n; k++)
				{
					for (l = 0; l < m; l++)
					{
						if (image[k][l] == color)	//같은 색이면서
						{
							for (i = k - 1; i <= k + 1; i++)
							{
								for (j = l - 1; j <= l + 1; j++)
								{
									if (i < 0 || j < 0 || i>n || j>m || (i == k && j == l))
										continue;

									if (image[i][j] == c)	//맞닿은 부분이 하나라도 있다면	
									{
										image[k][l] = c;	// 새 색으로 칠.
										num++;
										break;
									}
								}
								if (image[k][l] == c)
									break;
							}
						}
					}
				}
			} while (num != 0);


			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}
			break;

		case'S':
			token = strtok(command, seps);
			token = strtok(NULL, seps);
			strcpy(name, token);

			puts(name);
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					printf("%c", image[i][j]);
				}
				printf("\n");
			}

			break;

		case'X':
			return 0;

		default:
			break;


		}


	}

}
