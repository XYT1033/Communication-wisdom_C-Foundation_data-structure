#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"

#define M 8
#define N 3

typedef struct MYNUM{
	CircleLinkNode node;
	int val;
}MyNum;

void MyPrint(CircleLinkNode* data){
	MyNum* num = (MyNum*)data;
	printf("%d ",num->val);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2){
	MyNum* num1 = (MyNum*)data1;
	MyNum* num2 = (MyNum*)data2;
	if (num1->val == num2->val){
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

int main(void){

	//����ѭ������
	CircleLinkList* clist = Init_CircleLinkList();
	//�����������
	MyNum num[M];
	for (int i = 0; i < 8;i ++){
		num[i].val = i + 1;
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);
	}

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);
	printf("\n");


	int index = 1;
	//����ָ��
	CircleLinkNode* pCurrent = clist->head.next;
	while (Size_CircleLinkList(clist) > 1){
		
		if (index == N){
			
			MyNum* temNum = (MyNum*)pCurrent;
			printf("%d ", temNum->val);

			//�����ɾ��������һ�����
			CircleLinkNode* pNext = pCurrent->next;
			//����ֵɾ��
			RemoveByValue_CircleLinkList(clist, pCurrent, MyCompare);
			pCurrent = pNext;
			if (pCurrent == &(clist->head)){
				pCurrent = pCurrent->next;
			}
			index = 1;
		}

		pCurrent = pCurrent->next;
		if (pCurrent == &(clist->head)){
			pCurrent = pCurrent->next;
		}
		index++;
	}

	if (Size_CircleLinkList(clist) == 1){
		MyNum* tempNum = (MyNum*)Front_CircleLinkList(clist);
		printf("%d ",tempNum->val);
	}
	else{
		printf("����!");
	}

	printf("\n");

	//�ͷ������ڴ�
	FreeSpace_CircleLinkList(clist);
	



	system("pause");
	return 0;
}