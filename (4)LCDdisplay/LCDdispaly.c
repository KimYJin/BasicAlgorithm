//날짜: 170503
//이름: 김윤진
//문제4: LCD DISPLAY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_S 10		// (1 <= s <= 10)
#define MAX_DIGITS 8	// (0 < n <= 99999999)

void main()
{
	int s;
	char n[MAX_DIGITS + 1];	//출력될 숫자를 입력받는 문자배열
	int num_digits, digit;

	char result[5][(MAX_S + 3)*MAX_DIGITS];	//숫자들을 LCD 디스플레이 방식으로 출력하기 위한 문자배열

	char hor_bar[2][MAX_S + 1] = { "          ","----------" };
	char ver_bar[2][2] = { " ","|" };

	//숫자 0~9 의 가로 구성(0,2,4행)(-)
	char hor[10][3] = { { 1,0,1 },{ 0,0,0 },{ 1,1,1 },{ 1,1,1 },{ 0,1,0 },{ 1,1,1 },{ 1,1,1 },{ 1,0,0 },{ 1,1,1 },{ 1,1,1 } };
	//숫자 0~9 의 세로 구성(|)
	char ver[10][4] = { { 1,1,1,1 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,0,1 },{ 1,1,0,1 },{ 1,0,0,1 },{ 1,0,1,1 },{ 0,1,0,1 },{ 1,1,1,1 },{ 1,1,0,1 } };


	int i, j;

	scanf("%d", &s);	// 숫자 크기 입력받기

	while (s != 0)
	{
		/*처음에 쓰레기값으로 초기화되어있으므로 문자열의 끝을 알리는 '\0' 삽입 + 반복될때마다 초기화*/
		for (i = 0; i < 5; i++)
			result[i][0] = '\0';


		//가로 bar의 길이를 s로 맞춰놓기 위해 문자열의 끝을 알리는'\0'를 삽입
		hor_bar[0][s] = '\0';
		hor_bar[1][s] = '\0';

		scanf("%s", n);	// 출력될 숫자 입력받기

		num_digits = strlen(n);	// 숫자들의 개수 구하기

		for (i = 0; i < num_digits; i++)
		{
			digit = n[i] - '0';	// 아스키코드를 정수형으로 변환 

								/*숫자 사이를 한 column(열)씩 띄우기*/
			if (i > 0)
				for (j = 0; j < 5; j++)
					strcat(result[j], " ");

			/*첫째줄 가로 bar*/
			strcat(result[0], " ");
			strcat(result[0], hor_bar[hor[digit][0]]);
			strcat(result[0], " ");

			/*둘째줄 세로 bar*/
			strcat(result[1], ver_bar[ver[digit][0]]);
			strcat(result[1], hor_bar[0]);
			strcat(result[1], ver_bar[ver[digit][1]]);

			/*셋째줄 가로 bar*/
			strcat(result[2], " ");
			strcat(result[2], hor_bar[hor[digit][1]]);
			strcat(result[2], " ");

			/*넷째줄 세로 bar*/
			strcat(result[3], ver_bar[ver[digit][2]]);
			strcat(result[3], hor_bar[0]);
			strcat(result[3], ver_bar[ver[digit][3]]);

			/*다섯째줄 가로 bar*/
			strcat(result[4], " ");
			strcat(result[4], hor_bar[hor[digit][2]]);
			strcat(result[4], " ");
		}

		puts(result[0]);

		for (i = 0; i<s; i++)
			puts(result[1]);

		puts(result[2]);

		for (i = 0; i<s; i++)
			puts(result[3]);

		puts(result[4]);

		putchar('\n');

		/*앞에서 삽입한 \0 를 되돌려놓기*/
		hor_bar[0][s] = ' ';
		hor_bar[1][s] = '-';

		//반복해서 입력받는 프로그램
		scanf("%d", &s);

	}
}