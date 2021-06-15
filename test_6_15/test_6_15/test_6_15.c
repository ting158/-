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


//���е�˳���ʾ - ��һά����base[MAXQSIZE]
//#define MAXQSIZE 100  //�����г���
//
//typedef char QElemType;
//
//typedef struct
//{
//	QElemType* base; //��ʼ���Ķ�̬����洢�ռ�
//	int front; //ͷָ��
//	int rear;  //βָ��
//}SqQueue;


//�����е����Ͷ���
#define MAXQSIZE 100  //�����г���

typedef char QElemType;

typedef struct Qnode
{
	QElemType data;
	struct Qnode* next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front; //��ͷָ��
	QueuePtr rear;  //��βָ��
}LinkQueue;



//�����еĳ�ʼ��
Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

//����������
Status DestroryQueue(LinkQueue* Q)
{
	LinkQueue* p;
	while (Q->front)
	{
		p = Q->front->next;
		free(Q->front);
		Q->front = p;
		/*Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;*/
	}
	return OK;
}

//��Ԫ��e���
Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//�����г���
Status DeQueue(LinkQueue* Q, QElemType e)
{
	if (Q->front == Q->rear)
		return ERROR;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q->front->next;
	e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}