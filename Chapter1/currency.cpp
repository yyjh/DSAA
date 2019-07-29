#include <iostream>
#include "currency.h"

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw "illegalParameterValue Cents shuould be < 100";

	amount = theDollars * 100 + theCents;
	if (theSign == minus)
	{
		amount = -amount;
	}
}

void currency::setValue(double theAmount)
{
	if (theAmount < 0)
	{
		amount = (long)((theAmount - 0.001) * 100);
	}
	else
	{
		amount = (long)((theAmount + 0.001) * 100);
	}
}

currency currency::operator+(const currency& x) const
{
	currency result;
	result.amount = amount + x.amount;
	return result;
}

void currency::output(std::ostream& out) const
{
	long theAmount = amount;
	if (theAmount < 0)
	{
		out << '-';
		theAmount = -amount;
	}
	long dollars = theAmount / 100;
	out << '$' << dollars << '.';
	int cents = theAmount - dollars * 100;
	if (cents < 10)
	{
		out << '0';
	}
}