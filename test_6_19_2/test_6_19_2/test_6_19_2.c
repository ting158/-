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
typedef int TElemType;

//��ʽ�������洢�ṹ
typedef struct BiTNode
{
	TElemType data;//������
	struct BiTNode* lchild, * rchild; //���Һ��ӽ��
}BiNode, * BiTree;

//�������Ķ������Ͷ���
#define MaxSize 100
typedef struct
{
	BiNode data[MaxSize]; //��Ŷ���Ԫ��
	int front, rear; //��ͷ�Ͷ�βָ��
}SqQueue;  //˳��ѭ����������


//���ƶ�����
int Copy(BiTree T, BiTree P)
{
	if (T == NULL)
	{
		P == NULL;
		return 0;
	}
	else
	{
		P = (BiTree)malloc(sizeof(BiNode));
		P->data = T->data;
		Copy(T->lchild, P->lchild);
		Copy(T->rchild, P->rchild);
	}
}

//������������

//����������
void CreatBiTree(BiTree* T)
{
	char c;
	scanf("%c", &c);
	if (c == '#')
		*T = NULL;
	else
	{
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
}
int Depth(BiTree T)
{
	int m, n;
	if (T == NULL)
		return 0;
	else
	{
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

int main()
{
	BiTree T = NULL;
	printf("������һ����������#Ϊ����������");
	CreatBiTree(&T);
	printf("�����������Ϊ%d\n", Depth(T));
	return 0;
}
