// Chapter1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// 程序1-13
enum signType 
{
	plus,
	minus
};

class currency
{
public:
	currency(signType theSign = plus,
			unsigned long theDollars = 0,
			unsigned int theCents = 0);
	~currency() {};

	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const { return sign; };	// 常量函数不改变调用对象的值
	unsigned long getDollars() const { return dollars; }
	unsigned long getCents() const { return cents; }
	currency add(const currency&) const;
	currency& increment(const currency&);
	void output() const;

private:
	signType sign;				// 对象符号
	unsigned long dollars;		// 美元数量
	unsigned int cents;			// 美分数量

};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw "illegalParameterValue Cents shuould be < 100";

	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}

void currency::setValue(double theAmount)
{
	if (theAmount < 0)
	{
		sign = minus;
		theAmount = -theAmount;
	}
	else
	{
		sign = plus;
	}
	dollars = (unsigned long)theAmount;
	cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}
int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
 
