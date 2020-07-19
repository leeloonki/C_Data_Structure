#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
//���������ṹ��
struct BinaryNode
{
	char ch; //��ʾ���� ��ĸ
	struct BinaryNode* lChild; //������
	struct BinaryNode* rChild; //������
};

//ͳ��Ҷ������
void calculateLeafNum(struct BinaryNode* root, int* p)
{
	if (root == NULL)
	{
		return;
	}

	//�����������������ͬʱΪ�� ��ΪҶ��
	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*p)++; //ͳ�Ƶ�Ҷ������++
	}

	calculateLeafNum(root->lChild, p);

	calculateLeafNum(root->rChild, p);
}

//��ȡ���߶�
int getTreeHeight(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	//���������߶�
	int lHeight = getTreeHeight(root->lChild);
	//���������߶�
	int rHeight = getTreeHeight(root->rChild);
	//ȡ���ֵ +1 
	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

	return height;
}

//����������
struct BinaryNode* copyTree(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//1���ȿ���������
	struct BinaryNode* lChild = copyTree(root->lChild);

	//2���ٿ���������
	struct BinaryNode* rChild = copyTree(root->rChild);

	//3����������㣬��������������  
	struct BinaryNode* newNode = malloc(sizeof(struct BinaryNode));
	newNode->lChild = lChild;
	newNode->rChild = rChild;
	newNode->ch = root->ch;

	return newNode;
}

void recursion(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}



	recursion(root->lChild);

	printf("%c ", root->ch);

	recursion(root->rChild);
}

//�ͷ���
void freeTree(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//���ͷ�������  
	freeTree(root->lChild);
	//���ͷ�������
	freeTree(root->rChild);

	printf("%c���ͷ���\n", root->ch);
	//���ͷŸ�
	free(root);

}

void test01()
{
	//�������������
	struct BinaryNode nodeA = { 'A', NULL, NULL };
	struct BinaryNode nodeB = { 'B', NULL, NULL };
	struct BinaryNode nodeC = { 'C', NULL, NULL };
	struct BinaryNode nodeD = { 'D', NULL, NULL };
	struct BinaryNode nodeE = { 'E', NULL, NULL };
	struct BinaryNode nodeF = { 'F', NULL, NULL };
	struct BinaryNode nodeG = { 'G', NULL, NULL };
	struct BinaryNode nodeH = { 'H', NULL, NULL };

	//�������֮��Ĺ�ϵ
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//1��ͳ��Ҷ������
	int num = 0;
	calculateLeafNum(&nodeA, &num);

	printf("����Ҷ������Ϊ: %d\n", num);


	//2�����������/�߶�
	int height = getTreeHeight(&nodeA);

	printf("���ĸ߶�Ϊ: %d\n", height);

	//3������������
	struct BinaryNode* newTree = copyTree(&nodeA);
	//������������
	recursion(newTree);

	printf("\n--------------------\n");
	//4���ͷŶ�����
	freeTree(newTree);
}

int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}*/