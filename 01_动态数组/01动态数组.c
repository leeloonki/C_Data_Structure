#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include"01Dynamic_Array.h"

//测试
struct Person
{
	char name[64];
	int age;
};

//回调
void myprint(void* data)
{
	struct Person* P =data;
	printf("姓名：%s\t年龄：%d\t\n", P->name, P->age);
}

void mycompare(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test01()
{
	//初始化
	Dynamic_Array *arr=init_Dynamic_Array(5);

	//插入数组
	struct Person p1 = { "刘玄德",23 };
	struct Person p2 = { "关羽",19 };
	struct Person p3 = { "张飞",20 };
	struct Person p4 = { "赵云",22 };
	struct Person p5 = { "曹阿满",25 };
	struct Person p6 = { "孙权",21 };

	insert__Dynamic_Array(arr, 0, &p1);
	insert__Dynamic_Array(arr, 1, &p2);
	insert__Dynamic_Array(arr, 1, &p3);
	insert__Dynamic_Array(arr, 0, &p4);
	insert__Dynamic_Array(arr, -1, &p5);
	insert__Dynamic_Array(arr, 0, &p6);

	//遍历
	//孙权 赵云 刘玄德 张飞 关羽 曹阿满 
	printf("初始化结果为：\n\n");
	foreach_Dynamic_Array(arr, myprint);

	//按位删除
	removeByPosDynamic_Array(arr, 3);//删张飞
	printf("\n删除下标为3后：\n");
	foreach_Dynamic_Array(arr, myprint);

	struct Person p = { "刘玄德",23 };
	//测试按值删除
	removeByValue_Dynamic_Array(arr, &p,mycompare);
	printf("\n删除刘玄德后：\n");
	foreach_Dynamic_Array(arr, myprint);

	destory_Dynamic_Array(arr);

	printf("\n数组已销毁\n");
}

int main()
{
	test01();


	system("pause");
	return EXIT_SUCCESS;
}