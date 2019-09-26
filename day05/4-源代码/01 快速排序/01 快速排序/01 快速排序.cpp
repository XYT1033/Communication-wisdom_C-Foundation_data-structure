#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


void PrintArray(int arr[],int len){
	for (int i = 0; i < len;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
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
			while (i<j && arr[j] >= temp ){
				j--;
			}
			//���
			if(i < j){
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
int main(void){


	int myArr[] = {4,2,8,0,5,7,1,3,9};
	int len = sizeof(myArr) / sizeof(int);
	PrintArray(myArr, len);
	QuickSort(myArr,0,len-1);
	PrintArray(myArr, len);

	
	return 0;
}