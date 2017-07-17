
//이름: 김윤진
//문제8: 호주식 투표법(Australian Voting)

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>

#define MAX_CANDIDATES 20	// 후보자 수
#define MAX_NAME_LEN 80		// 후보자 이름 길이
#define MAX_VOTES 1000		// 투표자 수

char line[MAX_NAME_LEN + 1];

char name[MAX_CANDIDATES + 1][MAX_NAME_LEN + 1];

int vote[MAX_VOTES][MAX_CANDIDATES];	// 투표 용지. vote[i][j]->i번째 투표자가 j번째 선호하는 후보자

int votes_won[MAX_CANDIDATES + 1];	// i 번째 후보의 현재 득표수

int index_of_1st_alive[MAX_VOTES];	// i번째 투표자가 현재 살아남은 후보자들 중 가장 선호하는 사람이 투표용지 몇번째에 위치해 있는지

void election(int, int);

void main()
{
	int num_cases, num_votes, num_cands;
	int i, ptr;

	scanf("%d", &num_cases);		//입력 케이스 개수
	getchar();
	printf("\n");

	while (num_cases-- > 0)
	{
		/*후보자 수 입력받기*/
		scanf("%d", &num_cands);
		getchar();

		/*후보자의 이름 입력받고 각 후보자 득표수 초기화하기*/
		for (i = 1; i <= num_cands; i++)
		{
			gets(name[i]);
			votes_won[i] = 0;	// 득표수 초기화	
		}
		num_votes = 0;			//케이스 별 계산을 위해 투표자 수 초기화 

								/*투표 결과를 입력받는다*/
		while (gets(line) && *line)	// 입력 없이 엔터를 칠 때까지 입력받기
		{
			ptr = 0;

			for (i = 0; i < num_cands; i++)
			{
				sscanf(line + ptr, "%d", &vote[num_votes][i]); //line+ptr에서 정수 출력

															   /*다음 정수가 나올 때까지 포인터 이동*/

				while (line[ptr] >= '0' && line[ptr] <= '9')
					ptr++;

				while (line[ptr] == ' ')
					ptr++;
			}

			/*해당 후보의 득표수를 증가시킨다*/
			votes_won[vote[num_votes][0]]++;
			index_of_1st_alive[num_votes] = 0;
			num_votes++;
		}


		election(num_cands, num_votes);

		if (num_cases > 0)
			putchar('\n');

	}// end while문
}

void election(const int num_cands, const int num_votes)
{
	int temp;
	int i;
	int max, min;	// 최다 득표 후보, 최소 득표 후보
	int all_same;	// 살아남은 후보가 모두 동률이면 0, 아니면 1	 
	int who_got_max;

	while (1)
	{
		/* 최다득표, 최소득표 후보 가려내기 */
		min = MAX_VOTES + 1;
		max = -1;
		all_same = 1;

		for (i = 1; i <= num_cands; i++)
		{
			if (votes_won[i] > 0) { //아직 살아있는 후보만 처리

									/*최다 득표자인지 검사*/
				if (votes_won[i] > max)
				{
					if (max >= 0)
						all_same = 0;

					max = votes_won[i];

					who_got_max = i;	//최다 득표자를 기록해둔다.
				}

				/*최소득표자인지 검사*/
				if (votes_won[i] <min)
				{
					if (min <= MAX_VOTES)
						all_same = 0;

					min = votes_won[i];
				}
			}
		}

		/* 1순위 후보가 50%초과 득표하거나 모두 동률이면 while문 빠져 나오기*/
		if (max * 2 > num_votes || all_same)
			break;


		/*각 투표용지를 하나씩 점검하면서 현재 최소득표자에게 가있는 표는 걸러내어 그 다음으로 선호도가 높은 후보에게 넘겨준다.*/
		for (i = 0; i < num_votes; i++)
		{
			if (votes_won[i] == votes_won[min])	//최소 득표자를 찾는다 
			{
				/*그 다음으로 선호하는 후보를 찾는다*/
				/*for문의 조건식: 그 다음으로 선호하는 후보 역시 최소득표자(2명 이상가능하므로)라서 없어질 수 있으니
				최소득표자보다 많은 표를 받은 후보가 다음후보가 아니면 그 다음후보를 검사하기 위함.*/

				for (index_of_1st_alive[i]++; votes_won[vote[i][index_of_1st_alive[i]]] <= min; index_of_1st_alive[i]++);


				/*그 다음으로 선호하는 후보에게 표를 줌*/

				votes_won[vote[i][index_of_1st_alive[i]]]++;
			}
		}

		/*최소 득표자(들)의 득표는 0으로 리셋*/
		for (i = 1; i <= num_cands; i++)
		{
			if (votes_won[i] == min)
				votes_won[i] = 0;
		}

	}//end while문

	 /*과반 득표자가 있는 경우*/
	if (max * 2 > num_votes)
	{
		puts(name[who_got_max]);
	}
	else /*모두 동률이면->살아있는 모든 후보자들 출력*/
	{
		for (i = 1; i <= num_cands; i++)
		{
			if (votes_won[i] > 0)
				puts(name[i]);
		}
	}
}