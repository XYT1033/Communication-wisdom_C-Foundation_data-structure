#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 20

long getSystemTime(){
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//��������
void Swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int flag = 0; //0 ��ʶû�������
//ð������
void BubbleSort(int arr[],int length){

	for (int i = 0; i < length && flag == 0; i++){
		flag = 1; //��Ϊ�Ѿ������
		for (int j =  length - 1; j > i;j--){
			if (arr[j-1] < arr[j]){		
				flag = 0;
				Swap(&arr[j - 1],&arr[j]);
			}
		}
	}

}

//��ӡ����
void PrintArray(int arr[],int length){
	for (int i = 0; i < length; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}	

int main(void){
	
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX;i++){
		arr[i] = rand() % MAX;
	}

	printf("����ǰ:\n");
	//PrintArray(arr,MAX);
	long t_start = getSystemTime();
	BubbleSort(arr,MAX);
	long t_end = getSystemTime();
	printf("ð������%d��Ԫ�أ�����ʱ��:%ld\n", MAX, t_end- t_start);
	printf("�����:\n");
	for (int i = 0; i < MAX; i++) {
		printf("NUM:%d\n", arr[i]);
	}
	//PrintArray(arr, MAX);




	system("pause");
	return 0;
}