#pragma once
#include "Node.h"
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	Node<T>* Tail;
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
		Tail = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	
	bool isEmpty()
	{return Head == nullptr;}

	Node<T>* getNodeAt(int position) 
	{
		
		if (position < 1 || position > itemCount) 
			return nullptr;

		Node<T>* curPtr = Head;
		for (int skip = 1; skip < position; skip++)
			curPtr = curPtr->getNext();

		return curPtr;
	}

	T getEntry(int position) 
	{
		if ((position < 1) || (position > itemCount))
		{
			return nullptr;
		}
		Node<T>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();

	}

	void DeleteAll()
	{
		while (!isEmpty())
			remove(1);
	}

	int getLength() {
		return itemCount;
	}

	bool Add(const T& newEntry,int newPosition=1 )
	{
		bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
		if (ableToInsert) {
			Node<T>* newNodePtr = new Node<T>(newEntry);
			if (newPosition == 1) {

				newNodePtr->setNext(Head);
				Head = newNodePtr;
			}
			else {
				Node<T>* prevPtr = getNodeAt(newPosition - 1);
				newNodePtr->setNext(prevPtr->getNext());
				prevPtr->setNext(newNodePtr);
			}
			itemCount++;
		}


		return ableToInsert;

		
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
			prev->setNext(curr->getNext());
		}
	
		curr->setNext(nullptr);
		delete curr;
		curr = nullptr;
		itemCount--;
		return 1;
	}
	~LinkedList()
	{
		DeleteAll();
	}

};
