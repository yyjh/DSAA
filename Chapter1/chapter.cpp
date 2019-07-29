#include <iostream>
#include "currency.h"

// ����1-10 Ϊ��ά�������ռ�
template<typename T>
bool make2dArray(T** &x, int numberOfRows, int numberOfColumns)
{
	try {
		//������ָ��
		x = new T*[numberOfRows];
		//Ϊÿһ�з���ռ�
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
// ����1-12 �ͷŶ�ά����ռ�
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
	currency g, h(plus, 1, 1), i, j;
	g.setValue(plus, 1, 1);
	i.setValue(-1.01);

	j = h + g;
	std::cout << h << " + " << g << "=" << j << std::endl;

	j = (i += g) + h;


	try
	{
		i.setValue(plus, 3, 152);
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}

	return;
}

void test_chapter()
{
	int row = 0;
	int col = 0;
	std::cout << "Input:" << '\n';
	std::cin >> row >> col;
	int** x;
	make2dArray(x, row, col);
	delete2dArray(x, row);

	test_currency();
}