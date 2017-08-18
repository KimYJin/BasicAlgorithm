//날짜: 170605
//이름: 김윤진
//문제9: 유쾌한 점퍼(Jolly Jumpers)

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 3000

void main()
{
	int num;	//정수 개수
	int arr[MAX];	// 수열을 저장할 배열
					/* 앞 뒤에 있는 숫자 차의 절대값을 저장해 jolly jumper인지 체크하기 위한 배열*/
	int check_jolly[MAX] = { 0 };
	int i;
	int gap;

	while (1)
	{
		scanf("%d", &num);

		/*수열 입력받기*/
		for (i = 0; i < num; i++)
			scanf("%d", &arr[i]);

		/*0으로 초기화*/
		for (i = 1; i < num; i++)
			check_jolly[i] = 0;


		/*두 숫자 간의 차의 절대값과 일치하는 check_jolly배열의 인덱스에 1저장 */
		for (i = 1; i < num; i++)
		{
			if (arr[i] >= arr[i - 1])
				gap = arr[i] - arr[i - 1];
			else
				gap = arr[i - 1] - arr[i];

			check_jolly[gap] = 1;
		}


		/*1부터 n-1까지의 값을 모두 갖는지 검사*/
		for (i = 1; i < num && check_jolly[i] == 1; i++);

		if (i == num)
			printf("Jolly\n");
		else
			printf("Not Jolly\n");


	}





}