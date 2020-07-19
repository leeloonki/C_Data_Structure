#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "04seqstack.h"
//���������ṹ��
struct BinaryNode
{
	char ch; //��ʾ���� ��ĸ
	struct BinaryNode* lChild; //������
	struct BinaryNode* rChild; //������
	int flag; //��־ Ĭ��Ϊ��
};
/*
1�����������ջ
2��ֻҪsize>0 ִ��ѭ��
	��ȡջ��Ԫ��  top
	��ջ   pop
	�жϱ�־ ���Ϊ��  ���ִ����һ��ѭ��
	���Ϊ��  ����־��Ϊ��
	����������������������ջ
*/

//�ǵݹ����
void nonRecursion(struct BinaryNode* root)
{
	//��ʼ��ջ
	SeqStack stack = init_SeqStack();

	//1.���ڵ���ջ
	push_SeqStack(stack, root);

	while (size_SeqStack(stack) > 0)
	{
		//��ȡջ��
		struct BinaryNode* topNode = top_SeqStack(stack);

		//��ջ
		pop_SeqStack(stack);

		//���Ϊ�� ��ӡ
		if (topNode->flag)
		{
			printf("%c ", topNode->ch);
			continue;
		}

		//���Ϊ��  ����־��Ϊ��
		topNode->flag = 1;

		//��������������������ջ
		if (topNode->rChild != NULL)
		{
			push_SeqStack(stack, topNode->rChild);
		}

		if (topNode->lChild != NULL)
		{
			push_SeqStack(stack, topNode->lChild);
		}

		push_SeqStack(stack, topNode);
	}

	//����ջ
	destory_SeqStack(stack);
}

void test01()
{
	//�������������
	struct BinaryNode nodeA = { 'A', NULL, NULL ,0 };
	struct BinaryNode nodeB = { 'B', NULL, NULL ,0 };
	struct BinaryNode nodeC = { 'C', NULL, NULL ,0 };
	struct BinaryNode nodeD = { 'D', NULL, NULL ,0 };
	struct BinaryNode nodeE = { 'E', NULL, NULL ,0 };
	struct BinaryNode nodeF = { 'F', NULL, NULL ,0 };
	struct BinaryNode nodeG = { 'G', NULL, NULL ,0 };
	struct BinaryNode nodeH = { 'H', NULL, NULL ,0 };

	//�������֮��Ĺ�ϵ
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//�ǵݹ����
	nonRecursion(&nodeA);
}


int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}