#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include"04seqstack.h"

//数组的尾部适合做栈顶

//栈的结构体
struct SStack
{
	void* data[MAX];//栈顺序存储底层数组
	int m_Size;//栈大小
};

//初始化栈
SeqStack init_SeqStack()
{
	struct SStack* mystack = malloc(sizeof(struct SStack));
	if (mystack == NULL)
	{
		return NULL;
	}

	//初始化
	mystack->m_Size = 0;
	memset(mystack->data, 0, sizeof(void*) * MAX);
	return mystack;
}

//入栈(本质是数组尾插)
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

//出栈
void pop_SeqStack(SeqStack stack)
{
	//本质是尾删
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

//返回栈顶元素
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

//返回栈大小
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;
	return myStack->m_Size;
}

//判断栈为空
int empty_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;//-1代表真 空栈
	}
	struct SStack* myStack = stack;
	if (myStack->m_Size == 0)
	{
		return 1;//1 也代表真 空栈
	}

	return 0;//0代表假 非空
}

//销毁栈
void destory_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}