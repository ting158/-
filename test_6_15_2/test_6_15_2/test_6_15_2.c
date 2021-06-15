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

//������ʽ�洢�ṹ - �����ṹ
#define CHUNKSIZE 80 //��Ĵ�С

typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail; //����ͷָ���βָ��
	int curlen; //���ĵ�ǰ����
}LString; //�ַ����Ŀ����ṹ


//BF�㷨����
int Index_BF(SString S, SString T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		} //�������Ӵ�����ƥ����һ���ַ�
		else
		{
			i = i - j + 2;
			j = 1;
		} //�������Ӵ�ָ��������¿�ʼ��һ��ƥ��
	}
	if (j > T.length)
		return i - T.length; //����ƥ��ĵ�һ���ַ����±�
	else
		return 0; //ģʽƥ�䲻�ɹ�
}