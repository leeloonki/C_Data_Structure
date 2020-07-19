#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//链表结点设计
struct LinkNode
{
	void* data;//数据域
	struct LinkNode* next;//指针域
};

//链表结构体
struct LList
{
	struct LinkNode pHeader;//链表头节点
	int m_Size;//链表长度
};

//给用户用的数据类型
typedef void* LinkList;//用户无法获取LList属性，防止恶意篡改

//初始化链表
LinkList init_LinkList()
{
	struct LList *myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	//分配成功初始化链表属性
	myList->pHeader.data = NULL;//链表头节点不维护
	myList->pHeader.next = NULL;
	myList->m_Size = 0;

	return myList;
}

//插入节点
void insert_LinkList(LinkList list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList* myList = list;//参数List传进来是void* 需转化为struct LList类型
	if (pos<0 || pos>myList->m_Size)
	{
		//无效位置强制尾插
		pos = myList->m_Size;
	}

	//插入数据
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//此时pTemp是待插入结点的前驱节点位置
	
	//创建新节点
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;
	
	//插入新节点
	
	//更改指针指向
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;
	//更新链表长度
	myList->m_Size++;
}

//遍历链表
void foreach_LinkList(LinkList List,void(*myprint)(void *))
{
	if (List == NULL)
	{
		return;
	}

	struct LList* myList = List;

	//辅助临时指针指向第一个有真实数据的节点
	struct LinkNode* pCurrent = myList->pHeader.next;

	for (int i = 0; i < myList->m_Size; i++)
	{
		//pTemp->data;data是void*类型，需要使用回调函数
		myprint(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}

//按位删除节点
void removeByPos_LinkList(LinkList list, int pos)
{
	
	if (list == NULL)//if();后面多写了个；找了俩小时bug
	{
		return;
	}
	//无效位置直接return

	struct LList* myList = list;
	if (pos<0 || pos>myList->m_Size - 1)
	{
		return;
	}
	//辅助指针
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//此时 pCurrent就是待删除节点的前驱节点位置
	struct LinkNode* Pdel = pCurrent->next;
	pCurrent->next = Pdel->next;
	//释放待删除结点
	free(Pdel);
	Pdel = NULL;
	//更新链表长度
	myList->m_Size--;
}

//按值删除,参数三：回调函数判断要删除的节点与链表中的节点比较是否相同
void removeByValue_LinkList(LinkList list, void* data, int(*mycompare)(void*, void*))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList* mylist = list;

	//创建辅助指针变量
	struct LinkNode* prew = &mylist->pHeader;
	struct LinkNode* pcurrent = prew->next;//此时pcurrent指向第一个有数据的节点

	//利用两辅助指针找用户要删除的节点
	for (int i = 0; i < mylist->m_Size; i++)
	{
		if (mycompare(pcurrent->data, data))
		{
			prew->next = pcurrent->next;
			free(pcurrent);
			pcurrent = NULL;
			mylist->m_Size--;
			break;
		}
		//没找到要删除的值,辅助指针后裔
		prew = pcurrent;
		pcurrent = pcurrent->next;
	}
}

//清空链表
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = list;

	struct LinkNode* pCurent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_Size; i++)
	{
		//删除当前节点前先记录下一个节点位置
		struct LinkNode* pNext = pCurent->next;
		free(pCurent);
		pCurent = pNext;
	}

	//释放头节点
	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;
}

//获取链表长度
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList* mylist = list;

	return mylist->m_Size;
}

//销毁链表
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	//先清空
	clear_LinkList(list);
	//再释放链表结构体
	free(list);
	list = NULL;
}

//测试

struct Person
{
	char name[64];
	int age;
};

//回调函数
void myprint(void* data)
{
	struct Person*p = data;
	printf("姓名：%s\t年龄：%d\t\n", p->name, p->age);
}

//回调函数2
int mycompare2(void* data1,void*data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;
	
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}
void test01()
{
	//初始化链表
	LinkList list = init_LinkList();

	//插入链表
	struct Person p1 = { "刘备",23 };
	struct Person p2 = { "关羽",19 };
	struct Person p3 = { "张飞",20 };
	struct Person p4 = { "赵云",22 };
	struct Person p5 = { "曹操",25 };
	struct Person p6 = { "孙权",21 };
	
	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, -1, &p3);
	insert_LinkList(list, 1, &p4);
	insert_LinkList(list, 100, &p5);
	insert_LinkList(list, 2, &p6);


	//遍历链表
	//预测结果：关羽 赵云 孙权 刘备 张飞 曹操
	printf("插入数据后\n");
	foreach_LinkList(list, myprint);

	//按位删除 1号赵云
	removeByPos_LinkList(list,1);
	printf("\n删除1号位置后:\n");
	foreach_LinkList(list, myprint);
	
	//按值删除 张飞
	removeByValue_LinkList(list, &p3,mycompare2);
	printf("\n删除张飞后:\n");
	foreach_LinkList(list, myprint);

	//获取链表长度
	int size = size_LinkList(list);
	printf("\n链表长度为:%d\n",size);

	//清空链表后
	clear_LinkList(list);
	size = size_LinkList(list);
	printf("\n清空链表后链表长度为:%d\n", size);
	printf("遍历结果为:\n");
	foreach_LinkList(list, myprint);

	//销毁
	destroy_LinkList(list);
}

int main()
{
	test01();
	
	system("pause");
	return EXIT_SUCCESS;
}