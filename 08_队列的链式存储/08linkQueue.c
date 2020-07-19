#include"08linkQueue.h"

//��ʼ������
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

//���(����β��)
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
	struct LinkNode* myNode = data;//ȡ��dataǰ�ĸ��ֽ�

	struct LQueue* myLQueue = queue;

	//�������
	myLQueue->pTail->next = myNode;
	
	myNode->next = NULL;

	//����β���ָ��
	myLQueue->pTail = myNode;

	//���¶��д�С
	myLQueue->m_Size++;
}

//����(����ͷɾ)
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

	if (myQueue->m_Size == 1)//ֻ��һ��Ԫ�س��Ӻ�pTailָ��ͷ�ڵ�
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader;
		myQueue->m_Size = 0;
		return;
	}

	//��¼��һ�����
	struct LinkNode* pFirst = myQueue->pHeader.next;

	//����ָ���ָ��
	myQueue->pHeader.next = pFirst->next;

	//���д�С����
	myQueue->m_Size--;
}

//���ض�ͷ
void* front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pHeader.next;
}

//���ض�β
void* back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pTail;
}
//���ض��д�С
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;
	return myQueue->m_Size;
}

//�ж��Ƿ�Ϊ��
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

//���ٶ���
void destroy_LinkQueue(LinkQueue queue)
{

	if (queue != NULL)
	{
		free(queue);
		queue = NULL;
	}
}