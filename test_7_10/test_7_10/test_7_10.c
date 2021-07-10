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



//�۰���� - �ҵ������±꣬�Ҳ�������0
int Search_Bin(SSTable ST, KeyType key)
{
	int low = 1;
	int high = ST.length;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ST.R[mid].key == key)
			return mid;  //�ҵ�����Ԫ��
		else if (key < ST.R[mid].key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0; //˳����в����ڴ���Ԫ��
}


//�۰���� - �ݹ��㷨
int Search_Bin_Rec(SSTable ST, KeyType key, int low, int high)
{
	int mid;
	if (low > high)
		return 0;
	mid = (low + high) / 2;
	if (key == ST.R[mid].key)
		return mid;
	else if (key < ST.R[mid].key)
		Search_Bin_Rec(ST, key, low, mid - 1);
	else
		Search_Bin_Rec(ST, key, low + 1, high);
}