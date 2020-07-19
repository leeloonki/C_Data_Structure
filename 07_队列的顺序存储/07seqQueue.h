#pragma once

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
//只能访问队列头尾元素
//队列的底层可以用动态数组封装
//此程序将链表尾做队列的头部
#include"01Dynamic_Array.h"

#define MAX 1024//设置队列大小

typedef void* seqQueue;

//初始化队列
seqQueue init_seqQueue();

//入队
void push_seqQueue(seqQueue queue, void* data);

//出队
void pop_seqQueue(seqQueue queue);

//返回队头
void* front_seqQueue(seqQueue queue);

//返回队尾
void* back_seqQueue(seqQueue queue);

//队列大小
int size_seqQueue(seqQueue queue);

//判断队列是否为空
int isEmpty_seqQueue(seqQueue queue);

//销毁队列
void destroy_seqQueue(seqQueue queue);