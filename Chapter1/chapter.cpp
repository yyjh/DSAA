// 书籍示例代码

#include <iostream>
#include "currency.h"
#include <iterator>
using namespace std;

// 程序1-10 为二维数组分配空间
template<typename T>
bool make2dArray(T** &x, int numberOfRows, int numberOfColumns)
{
	try {
		//创建行指针
		x = new T*[numberOfRows];
		//为每一行分配空间
		for (int i = 0; i < numberOfRows; ++i)
		{
			x[i] = new int[numberOfColumns];
		}
		return true;
	}
	catch (std::bad_alloc)
	{
		return false;
	}
}
// 程序1-12 释放二维数组空间
template<typename T>
void delete2dArray(T** &x, int numberOfRows)
{
	for (int i = 0; i < numberOfRows; ++i)
	{
		delete[] x[i];
	}

	delete[] x;
	x = nullptr;
}

// test 1-18
std::ostream& operator<<(std::ostream& out, const currency& x)
{
	x.output(out);
	return out;
}

void test_currency()
{
	currency g, h(signType::plus, 1, 1), i, j;
	g.setValue(signType::plus, 1, 1);
	i.setValue(-1.01);

	j = h + g;
	std::cout << h << " + " << g << "=" << j << std::endl;

	j = (i += g) + h;


	try
	{
		i.setValue(signType::plus, 3, 152);
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}

	return;
}

// 程序1-32
template< typename T>
void permutation(T list[], int k, int m)
{
	if (k == m)
	{
		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
		cout << endl;
	}
	else
	{
		for (int i = k; i <= m; ++i)
		{
			swap(list[k], list[i]);
			permutation(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}
void test_permutations()
{
	char a[4] = { 'a', 'b', 'c', 'd' };
	permutation(a, 0, 3);
}

void test_chapter()
{
	/*int row = 0;
	int col = 0;
	std::cout << "Input:" << '\n';
	std::cin >> row >> col;
	int** x;
	make2dArray(x, row, col);
	delete2dArray(x, row);*/

	//test_currency();

	test_permutations();
}