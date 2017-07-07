//날짜: 170502 
//이름: 김윤진
//문제1: The 3n+1 problem


// 정수 n에서 시작해 n이 짝수면 2로 나누고,
// 홀수면 3을 곱한 다음 1을 더한다.
// n이 1이 될 때까지 같은 작업을 계속 반복한다.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int cycle_len(int n);

int main()
{
	int i, j, n;
	int temp, max;

	while (1)
	{
		max = 1;

		scanf("%d %d", &i, &j);

		for (n = i; n <= j; n++)
		{
			temp = cycle_len(n);

			if (max < temp)
				max = temp;
		}

		printf("%d %d %d\n", i, j, max);
	}

}

int cycle_len(int n)
{
	int len = 1;

	while (n != 1)
	{
		if (n % 2 == 0)	//짝수
		{
			n = n / 2;
		}
		else			//홀수
		{
			n = 3 * n + 1;
		}

		len++;
	}
	return len;
}