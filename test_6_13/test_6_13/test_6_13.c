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

//˳��ջ�ı�ʾ
#define MAXSIZE 100
typedef struct
{
	char name[20];
	int age;
}SElemType;
typedef struct
{
	SElemType* base; //ջ��ָ��
	SElemType* top;   //ջ��ָ��
	int stacksize;    //ջ�����������
}SqStack;


//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack S)
{
	S.base = (SElemType*)malloc(sizeof(SqStack) * MAXSIZE);
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base; //ջ��ָ�����ջ��ָ��
	S.stacksize = MAXSIZE;
	return OK;
}

//�ж�˳��ջ�Ƿ�Ϊ��
//��Ϊ�գ�����TRUE,���򷵻�FALSE
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

//��˳��ջ�ĳ���
int StackLenth(SqStack S)
{
	return S.top - S.base;
}

//���˳��ջ
Status ClearStack(SqStack S)
{
	if (S.base)
		S.top = S.base;
	return OK;
}

//����˳��ջ
Status DestroyStack(SqStack S)
{
	if (S.base)
	{
		free(S.base);
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//˳��ջ����ջ
Status Push(SqStack* S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)
		return ERROR;
	*S->top = e;
	S->top++;
	return OK;
}

//˳��ջ�ĳ�ջ
Status Pop(SqStack S, SElemType* e)
{
	if (S.top = S.base)
		return ERROR;
	e = --S.top;
	return OK;
}