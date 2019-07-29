#pragma once
#include <iostream>
#include <vector>
#include <vcruntime_exception.h>
#include "illegalParameterValue.h"

template<typename T>
T abc(T a, T b, T c)
{
	return a + b * c;
}

// excise
// 1.2
template<typename T>
int count(T a[], int n, T value)
{
	int nCount = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == value)
		{
			++nCount;
		}
	}

	return nCount;
}
void Test1_2()
{
	int a[5] = { 1, 2, 4, 2, 1 };
	int nCount = count(a, 5, 2);
}

// 1.3
template<typename T>
void fill(T a[], int n, T value)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = value;
	}
}
void Test1_3()
{
	int a[5];
	fill(a, 5, 6);
}

// 1.4
template<typename T>
T inner_product(T a[], T b[], int n)
{
	T result = 0;
	for (int i = 0; i < n; ++i)
	{
		result += a[i] * b[i];
	}

	return result;
}
void Test1_4()
{
	int a[] = { 1, 2, 3 };
	int b[] = { 3, 2, 1 };
	int r = inner_product(a, b, 3);
}

// 1.5
template<typename T>
void iota(T a[], int n, T value)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] += value;
	}
}
void Test1_5()
{
	int a[5]{ 5 };
	iota(a, 5, 6);
}

// 1.10
int ex(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		throw illegalParameterValue("uhi io");

	return a + b * c;
}
void test1_10()
{
	float* x;
	try
	{
		std::cout << ex(0, 1, 2);
		x = new float[99999999];
		delete[]x;
	}
	catch (const char* e)
	{
		std::cout << e;
		return;
	}
	catch (int e)
	{
		std::cout << e;
		return;
	}
	catch (std::bad_alloc e)
	{
		std::cerr << "out of memory" << std::endl;
		exit(1);
	}
	catch (illegalParameterValue e)
	{
		e.outputMessage();
		return;
	}

}

// 1.12
template<typename T>
bool make2dArray(T** &x, int numberOfRows, int rowSize[])
{
	//创建行指针
	x = new T*[numberOfRows];
	//为每一行分配空间
	for (int i = 0; i < numberOfRows; ++i)
	{
		int col = rowSize[i];
		x[i] = new int[col];
	}
	return true;
}
void test1_12()
{
	int row = 0;
	std::cout << "Input row:" << '\n';
	std::cin >> row;
	int** x;
	int rowSize[5] = { 1, 2, 3, 4, 5 };

	try {
		make2dArray(x, row, rowSize);
	}
	catch (std::bad_alloc)
	{
		return;
	}
}

// 1.13
template<typename T>
void changeLength1D(T* &a, int oldLength, int newLength)
{
	if (newLength < 0)
	{
		return;
	}
	T* b = new T[newLength];
	int length = oldLength < newLength ? oldLength : newLength;
	for (int i = 0; i < length; ++i)
	{
		b[i] = a[i];
	}
	delete [] a;
	a = b;
}
void test_1_13()
{
	int* a = new int[5];// delete只能删除new出的对象
	
	changeLength1D(a, 5, 3);
}

void test_excise()
{
	//abc(1, 2, 3);

	//Test1_2();
	//Test1_3();
	//Test1_4();
	//Test1_5();
	test1_10();
	//test1_12();
	//test_1_13();
}
