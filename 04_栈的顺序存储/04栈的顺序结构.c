#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include"04seqstack.h"
//#define MAX 1024

//����
struct Person
{
	char name[64];
	int age;
};
typedef void* SeqStack;

void test01()
{
	//��ʼ��ջ
	SeqStack stack = init_SeqStack();
	//��ջ
	struct Person p1 = {"������",23 };
	struct Person p2 = {"����",19 };
	struct Person p3 = {"�ŷ�",20 };
	struct Person p4 = {"����",22 };
	struct Person p5 = {"�ܰ���",25 };
	struct Person p6 = {"��Ȩ",21 };

	push_SeqStack(stack, &p1);
	push_SeqStack(stack, &p2);
	push_SeqStack(stack, &p3);
	push_SeqStack(stack, &p4);
	push_SeqStack(stack, &p5);
	push_SeqStack(stack, &p6);

	//ֻҪջ��Ϊ�գ��鿴ջ��Ԫ�أ���ִ�г�ջ
	while (!empty_SeqStack(stack))
	{
		struct Person* pTop = top_SeqStack(stack);
		printf("<��ǰջ��Ԫ��>  ������%s��\t���䣺%d\n", pTop->name, pTop->age);

		pop_SeqStack(stack);
	}
	//ջ��С
	printf("ջ�Ĵ�СΪ��%d\n", size_SeqStack(stack));
	//����ջ
	destory_SeqStack(stack);
}

int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}