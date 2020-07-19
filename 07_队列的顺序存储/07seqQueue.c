#include"07seqQueue.h"
//��ʼ������
seqQueue init_seqQueue()
{
	struct Dynamicarray* arr = init_Dynamic_Array(MAX);
	return arr;
}

//���(����β��)
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
		printf("�����������޷���������\n");
		return;
	}
	insert__Dynamic_Array(myQueue, myQueue->m_Size, data);
}

//����(����ͷɾ)
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

//���ض�ͷ
void* front_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Dynamicarray* myQueue = queue;

	return myQueue->addr[0];
}

//���ض�β
void* back_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Dynamicarray* myQueue = queue;

	return myQueue->addr[myQueue->m_Size - 1];
}

//���д�С
int size_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct Dynamicarray* myQueue = queue;
	return myQueue->m_Size;
}

//�ж϶����Ƿ�Ϊ��
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

//���ٶ���
void destroy_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	struct Dynamicarray* myQueue = queue;

	destory_Dynamic_Array(myQueue);
}