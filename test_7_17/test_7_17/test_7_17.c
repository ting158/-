#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 20 //���¼������20��
typedef int KeyType; //��ؼ���Ϊ������
typedef char InfoType;

typedef struct  //����ÿ����¼������Ԫ�أ��Ľṹ
{
	KeyType key;  //�ؼ���
	InfoType otherinfo; //����������
}RedType; //Record Type

typedef struct  //����˳���Ľṹ
{
	RedType r[MAXSIZE + 1]; //�洢˳��������
	                        //r[0]һ�����ڱ��򻺳���
	int length; //˳���ĳ���
}SqList;


//ֱ�Ӳ��������㷨
void InserSort(SqList* L)
{
	int i, j;
	for (i = 2;i <= L->length;i++)
	{
		if (L->r[i].key < L->r[i - 1].key)
		{
			L->r[0] = L->r[i];
		}
		for (j = i - 1;L->r[0].key < L->r[j].key;j--)
		{
			L->r[j + 1] = L->r[j];
		}
		L->r[j + 1] = L->r[0];
	}
}