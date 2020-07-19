#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include"04seqstack.h"

//�����β���ʺ���ջ��

//ջ�Ľṹ��
struct SStack
{
	void* data[MAX];//ջ˳��洢�ײ�����
	int m_Size;//ջ��С
};

//��ʼ��ջ
SeqStack init_SeqStack()
{
	struct SStack* mystack = malloc(sizeof(struct SStack));
	if (mystack == NULL)
	{
		return NULL;
	}

	//��ʼ��
	mystack->m_Size = 0;
	memset(mystack->data, 0, sizeof(void*) * MAX);
	return mystack;
}

//��ջ(����������β��)
void push_SeqStack(SeqStack stack, void* data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct SStack* mystack = stack;
	if (mystack->m_Size == MAX)
	{
		return;
	}

	mystack->data[mystack->m_Size] = data;
	mystack->m_Size++;
}

//��ջ
void pop_SeqStack(SeqStack stack)
{
	//������βɾ
	if (stack == NULL)
	{
		return;
	}
	struct SStack* mystack = stack;

	if (mystack->m_Size == 0)
	{
		return;
	}

	mystack->data[mystack->m_Size - 1] = NULL;
	mystack->m_Size--;
}

//����ջ��Ԫ��
void* top_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct SStack* myStuck = stack;

	if (myStuck->m_Size == 0)
	{
		return NULL;
	}
	return myStuck->data[myStuck->m_Size - 1];
}

//����ջ��С
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;
	return myStack->m_Size;
}

//�ж�ջΪ��
int empty_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;//-1������ ��ջ
	}
	struct SStack* myStack = stack;
	if (myStack->m_Size == 0)
	{
		return 1;//1 Ҳ������ ��ջ
	}

	return 0;//0����� �ǿ�
}

//����ջ
void destory_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}