//链表的头节点适合做栈顶
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

//节点结构体
struct LinkNode
{
	struct LinkNode* next;
};

//栈的结构体
struct LStack
{
	struct LinkNode header;//头节点
	int m_Size;//栈的大小
};

//用户使用类型
typedef void* LinkStack;

//初始化栈
LinkStack init_LinkStack()
{
	struct LStack *myStack = malloc(sizeof(struct LStack));
	if (myStack == NULL)
	{
		return NULL;
	}

	myStack->header.next = NULL;
	myStack->m_Size = 0;

	return myStack;
}
//入栈
void push_LinkStack(LinkStack stack,void *data)
{
	//本质，链表的头插
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//还原链表真实结构体
	struct LStack* myStack = stack;

	//取出用户传入的前四个字节
	struct LinkNode* newNode = data;

	//更新指针指向
	newNode->next = myStack->header.next;
	myStack->header.next = newNode;

	//更新
	myStack->m_Size++;

}
//出栈
void pop_LinkStack(LinkStack stack)
{
	//本质链表头删
	if (stack == NULL)
	{
		return;
	}
	struct LStack* myStack = stack;
	if (myStack == 0)
	{
		return;
	}

	//记录第一个节点
	struct LinkNode* pFirst = myStack->header.next;
	
	//更新指针指向
	myStack->header.next = pFirst->next;

	//更新链表长度
	myStack->m_Size--;
	
}
//返回栈顶元素
void* top_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct LStack* myStack = stack;
	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->header.next;

}

//返回栈的大小
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	return myStack->m_Size;
}
//判断是否为空
int empty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;
	if (myStack->m_Size == 0)
	{
		return 1;
	}

	return 0;
}
//销毁栈
void destory_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}

//测试
struct Person
{
	void* node;
	char name[64];
	int age;
};
typedef void* SeqStack;

void test01()
{
	//初始化栈
	LinkStack stack = init_LinkStack();
	//入栈
	struct Person p1 = {NULL, "刘玄德",23 };
	struct Person p2 = {NULL, "关羽",19 };
	struct Person p3 = {NULL, "张飞",20 };
	struct Person p4 = {NULL, "赵云",22 };
	struct Person p5 = {NULL, "曹阿满",25 };
	struct Person p6 = {NULL, "孙权",21 };

	push_LinkStack(stack, &p1);
	push_LinkStack(stack, &p2);
	push_LinkStack(stack, &p3);
	push_LinkStack(stack, &p4);
	push_LinkStack(stack, &p5);
	push_LinkStack(stack, &p6);

	//只要栈不为空，查看栈顶元素，并执行出栈
	while (!empty_LinkStack(stack))
	{
		struct Person* pTop = top_LinkStack(stack);
		printf("栈的链式存储 <当前栈顶元素>  姓名：%s，\t年龄：%d\n", pTop->name, pTop->age);

		pop_LinkStack(stack);
	}
	//栈大小
	printf("栈的大小为：%d\n", size_LinkStack(stack));
	//销毁栈
	destory_LinkStack(stack);
}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}