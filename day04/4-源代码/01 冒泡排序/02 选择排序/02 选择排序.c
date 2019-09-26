#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <time.h>

#define MAX 10000

long getSystemTime(){
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//��������
void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//��ӡ����
void PrintArray(int arr[], int length){
	for (int i = 0; i < length; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//ð������Ľ���
void BubbleSort(int arr[], int length){
	int flag = 0;
	for (int i = 0; i < length && flag == 0; i++){
		flag = 1; //��Ϊ�Ѿ������
		for (int j = length - 1; j > i; j--){
			if (arr[j - 1] < arr[j]){
				flag = 0;
				Swap(&arr[j - 1], &arr[j]);
			}
		}
	}

}


//ѡ������
void SelectSort(int arr[],int length){
	
	//ѡ�������ǲ��Ǽ��ٽ������� 
	for (int i = 0; i < length;i ++){
		int min = i;
		for (int j = i + 1; j < length; j++){
			if (arr[j] < arr[min]){
				min = j;
			}
		}
		if (min != i){
			Swap(&arr[min],&arr[i]);
		}
	}
}


int main(void){
	

	int arr[MAX];
	int arr2[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i ++){
		int randNum = rand() % MAX;
		arr[i] = randNum;
		arr2[i] = randNum;
	}

	//ð������
	long tbubble_start = getSystemTime();
	BubbleSort(arr, MAX);
	long tbubble_end = getSystemTime();
	printf("ð������%d��Ԫ��,����ʱ��:%ld\n", MAX, tbubble_end - tbubble_start);


	//ѡ������
	long tselect_start = getSystemTime();
	SelectSort(arr2, MAX);
	long tselect_end = getSystemTime();
	printf("ѡ������%d��Ԫ��,����ʱ��:%ld\n", MAX, tselect_end - tselect_start);

	system("pause");
	return 0;
}