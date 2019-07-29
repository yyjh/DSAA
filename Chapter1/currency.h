#pragma once
#include <ostream>

// 程序1-13
enum signType
{
	plus,
	minus
};

class currency
{
public:
	currency(signType theSign = signType::plus,
		unsigned long theDollars = 0,
		unsigned int theCents = 0);
	~currency() {};

	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const { if (amount < 0) return signType::minus; else return signType::plus; };	// 常量函数不改变调用对象的值
	unsigned long getDollars() const { if (amount < 0) return (-amount) / 100; else return amount / 100; }
	unsigned int getCents() const { if (amount < 0) return -amount - getDollars() * 100; else return amount - getDollars() * 100; }
	currency operator+(const currency&) const;
	currency& operator+=(const currency& x)
	{amount += x.amount; return *this;}
	void output(std::ostream&) const;

private:
	long amount;

};