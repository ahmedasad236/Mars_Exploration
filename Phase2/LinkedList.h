#pragma once
 #include "Node.h"
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	Node<T>* tail;

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
		Head = nullptr;
		tail = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	bool isEmpty()
	{
		return Head == nullptr;
	}


	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
	
	bool Add(T& item)
	{
		Node<T>* newNode = new Node<T>(item);
		if (!newNode)
			return 0;

		newNode->setNext(Head);
		Head = newNode;
		return 1;
	}
	
	bool remove(T& value)
	{
		bool found = false;

		if (!Head)
			return found;

		Node<T>* prev = Head;
		if (Head->getItem() == value)
		{
			Head = prev->getNext();
			delete prev;
			return found;
		}

		Node<T>* curr = prev->getNext();
		while (curr)
		{
			if (curr->getItem() == value)
			{
				Node<T>* temp = curr;
				prev->setNext(curr->getNext());
				delete temp;
				return true;
			}

			prev = curr;
			curr = curr->getNext();
		}
	}

	bool contains(T item)
	{
		return (getPointerTo(item) != nullptr);
	}

	int getFreqOf(const T& item)
	{
		int freq = 0;
		Node<T>* ptr = Head;

		while (ptr)
		{
			if (ptr->getItem() == item)
				freq++;

			ptr = ptr->getNext();
		}

		return freq;
	}
};