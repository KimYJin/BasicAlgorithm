//��¥: 170605
//�̸�: ������
//����9: ������ ����(Jolly Jumpers)

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 3000

void main()
{
	int num;	//���� ����
	int arr[MAX];	// ������ ������ �迭
					/* �� �ڿ� �ִ� ���� ���� ���밪�� ������ jolly jumper���� üũ�ϱ� ���� �迭*/
	int check_jolly[MAX] = { 0 };
	int i;
	int gap;

	while (1)
	{
		scanf("%d", &num);

		/*���� �Է¹ޱ�*/
		for (i = 0; i < num; i++)
			scanf("%d", &arr[i]);

		/*0���� �ʱ�ȭ*/
		for (i = 1; i < num; i++)
			check_jolly[i] = 0;


		/*�� ���� ���� ���� ���밪�� ��ġ�ϴ� check_jolly�迭�� �ε����� 1���� */
		for (i = 1; i < num; i++)
		{
			if (arr[i] >= arr[i - 1])
				gap = arr[i] - arr[i - 1];
			else
				gap = arr[i - 1] - arr[i];

			check_jolly[gap] = 1;
		}


		/*1���� n-1������ ���� ��� ������ �˻�*/
		for (i = 1; i < num && check_jolly[i] == 1; i++);

		if (i == num)
			printf("Jolly\n");
		else
			printf("Not Jolly\n");


	}





}