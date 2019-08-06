#include <iostream>
#include <iosfwd>
#include "arrayList.h"

template<typename T>
arrayList<T>::arrayList(int initalCapacity)
{
	if (initalCapacity < 1)
	{
		ostringstream s;
		s << "capacity must > 0";
		throw illegalParameterValue(s.c_str());
	}
	arrayLength = initalCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<typename T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}