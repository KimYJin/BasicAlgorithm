//��¥: 170529
//�̸�: ������
//����6: ����������(Interpreter)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 1000

int RAM[1000];	//0~999 : 1000����
int Register[10] = { 0 };	//10���� ��������

int main()
{
	int time = 0;			// �Է� ���̽��� ����	
	int command = 0;		//��ɾ� ����
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

				scanf("%d", &RAM[j]);	//0�̻� 999������ ���ڸ� ����

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

			if ((n1 * 100 + n2 * 10 + n3) == 100)			//����
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
		printf("%d\n", command);	//��� ���: �� ��ɾ� ����

	}//for

	return 0;
}