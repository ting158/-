#define _CRT_SECURE_NO_WARNINGS 1\

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;


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
}LNode, * LinkList;


//ȡֵ - ȡ�������е�i��Ԫ�ص�����
Status GetElem_L(LinkList L, int i, ElemType e)//ͨ��e��������
{
	LinkList p = L->next;
	int j = 1; //���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
	while (p && (j < i))
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) //��i��Ԫ�ز�����
		return ERROR;
	e = p->data; //ȡ��i��Ԫ��
	return OK;
}

//����
//����ֵ���� - ����ָ�����ݻ�ȡ�����ݵ�ָ��λ�ã���ַ����
LNode* LocateElem_L(LinkList L, ElemType e)
//�ҵ�������e�ĵ�ַ�����򷵻ؿ�ָ��
{
	LinkList p = L->next;
	while (p && (p->data != e))
	{
		p = p->next;
	}
	return p;
}

//���� - �ڵ�i�����ǰ�����½��
Status ListInsert_L(LinkList L, int i, ElemType e)
//��L�е�i��Ԫ��֮ǰ��������Ԫ��e
{
	LinkList p = L;
	int j;
	while (p && (j < i - 1)) //Ѱ�ҵ�i-1����㣬pָ��i-1���
	{
		p = p->next;
		j++;
	}
	if (!p || (j > i + 1))
		return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//ɾ�� - ɾ����i�����
Status ListDelete_L(LinkList L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;   //����ɾ������������
	free(q);
	return OK;
}
