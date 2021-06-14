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
//��ջ�ı�ʾ
typedef struct
{
	char name[20];
	int age;
}SElemType;
typedef struct StackNode
{
	SElemType data;
	StackNode* next;
}StackNode, *LinkStack;


//��ջ�ĳ�ʼ��
Status InitStack(LinkStack S)
{
	//����һ����ջ��ջ��ָ����Ϊ��
	S = NULL;
	return OK;
}

//�ж���ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S)
{
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}

//��ջ����ջ
Status Push(LinkStack S, SElemType e)
{
	LinkStack p = (LinkStack)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

//��ջ�ĳ�ջ
Status Pop(LinkStack S, SElemType e)
{
	if (S == NULL)
		return ERROR;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	free(p);
	return OK;
}

//���е�˳���ʾ - ��һά����base[MAXQSIZE]
#define MAXQSIZE 100  //�����г���

typedef char QElemType;

typedef struct
{
	QElemType* base; //��ʼ���Ķ�̬����洢�ռ�
	int front; //ͷָ��
	int rear;  //βָ��
}SqQueue;

//���еĳ�ʼ��
Status InitQueue(SqQueue* Q)
{
	Q->base = (SqQueue*)malloc(sizeof(SqQueue)*MAXQSIZE); //��������ռ�
	if (!Q->base) //�������ʧ��
		exit(OVERFLOW);
	Q->front = Q->rear = 0;//ͷָ���βָ����Ϊ0������Ϊ��
	return OK;
}

//����еĳ���
int QueueLenth(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//ѭ���������
Status EnQueue(SqQueue* Q, QElemType e)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front)
		return ERROR;  //����
	Q->base[Q->rear] = e;  //��Ԫ�ؼ����β
	Q->rear = (Q->rear + 1) % MAXQSIZE; //��βָ���һ
	return OK;
}

//ѭ�����г���
Status DeQueue(SqQueue* Q,QElemType e)
{
	if (Q->rear == Q->front)
		return ERROR; //�ӿ�
	e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

//ȡ��ͷԪ��
SElemType GetHead(SqQueue Q)
{
	if (Q.front != Q.rear) //���в�Ϊ��
		return Q.base[Q.front]; //��ͷָ��Ԫ�ص�ֵ����ͷָ�벻��
}