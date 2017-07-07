//날짜: 170503
//이름: 김윤진
//문제3: 여행(The Trip)

// 여행 동안 n명의 학생들이 각자 쓴 돈을 여행 후에 적는다.
// 그리고 모든 학생들이 쓴 돈이 같도록 돈을 주고 받는다.(1센트 단위 내에서)
// 돈을 주고 받는 과정이 최소가 되도록, 주고 받은 최소 액수를 구해보자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 1000

float cal(float *s, int n);

int main()
{
	int n;	// 학생 수
	int i;
	float min;
	float s[MAX];	//각 학생이 지출한 경비를 저장할 배열

	while (1)
	{
		scanf("%d", &n);

		if (n == 0)
			break;

		for (i = 0; i < n; i++)	// 각 학생이 지출한 경비
		{
			scanf("%f", &s[i]);
		}

		min = cal(s, n);
		printf("$%.2f\n", min);
	}


	return 0;

}
float cal(float *s, int n)
{
	int i;
	float total = 0.0;
	float gap = 0.0, gap2 = 0.0;

	for (i = 0; i < n; i++)
	{
		//total += s[i];
		total += *(s + i);
	}

	total = total / n;

	for (i = 0; i < n; i++)
	{
		if (total > s[i])
		{
			gap = total - s[i];
			gap = ((int)(gap * pow(10, 2))) / pow(10, 2);	// ★소수를 둘째자리까지 나타내기ex) 5.995 -> 5.99★
			gap2 += gap;
		}

	}
	return gap2;

}



