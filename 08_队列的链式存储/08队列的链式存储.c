
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

#include"08linkQueue.h"

struct Person
{
	void* node;
	char name[64];
	int age;
};
void test01()
{
	//初始化队列
	LinkQueue queue = init_LinkQueue();

	struct Person p1 = { NULL, "庞统", 40 };
	struct Person p2 = { NULL, "诸葛亮", 33 };
	struct Person p3 = { NULL, "司马懿", 30 };
	struct Person p4 = { NULL, "鲁肃", 35 };
	struct Person p5 = { NULL, "周公瑾", 23 };
	
	//入队
	push_LinkQueue(queue, &p1);
	push_LinkQueue(queue, &p2);
	push_LinkQueue(queue, &p3);
	push_LinkQueue(queue, &p4);
	push_LinkQueue(queue, &p5);
	
	printf("队列大小为:%d\n", size_LinkQueue(queue));

	//如果队列不为空，查看队头，查看队尾，出队
	while (!isEmpty_LinkQueue(queue))
	{
		struct Person* pFront = front_LinkQueue(queue);
		printf("队头元素---姓名：%s 年龄：%d\n", pFront->name, pFront->age);

		struct Person* pBack = back_LinkQueue(queue);
		printf("队尾元素---姓名：%s 年龄：%d\n", pBack->name, pBack->age);

		pop_LinkQueue(queue);
	}

	printf("队列大小为:%d\n", size_LinkQueue(queue));

	//销毁队列
	destroy_LinkQueue(queue);
}

int main()
{

	test01();
	
	system("pause");
	return EXIT_SUCCESS;
}
