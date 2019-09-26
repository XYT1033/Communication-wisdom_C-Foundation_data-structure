#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<time.h>
#include<sys/timeb.h>

#define MAX 5000000

long getSystemTime(){
	struct timeb tb;
	ftime(&tb);

	return tb.time * 1000 + tb.millitm;
}

//��������
int* CreateArray(){
	
	srand((unsigned int)time(NULL));
	int* arr = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++){
		arr[i] = rand() % MAX;
	}

	return arr;
}

//��ӡ
void PrintArray(int arr[], int len){
	for (int i = 0; i < len; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�ϲ��㷨 ��С����
void Merge(int arr[], int start, int end, int mid, int* temp){

	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//��ʾ�����ռ��ж��ٸ�Ԫ��
	int length = 0;

	//�ϲ�������������
	while (i_start <= i_end && j_start <= j_end){

		if(arr[i_start] < arr[j_start]){
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}else{
			temp[length] = arr[j_start];
			j_start++;
			length++;
		}
	}

	//i�������
	while (i_start <= i_end){
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}

	//j����
	while (j_start <= j_end){
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}

	//�����ռ����ݸ���ԭ�ռ�
	for (int i = 0; i < length;i++){
		arr[start + i] = temp[i];
	}

}

//�鲢����
void MergeSort(int arr[],int start,int end,int* temp){

	if (start >= end){
		return;
	}

	int mid = (start + end) / 2;
	//����
	//����
	MergeSort(arr,start,mid,temp);
	//�Ұ��
	MergeSort(arr, mid + 1, end,temp);
	//�ϲ�
	Merge(arr,start,end,mid,temp);
}

//�������� ��С����
void QuickSort(int arr[], int start, int end){

	int i = start;
	int j = end;
	//��׼��
	int temp = arr[start];
	if (i < j){

		while (i < j){

			//��������ȥ�ұȻ�׼��С��
			while (i < j && arr[j] >= temp){
				j--;
			}
			//���
			if (i < j){
				arr[i] = arr[j];
				i++;
			}
			//�������� �ұȻ�׼�������
			while (i < j && arr[i] < temp){
				i++;
			}
			//���
			if (i < j){
				arr[j] = arr[i];
				j--;
			}
		}

		//�ѻ�׼���ŵ�iλ��
		arr[i] = temp;
		//����벿�ֽ��п�������
		QuickSort(arr, start, i - 1);
		//���Ұ벿�ֽ��п�������
		QuickSort(arr, i + 1, end);

	}

}

//��С����
void ShellSort(int arr[], int length){

	int increasement = length;
	int i, j, k;

	do{

		//ȷ�����������
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++){

			for (j = i + increasement; j < length; j += increasement){

				if (arr[j] < arr[j - increasement]){

					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement){
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}

			}

		}
	} while (increasement > 1);

}

int main(void){

	int* myArr = CreateArray();
	//PrintArray(myArr,MAX);
	//�����ռ�
	int* temp = (int*)malloc(sizeof(int)* MAX);
	long t_start = getSystemTime();
	MergeSort(myArr, 0, MAX - 1, temp);
	//QuickSort(myArr,0,MAX -1);
	//ShellSort(myArr,MAX);
	long t_end = getSystemTime();
	//PrintArray(myArr, MAX);
	printf("����%d����������ʱ��:%ld\n",MAX,t_end - t_start);

	//�ͷſռ�
	free(temp);
	free(myArr);
	return 0;
}