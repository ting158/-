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


//˫������
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, *DuLinkList;



//������Ľ���
//ͷ�巨 - Ԫ�ز����������ͷ����Ҳ��ǰ�巨
void Create_H(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;//�Ƚ���һ������ͷ���Ŀ�����
	int i = 0;
	LinkList p;
	for (i = n;i > 0;i--)
	{
		p = (LinkList)malloc(sizeof(LinkList));
		scanf(&p->data);//����Ԫ��ֵ
		p->next = L->next;
		L->next = p;
	}
}
//β�巨 - Ԫ�ز�������β����Ҳ�к�巨
void CreateList_R(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	LinkList p;
	LinkList r = L; //βָ��rָ��ͷ���
	int i = 0;
	for (i = 0;i < n;i++)
	{
		p = (LinkList)malloc(sizeof(LinkList));
		scanf(&p->data);
		p->next = NULL;
		r->next = p; //���뵽��β
		r = p;  //rָ���µ�β���
	}
}

//��βָ��ѭ������ĺϲ�
LinkList Connect(LinkList Ta, LinkList Tb)
{
	LinkList p = Ta->next;
	Ta->next = Tb->next->next;
	free(Tb->next); //�ͷ�Tb�ı�ͷ���
	Tb->next = p;
	return Tb;
}

//˫������Ĳ���
void ListInsert_DuL(DuLinkList L, int i, ElemType e)
//�ڴ�ͷ����˫��ѭ������L�е�i��λ��֮ǰ����Ԫ��e
{
	DuLinkList p;
	if (!(p = GetElemP_Dul(L, i)))
		return ERROR;
	DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

//˫�������ɾ��
void ListInsert_DuL(DuLinkList L, int i, ElemType e)
//ɾ����ͷ����˫��ѭ������L�ĵ�i��Ԫ�أ�����e����
{
	DuLinkList p;
	if (!(p = GetElemP_Dul(L, i)))
		return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}