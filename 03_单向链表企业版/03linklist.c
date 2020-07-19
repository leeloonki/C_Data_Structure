#include "03linklist.h"
//���ṹ��
struct LinkNode
{
	//ֻά��ָ����
	struct LinkNode* next;
};

//����ṹ��
struct LList
{
	//����ͷ���
	struct LinkNode pHeader;
	//������
	int m_Size;
};

typedef void* LinkList;


//��ʼ������
LinkList init_LinkList()
{
	struct LList* mylist = malloc(sizeof(struct LList));
	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;

	return mylist;
}


//��������
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
	//��ԭ��ʵ�ṹ��
	struct LList* mylist = list;
	//��Чλ��ǿ��β��
	if (pos < 0 || pos >mylist->m_Size)
	{
		pos = mylist->m_Size;
	}

	//���û����� ǿתΪ struct LinkNode * 
	struct LinkNode* myNode = data;//dataǰ�ĸ��ֽڼ�Ϊ�û��ܲ��ݵ�ָ��

	//�ҵ�����λ�õ�ǰ�����
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//��ʱ pCurrent���Ǵ�����λ�õ�ǰ�����

	//���½���ϵ
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;
	//����������
	mylist->m_Size++;
}

//��������
void foreach_LinkList(LinkList list, void(*myPrint)(void*))
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = list;

	struct LinkNode* pCurrent = mylist->pHeader.next; //ָ���һ������ʵ���ݵĽ��
	for (int i = 0; i < mylist->m_Size; i++)
	{
		myPrint(pCurrent);
		pCurrent = pCurrent->next;
	}
}

//��λɾ��
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	if (pos < 0 || pos >  mylist->m_Size - 1)
	{
		return;
	}

	//��������ָ�����
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)//posҪɾ���ڵ���±�
	{
		pCurrent = pCurrent->next;
	}
	//pCurrent���Ǵ�ɾ������ǰ�����

	//��¼��ɾ�����λ��
	struct LinkNode* pDel = pCurrent->next;

	//���½���ϵ
	pCurrent->next = pDel->next;

	//free(pDel); //error  �������û����ٵģ��û�����ά���ͷ�

	//����������
	mylist->m_Size--;
}

//��������
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	list = NULL;
}