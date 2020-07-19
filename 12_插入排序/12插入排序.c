#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//插入排序
void insert_Sort(int arr[], int len)
{
	//从下标为一开始
	for (int i = 1; i < len; i++)
	{	
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];//暂存较小值

			//利用内层循环j 向后移动数据
			int j = i - 1;
			for (; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}

			//将j+1位置 赋值 temp
			arr[j + 1] = temp;
		}
	}
}


void test01()
{
	int arr[] = { 5, 3, 2, 1,4 };
	int len = sizeof(arr) / sizeof(int);
	insert_Sort(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}