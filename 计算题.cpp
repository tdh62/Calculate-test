// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"stdafx.h"
#include "windows.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"
#define cls system("cls")

//ȫ�ֱ���
struct ti {
	int t1;//1
	int flag;//+
	int t2;//1
	int ans;//2
	int times;
}t[10];
int right = 0, wrong = 0, point = 0;
//������
int showwelcome();

//������
int start();


//��Ļ�����ʾ
int toshow(int a);

//����
int ct();

//���⣬��ȫ�ֱ�����
void check();

//�����÷�
void repo1(int);

//�������ۣ�ѡ���Ƿ�����˳�
int end();

//��������Ŀ��ʾ
void sc(int a);

//����ƶ�
void gotoxy(int y, int x)
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//����
void linef(int x1, int y1, int x2, int y2) {
	int i, slong;
	slong = y2 - y1 - 1;
	gotoxy(x1, y1 + 1);
	for (i = 0; i < slong; i++) {
		printf("-");
	}
	gotoxy(x2, y1 + 1);
	for (i = 0; i < slong; i++) {
		printf("-");
	}
	for (i = x1 + 1; i <= x2 - 1; i++) {
		gotoxy(i, y1);
		printf("|");
		gotoxy(i, y2);
		printf("|");
	}
}


int main()
{
	int t=1;
	while(t)
	{
		showwelcome();
		ct();
		start();
		check();
		t=end();
	}
	
	exit(0);
	return 0;
}

int showwelcome() {
	//���ñ��⣬��������������̨��С��������ɫ
	system("title ������");
	cls;
	system("color f1");
	system("mode con cols=80 lines=35");
	//��ʾ��ӭ��Ϣ
	gotoxy(12, 30);
	printf("--��ӭʹ��--");
	Sleep(2000);
	return 0;
}

int ct() {
int i,a,b,c;
srand(time(0));//���õ�ǰʱ��ֵ��Ϊ��������ӣ��κ����������������Ҫһ������
i = 0;


while (i < 10)
{
	a = rand() % 51;//����0~51�������
	b = rand() % 51;//����0~51�������
	c = rand() % 2;//����0~1�������
	if (c) {
		if (a + b <= 50) {
			t[i].t1 = a;
			t[i].t2 = b;
			t[i].flag = c;
			t[i].ans = (a+b);
			t[i].times = 0;
			i++;
		}
	}
	if (!c) {
		if (a - b > 0) {
			t[i].t1 = a;
			t[i].t2 = b;
			t[i].flag = c;
			t[i].ans = (a-b);
			t[i].times = 0;
			i++;
		}
	}
}
return 1;
}

int start() {
	int i,p;
	cls;
	linef(1, 1, 35, 30);
	
	linef(1, 31, 35,79);
	
	gotoxy(28, 32);
	for (i = 0; i < 47; i++) {
		printf("-");
	}
	
	gotoxy(1,8);
	printf("��Ŀ��С���");
	gotoxy(1, 52);
	printf("����");
	gotoxy(28, 52);
	printf("����");
	for (i = 0,p=3; i < 10; i++,p+=3) {
	gotoxy(p, 6);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	char flag ;
	char step[10];
	if (t[i].flag == 1) {
		flag = '+';
	}
	else {
		flag = '-';
	}

	printf("%d %c %d  δ����", t[i].t1,flag/**/, t[i].t2);

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	

	
	}
	gotoxy(30, 65);
	printf("���   ��");
	gotoxy(31, 65);
	printf("���   ��");
	gotoxy(32, 65);
	printf("�÷�   ");
//	gotoxy(33, 61);
//	printf("��ǰ����      ");
	gotoxy(8, 42);
	printf("��Ŀ��");//10,49
	gotoxy(11, 42);
	printf("��Ļش�");//13,52
	//15,50
	gotoxy(20, 35);
	printf("ÿ������ 3 ���������");
	gotoxy(22, 35);
	printf("һ���Դ�Ե� 10 ��");
	gotoxy(23, 35);
	printf("�ڶ��δ�Ե� 7 ��");
	gotoxy(24, 35);
	printf("�����δ�Ե� 5 ��");

	return 1;
}

int toshow(int p) {
	int a;
	char flag;
	a = p;
	gotoxy(30, 69);
	printf(" ");
	gotoxy(31, 69);
	printf(" ");
	gotoxy(32, 71);
	printf("  ");
	p = 3 * (p+1);
	gotoxy(p,6);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	if (t[a].flag == 1) {
		flag = '+';
	}
	else {
		flag = '-';
	}
	printf("%d %c %d  ������",t[a].t1,flag,t[a].t2);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	return 1;
}

void sc(int a) {
	char flag;
	gotoxy(8, 49);
	if (t[a].flag == 1) {
		flag = '+';
	}
	else {
		flag = '-';
	}
	printf("                   ");
	gotoxy(8, 49);
	printf("%d %c %d", t[a].t1, flag, t[a].t2);
	gotoxy(11,52);
	printf("     ");
	gotoxy(11,52);
}

void check()
 {
	int da,i;
	for(i=0;i<10;)
	{
		sc(i);
		scanf("%d",&da);
		if(t[i].ans==da)
		{
			toshow(i);
			right++;
			repo1(i);
			i++;		
		}
		else
		{
			gotoxy(15,48);
			printf("�����,����һ�ΰ�");
			gotoxy(11,52);
			printf("      ");
			gotoxy(11,52);
			(t[i].times)++;
			if(t[i].times==3)
			{	
				gotoxy(15,48);
				printf("                    ");
				toshow(i);
				wrong++;
				repo1(i);
				i++;
			}
		}
	}
}

void repo1(int i) {
	gotoxy(30, 70);
	printf("%d", right);
	gotoxy(31, 70);
	printf("%d", wrong);
	gotoxy(32, 71);
	switch(t[i].times)
	{
		case 0: point+=10;break;
		case 1: point+=7;break;
		case 2: point+=5;break;
	}
	printf("%d", point);
}


int end()
{
	char z,y='y';
	cls;
	linef(1, 1, 35,79);
	gotoxy(12,33);
	printf("���β��Եĵ÷֣�%d",point);
	gotoxy(13,33);
	printf("����ԣ�%d",right);
	gotoxy(14,33);
	printf("�����%d",wrong);
	gotoxy(15,33);
	printf("���������");
	switch((point<60)+(point<70)+(point<80)+(point<90))
	{
	case 0:printf("SMART!");break;
	case 1:printf("GOOD!");break;
	case 2:printf("OK");break;
	case 3:printf("PASS");break;
	case 4:printf("TRYAGAIN");break;
	}
	gotoxy(16,33);
	fflush(stdin);
	printf("�Ƿ�Ҫ����һ�Σ�(Y/N)");
	z = _getch();
	if(z=='y'||z=='Y')
		return 1;
	gotoxy(17,33);
		return 0;
}


