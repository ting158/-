#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//���Ա�

#define LIST_INIT_SIZE 100 //���Ա���ռ�ĳ�ʼ������
#define LISTINCREMENT 4   //���Ա�洢�ռ�ķ�������

typedef int ElemType;

typedef struct
{
	ElemType* elem;  //�洢�ռ����ַ
	int length;  //��ǰ����
	int listsize;  //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;

//��������Ա�
void InitList_Sq(SqList* L)
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(L->elem))
	{
		printf("����ʧ��\n");
		exit(1);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	printf("����ɹ�\n");
}

int main()
{
	SqList L;
	InitList_Sq(&L);

	free(L.elem);
	return 0;
}