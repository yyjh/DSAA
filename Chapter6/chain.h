#pragma once
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
	T& get(int theIndex);
	int indexOf(const T& theElement) const;
	void erase(int gtheIdnex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;

protected:
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









