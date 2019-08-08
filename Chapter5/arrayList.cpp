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

template<typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << "size =" << listSize;
		throw illegalParameterValue(s.c_str());
	}
}

template<typename T>
T& arrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

template<typename T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int)(find(element, element + listSize, theElement));
	if (theIndex == listSize)
	{
		return -1;
	}
	else
	{
		return theIndex;
	}
}

template<typename T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();
}

template<typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalParameterValue(s.c_str());
	}

	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	// 从最右端的数组开始移动
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theIndex;
	listSize++;
}


template<typename T>
void arrayList<T>::output(std::ostream& out) const
{
	copy(element, element + listSize, ostream_iterator<T>(out, " "));
}

// 重载
template<typename T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x)
{
	x.output(out);
	return out;
}