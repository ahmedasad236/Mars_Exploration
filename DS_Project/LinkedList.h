#pragma once
#include "Node.h"
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	int itemCount;

	Node<T>* getPointerTo(T item)
	{
		bool found = false;
		Node<T>* curr = Head;
		while (!found && curr)
		{
			if (item == curr->getItem())
				found = true;

			curr = curr->getNext();
		}

		return curr;
	}

public:
	LinkedList()
	{
		itemCount = 0;
		Head = nullptr;
		tail = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{DeleteAll();}

	bool isEmpty()
	{return Head == nullptr;}

	Node<T>* getNodeAt(int position) 
	{
		
		if (position < 1 && position > itemCount) 
			return nullptr;
		

		Node<T>* curPtr = Head;
		for (int skip = 1; skip <= position; skip++)
			curPtr = curPtr->getNext();

		return curPtr;
	}

	T getEntry(int position) 
	{
		bool ableToGet = (position >= 1) && (position <= itemCount);

		if (ableToGet) {
			Node<T>* nodePtr = getNodeAt(position);
			return nodePtr->getItem();
		}

	}

	void DeleteAll()
	{
		while (!isEmpty())
			remove(1);
	}

	int getLength() {
		return itemCount;
	}

	bool Add(T& item, int pos = itemCount)
	{
		if(pos > itemCount || pos < 1)
			return 0;

		Node<T>* newNode = new Node<T>(item);
		if (!newNode)
			return 0;

		int i = 1;
		if (pos == i)
		{
			newNode->setNext(Head);
			Head = newNode;
		}

		else
		{
			Node<T>* ptr = getNodeAt(pos - 1);
			newNode->setNext(ptr->getNext());
			ptr->setNext(newNode);
		}
		
		itemCount++;
		return 1;
	}

	bool remove(int pos)
	{
		if (!Head || pos > itemCount || pos < 1)
			return 0;


		Node<T>* curr = Head;
		if (pos == 1)
		{
			curr = Head;
			Head = Head->getNext();
		}

		else
		{
			Node<T>* prev = getNodeAt(pos - 1);
			curr = prev->getNext();
			prev->setNext(curr->getNext();
		}
	
		curr->setNext(nullptr);
		delete curr;
		curr = nullptr;
		itemCount--;
		return 1;
	}

};
