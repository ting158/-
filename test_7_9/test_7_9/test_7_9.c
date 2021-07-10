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

typedef  char *KeyType;

typedef struct
{
	KeyType key; //�ؼ�����
	//...        //������
}ElemType;

//˳���ṹ���Ͷ���
typedef struct
{
	ElemType* R; //���ַ
	int length; //��
}SSTable;

SSTable ST; //����˳���ST


//���ɹ�����λ����Ϣ�����򷵻�0
int Search_Seq(SSTable ST, KeyType key)
{
	int i;
	for (i = ST.length;i >= 1;i--)
	{
		if (ST.R[i].key == key)
			return i;
	}
	return 0;
}