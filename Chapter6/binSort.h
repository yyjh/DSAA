#pragma once
#include <string>
#include "chain.h"
using namespace std;

struct studentRecord
{
	int score;
	string* name;

	int operator!=(const studentRecord& x) const
	{
		return (score != x.score);
	}
	operator int() const { return score; }
};

void binSort(chain<studentRecord>& theChain, int range)
{
	// 箱子
	chain<studentRecord> *bin;
	bin = new chain<studentRecord>[range + 1];

	// 数据分配到箱子
	int numberOfElement = theChain.size();
	for (int i = 1; i <= numberOfElement; ++i)
	{
		studentRecord x = theChain.get(0);
		theChain.erase(0);
		bin[x.score].insert(0, x);
	}
	for (int j = range; j >= 0; --j)
	{
		while (!bin[j].empty())
		{
			studentRecord x = bin[j].get(0);
			bin[j].erase(0);
			theChain.insert(0, x);
		}
	}
	delete[] bin;
}
