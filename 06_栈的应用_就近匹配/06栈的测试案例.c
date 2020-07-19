/*就近匹配，几乎所有编译器都具有检测括号是否匹配的能力，如何实现编译器中的符号成对检测？
5+5*（6）+9/3*1）-（1+3（*/
/*
从第一个字符开始扫描
当遇见普通字符时忽略，
当遇见左括号时压入栈中
当遇见右括号时从栈中弹出栈顶符号，并进行匹配
匹配成功：继续读入下一个字符
匹配失败：立即停止，并报错
结束：
成功: 所有字符扫描完毕，且栈为空
失败：匹配失败或所有字符扫描完毕但栈非空
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


void printError(char* str, char* errInfo, char* pos)//pos为右括号位置
{
	printf("错误信息为:%s\n", errInfo);
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

	//扫描字符串
	char* p = str;

	//准备栈
	SeqStack stack = init_SeqStack();

	while (*p != '\0')
	{
		//如果是左括号则入栈
		if (isLift(*p))
		{
			push_SeqStack(stack, p);
		}

		//如果是右括号则出栈
		if (isRight(*p))
		{
			if (size_SeqStack(stack) > 0)//栈中元素个数大于0出栈
			{
				pop_SeqStack(stack);
			}
			else
			{
				//立即停止 报错
				printError(str, "右括号没有匹配到对应的左括号", p);

				break;
			}
		}
		p++;

	}

	//进到当前循环意味着栈中数据为左括号
	while (size_SeqStack(stack) > 0)
	{
		printf("aaaaaa\n");
		printError(str, "左括号没有匹配到对应的右括号\n", top_SeqStack(stack));//参数三
		//出栈
		pop_SeqStack(stack);
	}
	//销毁栈
	destory_SeqStack(stack);
	stack = NULL;
}

int main()
{

	test01();

	system("pause");
	return EXIT_SUCCESS;
}