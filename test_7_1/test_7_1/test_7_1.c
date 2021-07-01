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
typedef int ElemType;
typedef int TElemType;
typedef char** HuffmanCode;


//��������
int s1, s2;
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, *HuffmanTree;

void CreatHuffmanTree(HuffmanTree HT, int n) //�����������
{
	if (n <= 1)
		return;
	int i;
	int m = 2 * n - 1; //Ԫ�ظ���
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); //0�ŵ�Ԫδ�ã�HT[m]��ʾ���ڵ�
	for (i = 1;i <= m;i++) //��2n-1��Ԫ�ص�lch��rch��parent��Ϊ0
	{
		HT[i].parent = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
	}
	for (i = 1;i <= n;i++)
	{
		scanf("%d", HT[i].weight);//����ǰn��Ԫ�ص�weightֵ
	}
	//��ʼ�����������濪ʼ������������

	for (i = n + 1;i <= m;i++) //�ϲ�����n-1�����--�����������
	{
		Select(HT, i - 1, s1, s2); //��HT[k](1<=k<=i-1)��ԭ��������˫����Ϊ0
		                           //��Ȩֵ��С�Ľ�㣬������������HT�����s1��s2
		HT[s1].parent = i; HT[s2].parent = i; //��ʾ��F��ɾ��s1��s2
		HT[i].lch = s1; HT[i].rch = s2; //s1,s2�ֱ���Ϊi�����Һ���
		HT[i].weight = HT[s1].weight + HT[s2].weight; //i��ȨֵΪ���Һ���Ȩֵ֮��
	}
}

//����������
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode HC, int n)
//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
{
	int i, start, c, f;
	HC = (char**)malloc((n + 1) * sizeof(char*)); //����n���ַ������ͷָ��ʸ��
	char* cd = (char)malloc(n * sizeof(char)); //������ʱ��ű���Ķ�̬����ռ�
	cd[n - 1] = '\0'; //���������
	for (i - 1;i <= n;i++) //����ַ������������
	{
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (!f)  //��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�����ڵ�
		{
			start--; //����һ��start��ǰָһ��λ��
			if (HT[f].lch == c) //���ӣ������ɴ���0
				cd[start] = '0';
			else                //�Һ���Ϊ1
				cd[start] = '1';
			c = f;
			f = HT[f].parent; //�������ϻ���
		}    //�����i���ַ��ı���
		HC[i] = (char*)malloc((n - start) * sizeof(char));//Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &cd[start]);//����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
	}
	free(cd); //�ͷ���ʱ�ռ�
	cd = NULL;
}