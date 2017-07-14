//날짜: 170529
//이름: 김윤진
//문제6: 인터프리터(Interpreter)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 1000

int RAM[1000];	//0~999 : 1000워드
int Register[10] = { 0 };	//10개의 레지스터

int main()
{
	int time = 0;			// 입력 케이스의 개수	
	int command = 0;		//명령어 개수
	int n1 = 0, n2 = 0, n3 = 0;


	scanf("%d", &time);
	printf("\n");

	for (int i = 0; i < time; i++)
	{
		int j = 0;
		command = 0;
		int temp = 1000;

		while (1)
		{
			if (temp >= j && j < 1000)
			{
				temp = 1000;

				scanf("%d", &RAM[j]);	//0이상 999이하의 세자리 정수

				n1 = RAM[j] / 100;
				n2 = (RAM[j] % 100) / 10;
				n3 = (RAM[j] % 10);

				j = j + 1;
			}
			else   //temp < j
			{
				n1 = RAM[temp] / 100;
				n2 = (RAM[temp] % 100) / 10;
				n3 = (RAM[temp] % 10);

				temp++;
			}

			command++;

			if ((n1 * 100 + n2 * 10 + n3) == 100)			//종료
				break;

			switch (n1)
			{
			case 2:
				Register[n2] = n3;
				break;

			case 3:
				Register[n2] += n3;
				break;
			case 4:
				Register[n2] *= n3;
				break;
			case 5:
				Register[n2] = Register[n3];
				break;
			case 6:
				Register[n2] += Register[n3];
				break;
			case 7:
				Register[n2] *= Register[n3];
				break;
			case 8:
				Register[n2] = RAM[n3];
				break;
			case 9:
				RAM[n3] = Register[n2];
				break;
			case 0:
				if (Register[n3] != 0)
				{
					temp = Register[n2];
				}
				break;

			}// switch

			if (Register[n2] >= 1000)
				Register[n2] = Register[n2] % 1000;

			printf("****\n");
			for (int a = 0; a < 10; a++)
			{
				printf("%d ", Register[a]);

			}
			printf("\n** j=%d, command=%d, temp=%d **\n", j, command, temp);
		}//while
		printf("\n**j=%d, command=%d, temp=%d**\n", j, command, temp);
		printf("%d\n", command);	//결과 출력: 총 명령어 개수

	}//for

	return 0;
}