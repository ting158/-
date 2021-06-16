#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

//����˳�򴢴�ṹ
#define MAXLEN 255

typedef struct
{
	char ch[MAXLEN + 1];//���洮��һά����
	int length;//���ĵ�ǰ����
}SString;


int next[MAXLEN];

void get_next(SString T, int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int Index_KMP(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	while (i < S.length && j < T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];  // i���䣬j����
		}
	}
	if (j > T.length)
		return i - T.length; //ƥ��ɹ�
	else
		return 0; //���ز�ƥ���־
}