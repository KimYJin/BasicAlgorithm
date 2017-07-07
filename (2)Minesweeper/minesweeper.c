//날짜: 170502 
//이름: 김윤진
//문제2: 지뢰찾기(Minewseeper)

// M*N의 지뢰밭에서 각 칸에 인접한 칸에 몇개의 지뢰가 있는지 보여주기.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char matrix[SIZE][SIZE];

int main()
{
	int n, m;	//지뢰밭의 행과 열(0< n,m <=100)
	int i, j, a, b;
	int time = 0;

	while (1)
	{
		scanf("%d %d", &n, &m); // 행과 열 입력받기
		getchar();				// 입력버퍼 비우기

		if (n == 0 && m == 0)	// 0 0입력시 종료
			break;

		for (i = 0; i < n; i++) // 각 행 별로 문자 입력받기
		{
			gets(matrix[i]);
		}

		for (i = 0; i < n; i++)	//.인 칸을 0으로 바꿔주기
		{
			for (j = 0; j < m; j++)
			{
				if ((matrix[i][j]) == '.')
					matrix[i][j] = '0';

			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (matrix[i][j] == '*')	//*인 경우
				{
					for (a = -1; a <= 1; a++)  //인접한 8개의 칸에 1씩 증가시킴
					{
						for (b = -1; b <= 1; b++)
						{
							if (((i + a) < 0 || (j + b)<0) || ((i + a) >= n || (j + b) >= m))	//지뢰밭 범위 안에서만
								continue;

							if (a == 0 && b == 0)	// 자기자신은 제외
								continue;

							if (matrix[i + a][j + b] == '*') //지뢰있는 부분은 숫자 증가X
								continue;

							//고치기 전 틀린 부분: matrix[i+a][j+b] = atoi(matrix[i+a][j+b]) + 1; 
							matrix[i + a][j + b]++;		//*인 경우 인접한 8개의 칸에 1씩 증가시킴
						}
					}
				}
			}
		}


		printf("\nField#%d \n", ++time);

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				printf("%c ", matrix[i][j]);
			}
			printf("\n");
		}

	}
	return 0;
}


