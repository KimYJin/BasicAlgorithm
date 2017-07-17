
//�̸�: ������
//����8: ȣ�ֽ� ��ǥ��(Australian Voting)

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>

#define MAX_CANDIDATES 20	// �ĺ��� ��
#define MAX_NAME_LEN 80		// �ĺ��� �̸� ����
#define MAX_VOTES 1000		// ��ǥ�� ��

char line[MAX_NAME_LEN + 1];

char name[MAX_CANDIDATES + 1][MAX_NAME_LEN + 1];

int vote[MAX_VOTES][MAX_CANDIDATES];	// ��ǥ ����. vote[i][j]->i��° ��ǥ�ڰ� j��° ��ȣ�ϴ� �ĺ���

int votes_won[MAX_CANDIDATES + 1];	// i ��° �ĺ��� ���� ��ǥ��

int index_of_1st_alive[MAX_VOTES];	// i��° ��ǥ�ڰ� ���� ��Ƴ��� �ĺ��ڵ� �� ���� ��ȣ�ϴ� ����� ��ǥ���� ���°�� ��ġ�� �ִ���

void election(int, int);

void main()
{
	int num_cases, num_votes, num_cands;
	int i, ptr;

	scanf("%d", &num_cases);		//�Է� ���̽� ����
	getchar();
	printf("\n");

	while (num_cases-- > 0)
	{
		/*�ĺ��� �� �Է¹ޱ�*/
		scanf("%d", &num_cands);
		getchar();

		/*�ĺ����� �̸� �Է¹ް� �� �ĺ��� ��ǥ�� �ʱ�ȭ�ϱ�*/
		for (i = 1; i <= num_cands; i++)
		{
			gets(name[i]);
			votes_won[i] = 0;	// ��ǥ�� �ʱ�ȭ	
		}
		num_votes = 0;			//���̽� �� ����� ���� ��ǥ�� �� �ʱ�ȭ 

								/*��ǥ ����� �Է¹޴´�*/
		while (gets(line) && *line)	// �Է� ���� ���͸� ĥ ������ �Է¹ޱ�
		{
			ptr = 0;

			for (i = 0; i < num_cands; i++)
			{
				sscanf(line + ptr, "%d", &vote[num_votes][i]); //line+ptr���� ���� ���

															   /*���� ������ ���� ������ ������ �̵�*/

				while (line[ptr] >= '0' && line[ptr] <= '9')
					ptr++;

				while (line[ptr] == ' ')
					ptr++;
			}

			/*�ش� �ĺ��� ��ǥ���� ������Ų��*/
			votes_won[vote[num_votes][0]]++;
			index_of_1st_alive[num_votes] = 0;
			num_votes++;
		}


		election(num_cands, num_votes);

		if (num_cases > 0)
			putchar('\n');

	}// end while��
}

void election(const int num_cands, const int num_votes)
{
	int temp;
	int i;
	int max, min;	// �ִ� ��ǥ �ĺ�, �ּ� ��ǥ �ĺ�
	int all_same;	// ��Ƴ��� �ĺ��� ��� �����̸� 0, �ƴϸ� 1	 
	int who_got_max;

	while (1)
	{
		/* �ִٵ�ǥ, �ּҵ�ǥ �ĺ� �������� */
		min = MAX_VOTES + 1;
		max = -1;
		all_same = 1;

		for (i = 1; i <= num_cands; i++)
		{
			if (votes_won[i] > 0) { //���� ����ִ� �ĺ��� ó��

									/*�ִ� ��ǥ������ �˻�*/
				if (votes_won[i] > max)
				{
					if (max >= 0)
						all_same = 0;

					max = votes_won[i];

					who_got_max = i;	//�ִ� ��ǥ�ڸ� ����صд�.
				}

				/*�ּҵ�ǥ������ �˻�*/
				if (votes_won[i] <min)
				{
					if (min <= MAX_VOTES)
						all_same = 0;

					min = votes_won[i];
				}
			}
		}

		/* 1���� �ĺ��� 50%�ʰ� ��ǥ�ϰų� ��� �����̸� while�� ���� ������*/
		if (max * 2 > num_votes || all_same)
			break;


		/*�� ��ǥ������ �ϳ��� �����ϸ鼭 ���� �ּҵ�ǥ�ڿ��� ���ִ� ǥ�� �ɷ����� �� �������� ��ȣ���� ���� �ĺ����� �Ѱ��ش�.*/
		for (i = 0; i < num_votes; i++)
		{
			if (votes_won[i] == votes_won[min])	//�ּ� ��ǥ�ڸ� ã�´� 
			{
				/*�� �������� ��ȣ�ϴ� �ĺ��� ã�´�*/
				/*for���� ���ǽ�: �� �������� ��ȣ�ϴ� �ĺ� ���� �ּҵ�ǥ��(2�� �̻󰡴��ϹǷ�)�� ������ �� ������
				�ּҵ�ǥ�ں��� ���� ǥ�� ���� �ĺ��� �����ĺ��� �ƴϸ� �� �����ĺ��� �˻��ϱ� ����.*/

				for (index_of_1st_alive[i]++; votes_won[vote[i][index_of_1st_alive[i]]] <= min; index_of_1st_alive[i]++);


				/*�� �������� ��ȣ�ϴ� �ĺ����� ǥ�� ��*/

				votes_won[vote[i][index_of_1st_alive[i]]]++;
			}
		}

		/*�ּ� ��ǥ��(��)�� ��ǥ�� 0���� ����*/
		for (i = 1; i <= num_cands; i++)
		{
			if (votes_won[i] == min)
				votes_won[i] = 0;
		}

	}//end while��

	 /*���� ��ǥ�ڰ� �ִ� ���*/
	if (max * 2 > num_votes)
	{
		puts(name[who_got_max]);
	}
	else /*��� �����̸�->����ִ� ��� �ĺ��ڵ� ���*/
	{
		for (i = 1; i <= num_cands; i++)
		{
			if (votes_won[i] > 0)
				puts(name[i]);
		}
	}
}