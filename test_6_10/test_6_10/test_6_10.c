#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

//����

typedef struct
{
	char num[8];
	char name[20];
	int score;
}ElemType;

typedef struct Londe
{
	ElemType data;//������
	struct Londe* next;//ָ����
}LNode, *LinkList;


//������ĳ�ʼ��
Status InitList_L(LinkList L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}

//�ж������Ƿ�Ϊ��
int ListEmpty(LinkList L)
{
	if (L->next) //�ǿ�
		return 0;
	else
		return 1;
}

//�����������
//  (��ͷָ�뿪ʼ�������ͷ����н��)
Status DestroyList_L(LinkList L)
{
	LinkList p;
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
	return OK;
}

//�������
 //(�����ڣ�����������Ԫ�أ���Ϊ������ͷָ���ͷ������ڣ�)
Status ClearList_L(LinkList L)
{
	LinkList p, q;
	p = L->next;
	free(p);
	while (q)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}

//������ı�
Status ListLength_L(LinkList L)
{
	LNode* p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

