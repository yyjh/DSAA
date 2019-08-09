#pragma once

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<iterator>
#include "linearList.h"
#include "../Chapter1/illegalParameterValue.h"
#include "../Chapter1/changeLength1D.h"

using namespace std;

template<typename T>
class arrayList : public LinearList<T>
{
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; }

	//ADT方法
	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out) const;
	
	int capacity() const { return arrayLength; }
	
	class iterator;
	iterator begin() { return iterator(element); }
	iterator end() { return iterator(element + listSize); }

	class iterator
	{
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		iterator(T* thePosition = 0) { position = thePosition; }

		T& operator*() const { return *position; }
		T* operator->() const { return &*position; }

		iterator& operator++()	// 前加
		{
			++position;
			return *this;
		}
		iterator operator++(int)	// 后加
		{
			iterator old = *this;
			++position;
			return old;
		}

		iterator& operator--()	// 前减
		{
			--position;
			return *this;
		}
		iterator operator--(int)	// 后减
		{
			iterator old = *this;
			--position;
			return old;
		}

		bool operator!=(const iterator right) const
		{
			return position != right.position;
		}
		bool operator==(const iterator right) const
		{
			return position == right.position;
		}

	protected:
		T * position;
	};

protected:
	void checkIndex(int theIndex) const;
	T* element;			// 存储线性表元素的一维数组
	int arrayLength;	// 一维数组的容量
	int listSize;		// 线性表的元素个数
	
};

template<typename T>
arrayList<T>::arrayList(int initalCapacity)
{
	if (initalCapacity < 1)
	{
		string s = "capacity must > 0";
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
		throw illegalParameterValue(s.str().c_str());
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
		throw illegalParameterValue(s.str().c_str());
	}

	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	// 从最右端的数组开始移动
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
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