#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include"04seqstack.h"
//#define MAX 1024

//测试
struct Person
{
	char name[64];
	int age;
};
typedef void* SeqStack;

void test01()
{
	//初始化栈
	SeqStack stack = init_SeqStack();
	//入栈
	struct Person p1 = {"刘玄德",23 };
	struct Person p2 = {"关羽",19 };
	struct Person p3 = {"张飞",20 };
	struct Person p4 = {"赵云",22 };
	struct Person p5 = {"曹阿满",25 };
	struct Person p6 = {"孙权",21 };

	push_SeqStack(stack, &p1);
	push_SeqStack(stack, &p2);
	push_SeqStack(stack, &p3);
	push_SeqStack(stack, &p4);
	push_SeqStack(stack, &p5);
	push_SeqStack(stack, &p6);

	//只要栈不为空，查看栈顶元素，并执行出栈
	while (!empty_SeqStack(stack))
	{
		struct Person* pTop = top_SeqStack(stack);
		printf("<当前栈顶元素>  姓名：%s，\t年龄：%d\n", pTop->name, pTop->age);

		pop_SeqStack(stack);
	}
	//栈大小
	printf("栈的大小为：%d\n", size_SeqStack(stack));
	//销毁栈
	destory_SeqStack(stack);
}

int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}