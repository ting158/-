#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


//����ʽ��˳��洢�ṹ���Ͷ���

#define MAXSIZE 1000//����ʽ���ܴﵽ����󳤶�

typedef struct  //����ʽ������Ķ���
{
	float p; //ϵ��
	int e; //ָ��
}Polynomial;

typedef struct
{
	Polynomial* elem; //�洢�ռ�Ļ���ַ
	int length;  //����ʽ�е�ǰ��ĸ���
}SqList;


//���Ա�L�ĳ�ʼ��
int InitList_Sq(SqList* L)
{
	L->elem = (SqList*)malloc(sizeof(SqList) * MAXSIZE);
	if (!(L->elem))
	{
		exit(-2);//exit() һ��0Ϊ�����˳�����0Ϊ�쳣�˳�
	}
	L->length = 0;
	return 1;
}

//�������Ա�
void DestroyList(SqList* L)
{
	if (L->elem)
	{
		free(L->elem);
	}
}

//������Ա�L
void ClearList(SqList* L)
{
	L->length = 0;  //�����Ա�����Ϊ0
}

//�����Ա���
int GetLength(SqList* L)
{
	return L->length;
}

//�ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList* L)
{
	if (L->length == 0)
		return 1;
	else
		return 0;
}

//˳����ȡֵ���ܾ�λ��i��ȡ��Ӧλ������Ԫ�ص����ݣ�
int GetElem(SqList* L, int i, Polynomial* e)
{
	if (i < 1 || i > L->length)
	{
		return 0;
	}
	*e = L->elem[i - 1];
	return 1;
}

//˳���Ĳ���
int LocateElem(SqList* L, int e)
//�����Ա�L�в���ֵΪe������Ԫ�أ���������ţ��ǵڼ���Ԫ�أ�
{
	int i = 0;
	for (i = 0;i < L->length;i++)
	{
		if ((L->elem)->e == e)
			return i + 1;//���ҳɹ����������
	}
	return 0;//����ʧ�ܣ�����0
}

//˳���Ĳ���
int ListInsert_Sq(SqList* L, int i, Polynomial* e)
{
	int j = 0;
	if (i < 1 || i > L->length)
		return 0;
	if (L->length == MAXSIZE)
		return 0;
	for (j = L->length - 1;j >= i - 1;j--)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i] = *e;
	L->length++;
	return 1;
}

//˳����ɾ��
int ListDelete_Sq(SqList* L, int i)
{
	int j = 0;
	if (i < 1 || i > L->length)
		return 0;
	for (j = i;j <= L->length - 1;j++)
	{
		L->elem[j - 1] = L->elem[j];
	}
	L->length--;
	return 1;
}