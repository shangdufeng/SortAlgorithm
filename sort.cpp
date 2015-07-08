#include<stdio.h>
#include <malloc.h>
#include <memory.h>

void Print(int *A, int len);
void swap(int &a, int &b);
void OrderMin(int *A, int start, int end);

void InsertSort(int *A, int len);                        //��������
void Recursive_InsertSort(int *A, int start, int end);   //�ݹ���������
void BubbleSort(int *A, int len);                        //ð������
void Recursive_BubbleSort(int *A, int start, int end);   //�ݹ��ð������
void Improved_BubbleSort(int *A, int len);               //�Ľ���ð������
void SelectionSort(int *A, int len);                     //ѡ������
void Recursive_SelectionSort(int *A, int start, int end);//�ݹ��ѡ������
void MergeSort(int *A, int len);                         //�鲢����
void QuickSort(int *A, int len);                         //��������
void HeapSort(int *A, int len);                          //������

int main()
{
	int A[20] = {8,2,9,10,25,36,5,7,6,3,4,78,69,56,45,15,18,98,23,29};
	Print(A, 20);
//	InsertSort(A, 20);
//	Recursive_InsertSort(A, 0, 19);
//	BubbleSort(A, 20);
//	Recursive_BubbleSort(A,0,20);
//	Improved_BubbleSort(A, 20);
//	SelectionSort(A, 20);
//	Recursive_SelectionSort(A, 0, 20);
//	MergeSort(A,20);
//	QuickSort(A,20);
	Print(A, 20);
	int wait;
	scanf("%d", &wait);
	return 0;
}

void Print(int *A, int len)
{
	for(int i=0; i<len; i++)
		printf("%d ", A[i]);
	printf("%c",'\n');
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void OrderMin(int *A, int start, int end)
{
	for(int i=end-1; i > start; i--)
		if(A[i] < A[i-1])
			swap(A[i], A[i-1]);
}

//��������, ���������������ź���ʱ���Ӷ�ΪO(n)
//����������Ϊ����ʱ�����Ӷ�ΪO(n^2)��������Եĸ����й�
//�ʺ�����Ԫ�ص�����

void InsertSort(int *A, int len)    
{
	int i, j, key;
	for(i=1; i<len; i++){
		j = i-1;
		key = A[i];
		while(j>-1 && A[j]>key){    /*ǰA[0...i-1]������*/
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

//�ݹ��ʵ��
void Insert(int *A, int start, int end)
{
	int key = A[end+1];
	int j = end;
	while(j>-1 && A[j]>key){
		A[j+1] = A[j];
		j--;
	}
	A[j+1] = key;
}

void Recursive_InsertSort(int *A, int start, int end)
{
	if(start<end){
		Recursive_InsertSort(A, start, end-1);
		Insert(A, start, end-1);
	}
}

//ð�����򣬸��Ӷ�ΪO(n^2)
void BubbleSort(int *A, int len)
{
	int i,j;
	for(i=0; i<len; i++)
		for(j=0; j<len-i-1; j++)
			if(A[j] > A[j+1])
				swap(A[j], A[j+1]);
}

//�ݹ��ð������
void Recursive_BubbleSort(int *A, int start, int end)
{
	if(start < end){
		OrderMin(A, start, end);
		Recursive_BubbleSort(A, start+1, end);
	}
}

//�Ľ���ð������,��Ѹ��Ӷ�O(n)
void Improved_BubbleSort(int *A, int len)
{
	bool flag = true;
	int i,j;
	for(i=0; i<len; i++){
		if(!flag) return;
		flag = false;
		for(j=0; j<len-i-1; j++)
			if(A[j] > A[j+1]){
				swap(A[j], A[j+1]);
				flag = true;
			}
	}
}

//ѡ�����򣬲��ȶ�����
//���Ӷ�ΪO(n^2)
void SelectionSort(int *A, int len)
{
	int Min = 0;
	for(int i=0; i < len-1; i++){
		Min = i;
		for(int j = i+1; j < len; j++)
			if(A[Min] > A[j])
				Min = j;
		swap(A[Min], A[i]);
	}
}

//�ݹ��ѡ������
void Recursive_SelectionSort(int *A, int start, int end)
{
	if(start < end){
		OrderMin(A,start,end);
		Recursive_SelectionSort(A, start+1, end);
	}
}

//�鲢���򣬸��Ӷ�O(nlogn)
void Merge(int *A, int start, int middle, int end)
{
	int len = end-start;
	int *T = (int *)malloc(len*sizeof(int));
	int i = start;
	int j = middle;
	int k = 0;
	while(i<middle&&j<end){
		if(A[i] <= A[j]){
			T[k++] = A[i];
			i++;
		}
		else{
			T[k++] = A[j];
			j++;
		}
	}
	if(i==middle)
		for(; j<end; j++)
			T[k++] = A[j];
	if(j==end)
		for(; i<middle; i++)
			T[k++] = A[i];
//	Print(T, len);
	i = 0;
	while(start < end)
		A[start++] = T[i++];
	free(T);
}
void RecursiveMergeSort(int *A, int start, int end)
{
	if(start < end-1){
		int middle = (start + end)/2;
		RecursiveMergeSort(A,start,middle);
		RecursiveMergeSort(A,middle,end);
		Merge(A,start,middle,end);
	}
}
void MergeSort(int *A, int len)
{
	RecursiveMergeSort(A, 0, len);
}

//��������,���ȶ�����
//����������������ʱ�����Ӷ�ΪO(n^2)
//��Ѹ��Ӷ�ΪO(nlogn)
int Partition(int *A, int start, int end)
{
	int low = start;
	int high = end-1;
	int pivot = A[end-1];
	while(low < high){
		while(low<high && A[low]<=pivot)
			low++;
		A[high] = A[low];
		while(low<high && pivot<A[high])
			high--;
		A[low] = A[high];
	}
	A[high] = pivot;
	return high;                              //highΪ���
}
void RecursiveQuickSort(int *A, int start, int end)
{
	if(start<end-1){
		int r = Partition(A,start,end);
		RecursiveQuickSort(A,start,r);
		RecursiveQuickSort(A,r+1,end);
	}
}
void QuickSort(int *A, int len)
{
	RecursiveQuickSort(A, 0, len);
}

//�����򣬲��ȶ�����
//ʱ�临�Ӷ�ΪO(nlogn��
void MaxHeapify(int *A, int n)
{

}
void BuildMaxHeap(int *A, int len)
{

}
void HeapSort(int *A, int len)
{
	BuildMaxHeap(A,len);
	for(int i = len-1; i > 1; i--){
		swap(A[1],A[])
	}
}