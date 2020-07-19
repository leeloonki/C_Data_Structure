/*�ͽ�ƥ�䣬�������б����������м�������Ƿ�ƥ������������ʵ�ֱ������еķ��ųɶԼ�⣿
5+5*��6��+9/3*1��-��1+3��*/
/*
�ӵ�һ���ַ���ʼɨ��
��������ͨ�ַ�ʱ���ԣ�
������������ʱѹ��ջ��
������������ʱ��ջ�е���ջ�����ţ�������ƥ��
ƥ��ɹ�������������һ���ַ�
ƥ��ʧ�ܣ�����ֹͣ��������
������
�ɹ�: �����ַ�ɨ����ϣ���ջΪ��
ʧ�ܣ�ƥ��ʧ�ܻ������ַ�ɨ����ϵ�ջ�ǿ�
*/
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

#include"04seqstack.h"

int isLift(char ch)
{
	return ch == '(';
}
int isRight(char ch)
{
	return ch == ')';
}


void printError(char* str, char* errInfo, char* pos)//posΪ������λ��
{
	printf("������ϢΪ:%s\n", errInfo);
	printf("%s\n", str);

	int num = pos - str;
	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("| \n");
}

void test01()
{
	//char* str = "5+5*(6)+9/3*1)-(1+3(";
	char* str = "5+5*(6)+9/3*1-(1+3(";

	//ɨ���ַ���
	char* p = str;

	//׼��ջ
	SeqStack stack = init_SeqStack();

	while (*p != '\0')
	{
		//���������������ջ
		if (isLift(*p))
		{
			push_SeqStack(stack, p);
		}

		//��������������ջ
		if (isRight(*p))
		{
			if (size_SeqStack(stack) > 0)//ջ��Ԫ�ظ�������0��ջ
			{
				pop_SeqStack(stack);
			}
			else
			{
				//����ֹͣ ����
				printError(str, "������û��ƥ�䵽��Ӧ��������", p);

				break;
			}
		}
		p++;

	}

	//������ǰѭ����ζ��ջ������Ϊ������
	while (size_SeqStack(stack) > 0)
	{
		printf("aaaaaa\n");
		printError(str, "������û��ƥ�䵽��Ӧ��������\n", top_SeqStack(stack));//������
		//��ջ
		pop_SeqStack(stack);
	}
	//����ջ
	destory_SeqStack(stack);
	stack = NULL;
}

int main()
{

	test01();

	system("pause");
	return EXIT_SUCCESS;
}