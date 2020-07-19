#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "03linklist.h"

//测试链表
struct Person
{
	//struct LinkNode node;
	void* node;
	char name[64];
	int age;
};

void printPerson(void* data)
{
	struct Person* p = data;
	printf("姓名：%s 年龄:%d\n", p->name, p->age);
}

void test01()
{
	//初始化链表
	LinkList list = init_LinkList();

	//准备数据
	struct Person p1 = { NULL,"傅思归", 30 };  //alt + shift
	struct Person p2 = { NULL,"过彦之", 33 };
	struct Person p3 = { NULL,"司空玄", 41 };
	struct Person p4 = { NULL,"石清露", 22 };
	struct Person p5 = { NULL,"古笃诚", 42 };

	//插入链表
	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, -1, &p4);
	insert_LinkList(list, 1, &p5);

	//遍历链表
	foreach_LinkList(list, printPerson);

	//测试删除
	removeByPos_LinkList(list, 3);
	printf("\n删除 3 后的遍历结果为\n\n");
	foreach_LinkList(list, printPerson);

	//销毁链表
	destroy_LinkList(list);

	//提供按值删除、返回链表长度、清空链表
}

int main() {
	test01();


	system("pause");
	return EXIT_SUCCESS;
}