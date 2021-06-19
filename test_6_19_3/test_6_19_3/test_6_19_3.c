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
typedef int ElemType;
typedef int TElemType;

//����˫�ױ�洢��ʾ

#define MAX_TREE_SIZE 100

typedef struct PTNdode
{
	TElemType data;
	int parent;  //˫��λ����
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n; //������λ�úͽ�����
}PTree;


//���ĺ������ߴ洢��ʾ

typedef struct CTNode  //���ӽ��
{
	int child;   //���ӽ���±�λ��
	struct CTNode* next;
}*ChildPtr;

typedef struct
{
	TElemType data;
	ChildPtr firstchild; //��������ָ��
}CTBox;

typedef struct
{
	CTBox nades[MAX_TREE_SIZE];
	int n, r;  //������͸���λ��
};


//���Ķ����������� - �ֵܣ��洢��ʾ

typedef struct CSNode
{
	ElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
