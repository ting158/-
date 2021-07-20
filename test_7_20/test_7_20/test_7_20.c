#define _CRT_SECURE_NO_WARNINGS 1

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


//��ѡ�������㷨
void SelectSort(SqList* L) {
	int i, j, k;
	RedType tmp;
	for (i = 1;i < L->length;i++) {
		k = i;
		for (j = i + 1;j <= L->length;j++)
			if (L->r[j].key < L->r[k].key)
				k = j; //��¼��Сֵλ��
		if (k != i) {  //����
			tmp = L->r[i];
			L->r[i] = L->r[k];
			L->r[k] = tmp;
		}
	}
}

typedef int elem;
//������

//ɸѡ����
void HeapAdjust(elem R[], int s, int m)
/*
��֪R[s...m]�м�¼�Ĺؼ��ֳ�R[s]֮�������ѵĶ��壬
����������R[s]�Ĺؼ��֣�ʹR[s...m]��Ϊһ�������
*/
{
	int rc = R[s];
	for (int j = 2 * s;j <= m;j *= 2) //��key�ϴ�ĺ��ӽ������ɸѡ
	{
		if (j < m && R[j] < R[j + 1]) //jΪkey�ϴ�ļ�¼���±�
			j++;
		if (rc >= R[j])
			break;
		R[s] = R[j];
		s = j;   //rcӦ������λ��s��
	}
	R[s] = rc; //����
}