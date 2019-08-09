#include "arrayList.h"

void test_Chapter5()
{
	arrayList<int> y;
	y.insert(0, 5);
	y.insert(1, 6);
	arrayList<int>::iterator iterBegin = y.begin();
	arrayList<int>::iterator iterEnd = y.end();
	for (; iterBegin != iterEnd; ++iterBegin)
	{
		cout << *iterBegin << '\n';
	}
}