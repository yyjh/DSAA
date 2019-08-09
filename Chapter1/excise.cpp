// 习题

#include <iostream>
#include <vector>
#include <vcruntime_exception.h>
#include "illegalParameterValue.h"
#include <iterator>
#include <set>
#include "changeLength1D.h"

using namespace std;

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

void test_1_13()
{
	int* a = new int[5];// delete只能删除new出的对象
	
	changeLength1D(a, 5, 3);
}

// 1-20
int Fibonacci(const int& n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
void test1_20()
{
	for (int i = 0; i < 10; ++i)
	{
		int fn = Fibonacci(i);
		cout << fn << '\n';
	}
	
}

// 1-21
int f1_21(const int& n)
{
	if (n % 2 == 0)
	{
		return n / 2;
	}
	else
	{
		return (3 * n + 1) / 2;
	}
}

int f1_21_re(const int& n)
{
	if (n % 2 == 0)
	{
		return n / 2;
	}
	else
	{
		return f1_21_re(n * 3 + 1);
	}
}

void test_f1_21()
{
	cout << f1_21(7) << '\n' << f1_21_re(7) << '\n';
}

// 1-22
int AckermannF(int i, int j)
{
	if (i < 1 || j < 1)
	{
		throw illegalParameterValue("parameter should >= 1");
	}
	if (i == 1)
	{
		return static_cast<int>(pow(2, j));
	}
	else if(i >= 2 && j == 1)
	{
		return AckermannF(i - 1, 2);
	}
	else
	{
		return AckermannF(i - 1, AckermannF(i, j - 1));
	}
}
void test1_22()
{
	try
	{
		cout << AckermannF(2, 2);
	}
	catch (illegalParameterValue e)
	{
		e.outputMessage();
	}	
}

// 1-23
int gcd(int x, int y)
{
	if ( y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}

void test1_23()
{
	cout << gcd(112, 42);
}

// 1-24
template<typename T>
int IsInArray(T a[], int length, T x)
{
	if (length == 0)
	{
		return 0;
	}
	if (x == *a)
	{
		return 1;
	}

	return IsInArray(a, length - 1, x);
}

void test1_24()
{
	char a[5] = { 'q', 'w', 'e', 'r', 't' };
	cout << IsInArray(a, 1, 'q');
}

// 1-25子集生成方法
// 基础部分 subset(0) = {}
// 递归部分 subset(n) = 每个元素 * subset(n - 1) 
//template<typename T>
//void subset(T a[], int length, int k, set<vector<int>> elem)
//{
//
//	for (auto x : elem)
//	{
//		for (auto y : x)
//		{
//			cout << y;
//			cout << endl;
//		}
//	}
//	
//	for (int i = 0; i < length; ++i)
//	{
//		set<vector<int>> elem1;
//		for (int j = 0; j < k; ++j)
//		{
//			elem[i][j] = 1;
//			elem1.insert(elem[j]);
//		}
//		//subset(a, length, k, elem);
//	}
//	
//}
//
//void test_1_25()
//{
//	char a[3] = { 'a', 'b', 'c' };
//	set<vector<int>> elem{ {0, 0, 0} };
//	subset(a, 3, 0, elem);
//}

void test_excise()
{
	//abc(1, 2, 3);

	//Test1_2();
	//Test1_3();
	//Test1_4();
	//Test1_5();
	//test1_10();
	//test1_12();
	//test_1_13();
	//test1_20();
	//test_f1_21();
	//test1_22();
	//test1_23();
	//test1_24();
	//test_1_25();
}
