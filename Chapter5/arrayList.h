#pragma once
#include "linearList.h"

template<typename T>
class arrayList : public LinearList<T>
{
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; }

	//ADT����
	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out) const;

	int capacity() const { return arrayLength; }

protected:
	void checkIndex(int theIndex) const;
	T* element;			// �洢���Ա�Ԫ�ص�һά����
	int arrayLength;	// һά���������
	int listSize;		// ���Ա��Ԫ�ظ���

};
