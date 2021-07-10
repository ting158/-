#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef  char* KeyType;
typedef  char* InfoType;

//�����������Ĵ洢�ṹ
typedef struct
{
	KeyType key;   //�ؼ�����
	InfoType otherinfo;  //����������
}ElemType;

typedef struct BSTNode
{
	ElemType data;      //������
	struct BSTNode* lchild, * rchild; //���Һ���ָ��
}BSTNode,*BSTree;

BSTree T; //�������������T


//�����������ĵݹ����
BSTree SearchBST(BSTree T, KeyType key)
{
	if ((!T) || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key); //���������м�������
	else
		return SearchBST(T->rchild, key); //���������м�������
}