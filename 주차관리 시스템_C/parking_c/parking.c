#include <stdio.h>//주차관리시스템

int i, j;
int result;
int arr[5][10];

int menu()      //메뉴
{
	printf("\t\t입차");//0
	printf("\t\t출차");//0
	printf("\t\t이용\n");//0
	printf("순서\t");//0
	printf("차번호\t");//1
	printf("시간\t");//2
	printf("분\t");//3
	printf("시간\t");//4
	printf("분\t");//5
	printf("시간\t");//6
	printf("요금\n");//7
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
			printf("주의!! %d구역에 출차금지 차량 존재합니다.\n", i + 1);
}

int carnum()
{
	while (1)
	{
		printf("%d구역 차번호 4자리를 입력하시오.", i + 1);
		scanf_s("%d", &arr[i][1]);
		if (arr[i][1] > 9999)
			printf("잘못입력하셨습니다\n");
		if (arr[i][1] <= 9999)
			break;
	}
}

int startnum()
{
	while (1)
	{
		printf("입차시간 입력하시오(몇시)");
		scanf_s("%d", &arr[i][2]);
		if (arr[i][2] > 24 || arr[i][2] < 0)
			printf("잘못입력하셨습니다\n");
		if (arr[i][2] <= 24)
			break;
	}
}

int startnum2()
{
	while (1)
	{
		printf("입차시간 입력하시오(몇분)");
		scanf_s("%d", &arr[i][3]);
		if (arr[i][3] > 60 || arr[i][3] < 0)
			printf("잘못입력하셨습니다\n");
		if (arr[i][3] <= 60)
			break;
	}
}

int endnum()
{
	while (1)
	{
		printf("출차시간 입력하시오(몇시)");
		scanf_s("%d", &arr[i][4]);
		if (arr[i][4] < arr[i][2] || arr[i][4] > 24 || arr[i][4] < 0)
			printf("잘못입력하셨습니다\n");
		if (arr[i][4] >= arr[i][2] && arr[i][4] < 25)
			break;
	}
}

int endnum2()
{
	while (1)
	{
		printf("출차시간 입력하시오(몇분)");
		scanf_s("%d", &arr[i][5]);
		if (arr[i][5] > 60)
			printf("잘못입력하셨습니다\n");
		break;
	}
}

int in_min()
{
	for (i = 0; i < 5; i++)//입차분환산
		arr[i][8] = arr[i][2] * 60 + arr[i][3];
}

int out_min()
{
	for (i = 0; i < 5; i++)//출차분환산
		arr[i][9] = arr[i][4] * 60 + arr[i][5];
}

int total_min()
{
	for (i = 0; i < 5; i++)//총분
		arr[i][6] = arr[i][9] - arr[i][8];
}

int price()
{
	for (i = 0; i < 5; i++)//총분*요금계산
		arr[i][7] = arr[i][6] * 50;
}

int main(void)
{
	printf("<일일주차관리기록부>\n\n");
	input();
	menu();
	order();
	output();
	total();

	printf("\n");
	printf("\t*요금은 1분당 50원입니다.\n");
	printf("\t오늘 총 수익은:%d 입니다.\n", result);

	error();

	return 0;
}