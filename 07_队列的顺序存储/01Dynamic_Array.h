#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
typedef struct Dynamicarray
{
	//�������������ָ��
	void** addr;

	//��������
	int m_Capacity;

	//�����С
	int m_Size;
}Dynamic_Array;

//��ʼ����̬����
Dynamic_Array* init_Dynamic_Array(int capacity);

//��������
//����1����̬���� ����2�������λ�� ����3�����������
void insert__Dynamic_Array(Dynamic_Array* arr, int pos, void* data);

//��������
void foreach_Dynamic_Array(Dynamic_Array* arr, void(*myprint)(void*));

//��λɾ��
void removeByPosDynamic_Array(Dynamic_Array* arr, int pos);

//��ֵɾ��
void removeByValue_Dynamic_Array(Dynamic_Array* arr, void* data, int (*mycompare)(void*, void*));

//��������
void destory_Dynamic_Array(Dynamic_Array* arr);