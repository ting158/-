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
typedef char VerTexType; //�趨�����������Ϊ�ַ���
typedef int ArcType; //����ߵ�Ȩֵ����Ϊ����
typedef int OtherInfo;


//ͼ���ڽӱ�洢��ʾ

#define MVNum 100  //��󶥵���

typedef struct ArcNode  //�߽��
{
	int adjvex; //�ñ���ָ��Ķ����λ��
	struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
	OtherInfo info; //�ͱ���ص���Ϣ
}ArcNode; 

typedef struct VNode
{
	VerTexType data; //������Ϣ
	ArcNode* firstarc; //ָ���һ�������ö���ıߵ�ָ��
}VNode, AdjList[MVNum]; //AdjList��ʾ�ڽӱ�����

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
}ALGraph;


//�����ڽӱ��ʾ������������
Status CreateUDG(ALGraph* G) //�����ڽӱ��ʾ������������ͼG
{
	int i, j, k;
	int v1, v2;
	ArcNode* p1, *p2;
	scanf("%d%d", &(G->vexnum), &(G->arcnum)); //�����ܶ��������ܱ���
	for (i = 0;i < G->vexnum;i++) //�����ͷ����
	{
		scanf("%d", &(G->vertices[i].data)); //���붥��ֵ
		G->vertices->firstarc = NULL; //��ʼ����ͷ����ָ����
	}
	for (k = 0;k < G->vexnum;k++) //�����ڽӱ�
	{
		scanf("%d%d", &v1, &v2); //����һ������������������
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);  //����v1��v2��G�е�λ��
		p1->adjvex = j; //�ٽ�����Ϊj
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1; //���½��*p1���붥��v[i]�ı߱�ͷ��
		p2->adjvex = i; //�ڽӵ����Ϊi
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2; //���½��*p2���붥��v[j]�ı߱�ͷ��
	}
	return OK;
}