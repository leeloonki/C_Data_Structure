#include"07seqQueue.h"
//初始化队列
seqQueue init_seqQueue()
{
	struct Dynamicarray* arr = init_Dynamic_Array(MAX);
	return arr;
}

//入队(本质尾插)
void push_seqQueue(seqQueue queue, void* data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct Dynamicarray* myQueue = queue;

	if (myQueue->m_Size == MAX)
	{
		printf("队列已满，无法继续插入\n");
		return;
	}
	insert__Dynamic_Array(myQueue, myQueue->m_Size, data);
}

//出队(本质头删)
void pop_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct Dynamicarray* myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return;
	}

	removeByPosDynamic_Array(myQueue, 0);
}

//返回队头
void* front_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Dynamicarray* myQueue = queue;

	return myQueue->addr[0];
}

//返回队尾
void* back_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Dynamicarray* myQueue = queue;

	return myQueue->addr[myQueue->m_Size - 1];
}

//队列大小
int size_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct Dynamicarray* myQueue = queue;
	return myQueue->m_Size;
}

//判断队列是否为空
int isEmpty_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct Dynamicarray* myQueue = queue;
	if (myQueue->m_Size == 0)
	{
		return 1;
	}
	return 0;
}

//销毁队列
void destroy_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	struct Dynamicarray* myQueue = queue;

	destory_Dynamic_Array(myQueue);
}