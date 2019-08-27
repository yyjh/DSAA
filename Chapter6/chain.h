#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct chainNode
{
	// 数据成员
	T element;
	chainNode<T> *next;

	chainNode(){}
	chainNode(const T& element)
	{
		this->element = element;
	}
	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};

template<typename T>
class chain : public linearList<T>
{
public:
	chain(int initalCapacity = 10);
	chain(const chain<T>&);
	~chain();

	bool empty() const { return listSize == 0; }
	int size() const { return listSize; };
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int gtheIdnex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(nullptr); }
	void setSize(int theSize);
public:
	class
	{
	public:
		iterator(chainNode<T>* theNode = nullptr) { node = theNode; }
		T& operator*() const { return node->element; }
		T* operator->() const { return &node->element; }
		iterator& operator++()	// 前加
		{
			node = node->next;
			return &node->element;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			node = node->next;
			return old;
		}

		bool operator!=(const iterator right) const
		{
			return node != right.node;
		}
		bool operator==(const iterator right) const
		{
			return node == right.node;
		}
	private:
		chainNode<T>* node;
	};	

private:
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;
	int listSize;
};

template<typename T>
chain<T>::chain(int initialCapacity)
{
	firstNode = nullptr;
	listSize = 0;
}

template<typename T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = nullptr;
		return;
	}

	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	while (sourceNode != nullptr)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = nullptr;
}

template<typename T>
chain<T>::~chain()
{
	while (firstNode != nullptr)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<typename T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);

	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; ++i)
	{
		currentNode = currentNode->next;
	}
	return currentNode;
}

template<typename T>
int chain<T>::indexOf(const T& theElement) const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != nullptr && currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		++index;
	}
	if (currentNode == nullptr)
	{
		return -1;
	}
	else
	{
		return index;
	}
}

template<typename T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T*> deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->element;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; ++i)
		{
			p = p->next;
		}
		deleteNode = p->next;
		p->next = p->next->next;
	}
	--listSize;
	delete deleteNode;
}

template<typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
	{
		return;
	}
	if (theIndex == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; ++i)
		{
			p = p->next;
		}
		p->next = new chainNode<T>(theElement, p->next);
	}
	++listSize;
}

template<typename T>
void chain<T>::output(ostream& out) const
{
	for (chainNode<T>* currentNode = firstNode;
		currentNode != nullptr;
		currentNode = currentNode->next)
	{
		cout << currentNode->element << " ";
	}
}

template<typename T>
void chain<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << "size =" << listSize;
		throw illegalParameterValue(s.str().c_str());
	}
}

template<typename T>
void chain<T>::setSize(int theSize)
{
	if ()
	{
	}
}

template<typename T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
	x.output(out);
	return out;
}









