#pragma once
#include "linearList.h"
#include <xutility>
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
	iterator begin() { return iterator(element); }
	iterator end() { return iterator(element + listSize); }

protected:
	void checkIndex(int theIndex) const;
	T* element;			// 存储线性表元素的一维数组
	int arrayLength;	// 一维数组的容量
	int listSize;		// 线性表的元素个数

public:
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
};
