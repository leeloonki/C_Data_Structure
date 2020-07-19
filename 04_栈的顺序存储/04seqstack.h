#pragma once
#define MAX 1024

typedef void* SeqStack;

//��ʼ��ջ
SeqStack init_SeqStack();

//��ջ(����������β��)
void push_SeqStack(SeqStack stack, void* data);

//��ջ
void pop_SeqStack(SeqStack stack);

//����ջ��Ԫ��
void* top_SeqStack(SeqStack stack);

//����ջ��С
int size_SeqStack(SeqStack stack);

//�ж�ջΪ��
int empty_SeqStack(SeqStack stack);

//����ջ
void destory_SeqStack(SeqStack stack);
