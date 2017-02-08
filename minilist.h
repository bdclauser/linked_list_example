#pragma once
#include <iostream>

using namespace std;

template <typename T> class miniList;

template <typename T>
class ListNode
{
	friend class miniList<T>;
private:
	ListNode<T> *nextPtr;
	T data;
public:
	ListNode(const T& info) : data(info), nextPtr(nullptr) {}
	T getData() const { return data; }
};

template <typename T>
class miniList
{
private:
	ListNode<T> *firstPtr;
	ListNode<T> *lastPtr;
	ListNode<T> *getNewNode(const T& value);
public:
	miniList();
	~miniList();
	void insertAtFront(const T& value);
	void insertAtBack(const T& value);
	void removeFromFront();
	void removeFromBack();
	bool isEmpty() const;
	void print() const;
	T front();
	T back();
	int size();
	miniList<T> operator=(const miniList<T>& rhs);
};

template <typename T>
miniList<T> miniList<T>::operator=(const miniList<T>& rhs)
{
	ListNode<T> *temp = rhs.firstPtr;

	if (rhs.isEmpty())
		return miniList<T>();

	while (temp != nullptr)
	{
		this->insertAtBack(temp->data);
		temp = temp->nextPtr;
	}
}

template <typename T>
int miniList<T>::size()
{
	ListNode<T> *temp = firstPtr;
	int counter = 0;

	if (isEmpty())
		return counter;

	counter++;
	while (temp != lastPtr)
	{
		temp = temp->nextPtr;
		counter++;
	}
	return counter;
}

template <typename T>
T miniList<T>::back()
{
	if (!isEmpty())
		return lastPtr->data;
	return NULL;
}

template <typename T>
T miniList<T>::front()
{
	if (!isEmpty())
		return firstPtr->data;
	return NULL;
}

template <typename T>
void miniList<T>::removeFromBack()
{
	if (isEmpty())
		return;

	ListNode<T> *temp = firstPtr;
	if (firstPtr == lastPtr)
	{
		delete firstPtr;
		firstPtr = lastPtr = nullptr;
		return;
	}

	while (temp->nextPtr->nextPtr != nullptr)
		temp = temp->nextPtr;

	lastPtr = temp;
	delete temp->nextPtr->nextPtr;
	temp->nextPtr = nullptr;
	
}

template <typename T>
void miniList<T>::removeFromFront()
{
	if (isEmpty())
		return;

	ListNode<T> *temp = firstPtr;
	if (firstPtr == lastPtr)
		firstPtr = lastPtr = nullptr;
	else
		firstPtr = firstPtr->nextPtr;

	delete temp;
}

template <typename T>
void miniList<T>::print() const
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}

	ListNode<T> *currPtr = firstPtr;
	while (currPtr != nullptr)
	{
		cout << currPtr->data << "\t";
		currPtr = currPtr->nextPtr;
	}

	cout << endl;
}

template <typename T>
bool miniList<T>::isEmpty() const
{
	return firstPtr == nullptr;
}

template <typename T>
void miniList<T>::insertAtBack(const T& value)
{
	ListNode<T> *nPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = nPtr;
	else
	{
		lastPtr->nextPtr = nPtr;
		lastPtr = nPtr;
	}
}

template <typename T>
void miniList<T>::insertAtFront(const T& value)
{
	ListNode<T> *nPtr = getNewNode(value);
	if (isEmpty())
		firstPtr = lastPtr = nPtr;
	else
	{
		nPtr->nextPtr = firstPtr;
		firstPtr = nPtr;
	}
}

template <typename T>
miniList<T>::miniList() : firstPtr(nullptr), lastPtr(nullptr)
{}

template <typename T>
miniList<T>::~miniList()
{

}

template <typename T>
ListNode<T>* miniList<T>::getNewNode(const T& value)
{
	return new ListNode<T>(value);
}