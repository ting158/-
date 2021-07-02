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

typedef int Status;


//�ڽӾ���Ĵ洢��ʾ

#define MaxInt 32767 //��ʾ����ֵ������
#define MVNum 100 //��󶥵���
typedef char VerTexType; //�趨�����������Ϊ�ַ���
typedef int ArcType; //����ߵ�Ȩֵ����Ϊ����

typedef struct
{
	VerTexType vexs[MVNum];  //�����
	ArcType arcs[MVNum][MVNum];  //�ڽӾ���
	int vexnum, arcnum;  //ͼ�ĵ�ǰ�����ͱ���
}AMGraph;


//�����㷨����ͼ�в��Ҷ���
int LocateVex(AMGraph G, VerTexType u)
//��ͼG�в��Ҷ���u�������򷵻ض�����е��±ꣻ���򷵻�-1
{
	int i;
	for (i = 0;i < G.vexnum;i++)
	{
		if (u == G.vexs[i])
			return i;
	}
	return -1;
}

//�����ڽӾ����ʾ������������
Status CreateUDN(AMGraph* G)  //�����ڽӾ����ʾ��������������G
{
	int i, j, k;
	char v1, v2;
	int w;
	scanf("%d%d", &G->vexnum, &G->arcnum); //�����ܶ��������ܱ���
	for (i = 0; i < G->vexnum; i++) //������������Ϣ
	{
		scanf("%c", &(G->vexs[i]));
	}
	for (i = 0;i < G->vexnum;i++) //�ߵ�Ȩֵ����Ϊ����ֵ
	{
		for (j = 0;j < G->vexnum;j++)
		{
			G->arcs[i][j] = MaxInt;
		}
	}
	for (k = 0;k < G->arcnum;k++)  //�����ڽӾ���
	{
		scanf("%c%c%d", &v1, &v2, &w); //����һ�����������Ķ��㼰�ߵ�Ȩֵ
		i = LocateVex(G, v1);
		j = LocateVex(G, v2); //ȷ��v1��v2��G�е�λ��
		G->arcs[i][j] = w; //��<v1,v2>��Ȩֵ��Ϊw
		G->arcs[j][i] = w; //��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw
	}
	return OK;
}

