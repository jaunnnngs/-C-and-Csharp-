#include <stdio.h>//���������ý���

int i, j;
int result;
int arr[5][10];

int menu()      //�޴�
{
	printf("\t\t����");//0
	printf("\t\t����");//0
	printf("\t\t�̿�\n");//0
	printf("����\t");//0
	printf("����ȣ\t");//1
	printf("�ð�\t");//2
	printf("��\t");//3
	printf("�ð�\t");//4
	printf("��\t");//5
	printf("�ð�\t");//6
	printf("���\n");//7
}

int input()
{
	for (i = 0; i < 5; i++)
	{
		carnum();
		startnum();
		startnum2();
		endnum();
		endnum2();

		printf("\n");
	}
}

int order()
{
	for (i = 0; i < 5; i++)
	{
		arr[i][0] = i + 1;
	}
}

int output()
{
	in_min();
	out_min();
	total_min();
	price();
}

int total()
{
	i = 0;
	result = 0;
	while (i < 5)
	{
		result = arr[i][7] + result;
		i++;
	}
	//for (i = 0; i < 5; i++)
	//{
	//	for (j = 0; j < 8; j++)
	//		printf("%d\t", arr[i][j]);
	//	printf("\n");
	//}
}

int error()
{
	for (i = 0; i < 5; i++)
		if (arr[i][7] < 0)
			printf("����!! %d������ �������� ���� �����մϴ�.\n", i + 1);
}

int carnum()
{
	while (1)
	{
		printf("%d���� ����ȣ 4�ڸ��� �Է��Ͻÿ�.", i + 1);
		scanf_s("%d", &arr[i][1]);
		if (arr[i][1] > 9999)
			printf("�߸��Է��ϼ̽��ϴ�\n");
		if (arr[i][1] <= 9999)
			break;
	}
}

int startnum()
{
	while (1)
	{
		printf("�����ð� �Է��Ͻÿ�(���)");
		scanf_s("%d", &arr[i][2]);
		if (arr[i][2] > 24 || arr[i][2] < 0)
			printf("�߸��Է��ϼ̽��ϴ�\n");
		if (arr[i][2] <= 24)
			break;
	}
}

int startnum2()
{
	while (1)
	{
		printf("�����ð� �Է��Ͻÿ�(���)");
		scanf_s("%d", &arr[i][3]);
		if (arr[i][3] > 60 || arr[i][3] < 0)
			printf("�߸��Է��ϼ̽��ϴ�\n");
		if (arr[i][3] <= 60)
			break;
	}
}

int endnum()
{
	while (1)
	{
		printf("�����ð� �Է��Ͻÿ�(���)");
		scanf_s("%d", &arr[i][4]);
		if (arr[i][4] < arr[i][2] || arr[i][4] > 24 || arr[i][4] < 0)
			printf("�߸��Է��ϼ̽��ϴ�\n");
		if (arr[i][4] >= arr[i][2] && arr[i][4] < 25)
			break;
	}
}

int endnum2()
{
	while (1)
	{
		printf("�����ð� �Է��Ͻÿ�(���)");
		scanf_s("%d", &arr[i][5]);
		if (arr[i][5] > 60)
			printf("�߸��Է��ϼ̽��ϴ�\n");
		break;
	}
}

int in_min()
{
	for (i = 0; i < 5; i++)//������ȯ��
		arr[i][8] = arr[i][2] * 60 + arr[i][3];
}

int out_min()
{
	for (i = 0; i < 5; i++)//������ȯ��
		arr[i][9] = arr[i][4] * 60 + arr[i][5];
}

int total_min()
{
	for (i = 0; i < 5; i++)//�Ѻ�
		arr[i][6] = arr[i][9] - arr[i][8];
}

int price()
{
	for (i = 0; i < 5; i++)//�Ѻ�*��ݰ��
		arr[i][7] = arr[i][6] * 50;
}

int main(void)
{
	printf("<��������������Ϻ�>\n\n");
	input();
	menu();
	order();
	output();
	total();

	printf("\n");
	printf("\t*����� 1�д� 50���Դϴ�.\n");
	printf("\t���� �� ������:%d �Դϴ�.\n", result);

	error();

	return 0;
}