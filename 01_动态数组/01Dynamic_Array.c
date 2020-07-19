#include"01Dynamic_Array.h"
Dynamic_Array* init_Dynamic_Array(int capacity)
{
	//判断数据有效性
	if (capacity <= 0)
	{
		return NULL;
	}

	//给数组分配内存
	Dynamic_Array* arr = malloc(sizeof(Dynamic_Array));

	if (arr == NULL)
	{
		printf("内存分配失败\n");
		return NULL;//内存分配失败返回空
	}

	//初始化数组中的属性
	arr->m_Capacity = capacity;
	arr->m_Size = 0;
	arr->addr = malloc(sizeof(void*) * capacity);//设置初始指针指向堆区数组
	return arr;
}

//插入数组
//参数1：动态数组 参数2：插入的位置 参数3：插入的数据
void insert__Dynamic_Array(Dynamic_Array* arr, int pos, void* data)
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos<0 || pos>arr->m_Size)//插入元素时不能超过当前元素个数（下标）
	{
		//无效位置强制尾插
		pos = arr->m_Size;
	}

	//插入前先判断是否已经满，如果满了，动态扩展
	if (arr->m_Capacity == arr->m_Size)
	{
		//计算申请的空间
		int newCapacity = arr->m_Capacity * 2;
		//创建新空间
		void** newSpace = malloc(sizeof(void*) * newCapacity);
		//将原空间内容拷贝新空间
		memcpy(newSpace, arr->addr, sizeof(void*) * arr->m_Capacity);
		//释放原空间
		free(arr->addr);
		//更新新空间指向
		arr->addr = newSpace;
		//更新容量
		arr->m_Capacity = newCapacity;
		newSpace = NULL;//临时指针可以置空了
	}

	//插入数据
	//插入时，最后一个元素开始依次向后移动
	//arr->m_Size - 1数组中最后一个元素的下标 pos也为数组下标
	for (int i = arr->m_Size - 1; i >= pos; i--)
	{
		arr->addr[i + 1] = arr->addr[i];//
	}

	arr->addr[pos] = data;

	//更新数组大小
	arr->m_Size++;
}


//遍历数组
void foreach_Dynamic_Array(Dynamic_Array* arr, void(*myprint)(void*))
{
	if (arr == NULL)
	{
		return;
	}
	if (myprint == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_Size; i++)
	{
		myprint(arr->addr[i]);//回调函数
	}
}

//按位删除
void removeByPosDynamic_Array(Dynamic_Array* arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (pos<0 || pos>arr->m_Size - 1)
	{
		return;
	}

	for (int i = pos; i < arr->m_Size - 1; i++)
	{
		arr->addr[i] = arr->addr[i + 1];
	}
	arr->m_Size--;

}

//按值删除
void removeByValue_Dynamic_Array(Dynamic_Array* arr, void* data, int (*mycompare)(void*, void*))
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_Size; i++)
	{
		if (mycompare(arr->addr[i], data))
		{
			removeByPosDynamic_Array(arr, i);
			break;
		}
	}
}


//销毁数组
void destory_Dynamic_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return;
	}

	//for (int i = 0; i < arr->m_Size; i++)
	//{
	//	free(arr->addr[i]);
	//	arr->addr[i] == NULL;
	//}

	//先释放堆区数组，再释放结构体
	if (arr->addr != NULL)
	{
		free(arr->addr);
		arr->addr = NULL;
	}

	free(arr);
	arr = NULL;
}