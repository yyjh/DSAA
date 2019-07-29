#pragma once
#include <iostream>
#include <vector>
#include <vcruntime_exception.h>

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
		throw "uhi io";

	return a + b * c;
}
void test1_10()
{
	float* x;
	try
	{
		std::cout << ex(1, 1, 2);
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

}

// 1.12
template<typename T>
bool make2dArray(T** &x, int numberOfRows, int rowSize[])
{
	//������ָ��
	x = new T*[numberOfRows];
	//Ϊÿһ�з���ռ�
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
void changeLength1D(T a[], int oldLength, T b[], int newLength)
{
	b = new T[newLength];
	int length = newLength < oldLength ? newLength : oldLength;
	for (int i = 0; i < length; ++i)
	{
		a[i] = b[i];
	}

}
void test_1_13()
{
	int a[5] = { 1, 1, 1, 1, 1 };
	int b[3] = { 2, 2, 2 };
	changeLength1D(a, 5, b, 3);
}

void test_excise()
{
	abc(1, 2, 3);

	Test1_2();
	Test1_3();
	Test1_4();
	Test1_5();
	//test1_12();
	test_1_13();
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ��������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б����ڲ鿴����
//   5. ת������Ŀ��>����������Դ����µĴ����ļ�����ת������Ŀ��>������������Խ����д����ļ����ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�