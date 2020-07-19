#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
typedef struct Dynamicarray
{
	//堆区开辟数组的指针
	void** addr;

	//数组容量
	int m_Capacity;

	//数组大小
	int m_Size;
}Dynamic_Array;

//初始化动态数组
Dynamic_Array* init_Dynamic_Array(int capacity);

//插入数组
//参数1：动态数组 参数2：插入的位置 参数3：插入的数据
void insert__Dynamic_Array(Dynamic_Array* arr, int pos, void* data);

//遍历数组
void foreach_Dynamic_Array(Dynamic_Array* arr, void(*myprint)(void*));

//按位删除
void removeByPosDynamic_Array(Dynamic_Array* arr, int pos);

//按值删除
void removeByValue_Dynamic_Array(Dynamic_Array* arr, void* data, int (*mycompare)(void*, void*));

//销毁数组
void destory_Dynamic_Array(Dynamic_Array* arr);