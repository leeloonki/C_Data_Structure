
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include"07seqQueue.h"

struct Person
{
	char name[64];
	int age;
};
void test01()
{
	//��ʼ������
	seqQueue  queue = init_seqQueue();

	struct Person p1 = { "������",23 };
	struct Person p2 = { "����",19 };
	struct Person p3 = { "�ŷ�",20 };
	struct Person p4 = { "�ܰ���",22};
	struct Person p5 = { "��Ȩ",21 };

	//���
	push_seqQueue(queue, &p1);
	push_seqQueue(queue, &p2);
	push_seqQueue(queue, &p3);
	push_seqQueue(queue, &p4);
	push_seqQueue(queue, &p5);

	printf("���д�СΪ:%d\n", size_seqQueue(queue)); 

	//������в�Ϊ�գ��鿴��ͷ���鿴��β������
	while (!isEmpty_seqQueue(queue))
	{
		struct Person* pFront = front_seqQueue(queue);
		printf("<��ͷԪ��>----������%s ���䣺%d\n", pFront->name, pFront->age);

		struct Person* pBack = back_seqQueue(queue);
		printf("<��βԪ��>----������%s ���䣺%d\n", pBack->name, pBack->age);

		pop_seqQueue(queue);
	}

	printf("���д�СΪ:%d\n", size_seqQueue(queue)); // 0

	//���ٶ���
	destroy_seqQueue(queue);

}

int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
