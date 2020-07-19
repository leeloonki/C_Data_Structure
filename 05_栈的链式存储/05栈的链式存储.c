//�����ͷ�ڵ��ʺ���ջ��
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

//�ڵ�ṹ��
struct LinkNode
{
	struct LinkNode* next;
};

//ջ�Ľṹ��
struct LStack
{
	struct LinkNode header;//ͷ�ڵ�
	int m_Size;//ջ�Ĵ�С
};

//�û�ʹ������
typedef void* LinkStack;

//��ʼ��ջ
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
//��ջ
void push_LinkStack(LinkStack stack,void *data)
{
	//���ʣ������ͷ��
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//��ԭ������ʵ�ṹ��
	struct LStack* myStack = stack;

	//ȡ���û������ǰ�ĸ��ֽ�
	struct LinkNode* newNode = data;

	//����ָ��ָ��
	newNode->next = myStack->header.next;
	myStack->header.next = newNode;

	//����
	myStack->m_Size++;

}
//��ջ
void pop_LinkStack(LinkStack stack)
{
	//��������ͷɾ
	if (stack == NULL)
	{
		return;
	}
	struct LStack* myStack = stack;
	if (myStack == 0)
	{
		return;
	}

	//��¼��һ���ڵ�
	struct LinkNode* pFirst = myStack->header.next;
	
	//����ָ��ָ��
	myStack->header.next = pFirst->next;

	//����������
	myStack->m_Size--;
	
}
//����ջ��Ԫ��
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

//����ջ�Ĵ�С
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	return myStack->m_Size;
}
//�ж��Ƿ�Ϊ��
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
//����ջ
void destory_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}

//����
struct Person
{
	void* node;
	char name[64];
	int age;
};
typedef void* SeqStack;

void test01()
{
	//��ʼ��ջ
	LinkStack stack = init_LinkStack();
	//��ջ
	struct Person p1 = {NULL, "������",23 };
	struct Person p2 = {NULL, "����",19 };
	struct Person p3 = {NULL, "�ŷ�",20 };
	struct Person p4 = {NULL, "����",22 };
	struct Person p5 = {NULL, "�ܰ���",25 };
	struct Person p6 = {NULL, "��Ȩ",21 };

	push_LinkStack(stack, &p1);
	push_LinkStack(stack, &p2);
	push_LinkStack(stack, &p3);
	push_LinkStack(stack, &p4);
	push_LinkStack(stack, &p5);
	push_LinkStack(stack, &p6);

	//ֻҪջ��Ϊ�գ��鿴ջ��Ԫ�أ���ִ�г�ջ
	while (!empty_LinkStack(stack))
	{
		struct Person* pTop = top_LinkStack(stack);
		printf("ջ����ʽ�洢 <��ǰջ��Ԫ��>  ������%s��\t���䣺%d\n", pTop->name, pTop->age);

		pop_LinkStack(stack);
	}
	//ջ��С
	printf("ջ�Ĵ�СΪ��%d\n", size_LinkStack(stack));
	//����ջ
	destory_LinkStack(stack);
}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}