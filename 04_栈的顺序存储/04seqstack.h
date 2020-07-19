#pragma once
#define MAX 1024

typedef void* SeqStack;

//初始化栈
SeqStack init_SeqStack();

//入栈(本质是数组尾插)
void push_SeqStack(SeqStack stack, void* data);

//出栈
void pop_SeqStack(SeqStack stack);

//返回栈顶元素
void* top_SeqStack(SeqStack stack);

//返回栈大小
int size_SeqStack(SeqStack stack);

//判断栈为空
int empty_SeqStack(SeqStack stack);

//销毁栈
void destory_SeqStack(SeqStack stack);
