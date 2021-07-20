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


//�۰��������
void BInsertSort(SqList* L) {
	int low, high, mid, i, j;
	for (i = 2;i <= L->length;i++) { //���β����2-n��Ԫ��
		L->r[0] = L->r[i]; //��ǰ����Ԫ�ش浽�ڱ�λ��
		low = 1;
		high = i - 1; //���ö��ֲ��ҷ����Ҳ���λ��
		while (low <= high) {
			mid = (low + high) / 2;
			if (L->r[0].key > L->r[mid].key)
				low = mid + 1;
			else
				high = mid - 1;
		} //ѭ��������high + 1��Ϊ����λ��
		for (j = i - 1;j > high + 1;j--) //�ƶ�Ԫ��
			L->r[j + 1] = L->r[j]; 
		L->r[high + 1] = L->r[0]; //���뵽��ȷλ��
	}
}



//��������
int Partition(SqList* L, int low, int high) {
	int pivotkey = L->r[low].key;
	L->r[0] = L->r[low];
	while (low < high) {
		while (low < high && L->r[high].key >= pivotkey)
			high--;
		L->r[low] = L->r[high];
		while (low < high && L->r[high].key <= pivotkey)
			low++;
		L->r[high] = L->r[low];
	}
	L->r[low] = L->r[0];
	return low;
}

void QSort(SqList* L, int low, int high) { //��˳���L��������
	int pivotloc;
	if (low < high) { //���ȴ���1
		pivotloc = Partition(L, low, high); //��L.r[low...high]һ��Ϊ����pivotlocΪ��ŦԪ���ź���λ��
		QSort(L, low, pivotloc - 1); //�Ե��ӱ�ݹ�����
		QSort(L, pivotloc + 1, high); //�Ը��ֱ�ݹ�����
	}
}

void main() {
	SqList L;
	QSort(&L, 1, L.length);
}