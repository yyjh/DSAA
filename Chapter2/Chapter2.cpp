// Chapter2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>

using namespace std;

// 程序2-7 选择排序
template<typename T>
int indexMax(T a[], int nSize)
{
	T temp = 0;
	int nMax = 0;
	for (int i = nSize - 1; i >= 0; --i)
	{
		if (a[i] > temp)
		{
			temp = a[i];
			nMax = i;
		}
	}
	return nMax;
}
template<class T>
void selectionSort(T a[], int n)
{
	for (int i = n; i > 0; --i)
	{
		int nMax = indexMax(a, i);
		swap(a[i - 1], a[nMax]);
	}
}
void test_selectionSort()
{
	int a[5] = { 5, 2, 6, 3, 7 };
	selectionSort(a, 5);
	for (int i = 0; i < 5; ++i)
	{
		cout << a[i] << '\n';
	}
}

// 2-9冒泡排序
template<typename T>
void Bubble(T a[], int n)
{
	for (int i = n; i > 0; --i)
	{
		for (int j = 0; j < i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void test_bubble()
{
	int a[5] = { 5, 2, 6, 3, 7 };
	Bubble(a, 5);
	for (int i = 0; i < 5; ++i)
	{
		cout << a[i] << '\n';
	}
}

void test_chapter()
{
	//test_selectionSort();
	test_bubble();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
