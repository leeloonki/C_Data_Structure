#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���������ṹ��
struct BinaryNode
{
	char ch; //������ �����ĸ
	struct BinaryNode* lChild; //������ָ��
	struct BinaryNode* rChild; //������ָ��
};

//�ݹ����
void recursion(struct BinaryNode* root)
{
	if (root == NULL)//ĳ�ڵ㲻������root=NULL
	{
		return; //������������
	}

	//�������    �ȸ� ���� ����
	printf("%c ", root->ch);

	recursion(root->lChild);

	recursion(root->rChild);
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

	//�ݹ����
	recursion(&nodeA);
}


int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}