#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


////���ṹ��
//struct LinkNode
//{
//	//ֻά��ָ����
//	struct LinkNode * next;
//};
//
////����ṹ��
//struct LList
//{
//	//����ͷ���
//	struct LinkNode pHeader;
//	//������
//	int m_Size;
//};
//���صĲ��ַŵ�.c�ļ��У���.c�ļ���װ�ɿ��ļ����û�ֻ�ܸ���.hʹ�ã����޷������޸�

typedef void* LinkList;


//��ʼ������
LinkList init_LinkList();

//��������
void insert_LinkList(LinkList list, int pos, void* data);

//��������
void foreach_LinkList(LinkList list, void(*myPrint)(void*));

//ɾ������
void removeByPos_LinkList(LinkList list, int pos);

//��������
void destroy_LinkList(LinkList list);
