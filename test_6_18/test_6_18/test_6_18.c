#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int TElemType;

//��ʽ�������洢�ṹ
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild; //���Һ���ָ��
}BiNode,*BiTree;