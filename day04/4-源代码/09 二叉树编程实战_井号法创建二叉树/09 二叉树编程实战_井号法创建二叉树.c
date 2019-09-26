#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���������
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root){
	if (root == NULL){
		return;
	}

	printf("%c",root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

BinaryNode* CreateBinaryTree(){
	
	fflush(stdin);
	char ch;
	scanf("%c",&ch);

	BinaryNode* node;

	if (ch == '#'){
		node = NULL;
	}
	else{

		node = (BinaryNode*)malloc(sizeof(BinaryNode));
		node->ch = ch;
		node->lchild = CreateBinaryTree();
		node->rchild = CreateBinaryTree();
	}


	return node;
}

int main(void){

	//������
	BinaryNode* root = CreateBinaryTree();
	//��ӡ��
	Recursion(root);
	

	printf("\n");
	system("pause");
	return 0;
}