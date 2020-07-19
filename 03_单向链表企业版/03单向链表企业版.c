#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "03linklist.h"

//��������
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
	printf("������%s ����:%d\n", p->name, p->age);
}

void test01()
{
	//��ʼ������
	LinkList list = init_LinkList();

	//׼������
	struct Person p1 = { NULL,"��˼��", 30 };  //alt + shift
	struct Person p2 = { NULL,"����֮", 33 };
	struct Person p3 = { NULL,"˾����", 41 };
	struct Person p4 = { NULL,"ʯ��¶", 22 };
	struct Person p5 = { NULL,"���Ƴ�", 42 };

	//��������
	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, -1, &p4);
	insert_LinkList(list, 1, &p5);

	//��������
	foreach_LinkList(list, printPerson);

	//����ɾ��
	removeByPos_LinkList(list, 3);
	printf("\nɾ�� 3 ��ı������Ϊ\n\n");
	foreach_LinkList(list, printPerson);

	//��������
	destroy_LinkList(list);

	//�ṩ��ֵɾ�������������ȡ��������
}

int main() {
	test01();


	system("pause");
	return EXIT_SUCCESS;
}