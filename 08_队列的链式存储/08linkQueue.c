#include"08linkQueue.h"

//初始化队列
LinkQueue init_LinkQueue()
{
	struct LQueue *myLQueue= malloc(sizeof(struct LQueue));
	if (myLQueue == NULL)
	{
		return NULL;
	}
	myLQueue->m_Size = 0;
	myLQueue->pHeader.next = NULL;
	myLQueue->pTail = &myLQueue->pHeader;
	return myLQueue;
}

//入队(本质尾插)
void push_LinkQueue(LinkQueue queue, void* data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct LinkNode* myNode = data;//取出data前四个字节

	struct LQueue* myLQueue = queue;

	//插入操作
	myLQueue->pTail->next = myNode;
	
	myNode->next = NULL;

	//更新尾结点指针
	myLQueue->pTail = myNode;

	//更新队列大小
	myLQueue->m_Size++;
}

//出队(本质头删)
void pop_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct LQueue* myQueue = queue;
	if (myQueue->m_Size == 0)
	{
		return;
	}

	if (myQueue->m_Size == 1)//只有一个元素出队后pTail指向头节点
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader;
		myQueue->m_Size = 0;
		return;
	}

	//记录第一个结点
	struct LinkNode* pFirst = myQueue->pHeader.next;

	//更新指针的指向
	myQueue->pHeader.next = pFirst->next;

	//队列大小更新
	myQueue->m_Size--;
}

//返回队头
void* front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pHeader.next;
}

//返回队尾
void* back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pTail;
}
//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;
	return myQueue->m_Size;
}

//判断是否为空
int isEmpty_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;
	if (myQueue->m_Size == 0)
	{
		return 1;
	}

	return 0;
}

//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{

	if (queue != NULL)
	{
		free(queue);
		queue = NULL;
	}
}