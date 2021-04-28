#pragma once
 #include "Node.h"
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	Node<T>* tail;
	bool DeleteFirst(T& frntEntry)
	{
		if (isEmpty())
			return false;
		else if (Head->getNext() == nullptr)
		{
			frntEntry = Head->getItem();
			delete Head;
			Head = tail = nullptr;

		}
		else
		{
			frntEntry = Head->getItem();
			Node<T>* temp = new Node<T>;
			temp = Head;
			Head = Head->getNext();
			delete temp;

		}


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
	void InsertEnd(const T& data)
	{
		Node<T>* p = new Node<T>;
		p->setItem(data);
		if (!Head)
		{
			Head = tail = p;
			p->setNext(nullptr);
			return;
		}

		else if (!Head->getNext())
		{
			tail = p;
			Head->setNext(p);
			tail->setNext(nullptr);
		}
		else
		{

			tail->setNext(p);
			p->setNext(nullptr);
			tail = p;
		}
	}
	
	bool peek(T& frntEntry)
	{
		if (isEmpty())
			return false;

		frntEntry = Head->getItem();
		return true;

	}
	void DeleteLast(T& frntEntry)
	{
		Node<T>* temp = Head;
		if (!Head)
		{
			return;
		}
		frntEntry = tail->getItem();
		while (temp->getNext() != tail)
		{
			temp = temp->getNext();
		}
		temp->setNext(nullptr);
		tail = temp;
	}

	bool DeleteNode(const T& value)
	{
		bool found = false;
		if (!Head)
		{
			return found;
		}
		Node<T>* prev = Head;
		if (Head->getItem() == value)
		{
			T num;
			DeleteFirst(num);
			found = true;
			return found;
		}

		while (prev->getNext()->getNext())
		{
			if (prev->getNext()->getItem() == value)
			{

				Node<T>* temp = new Node<T>;
				temp = prev->getNext();
				prev->setNext(temp->getNext());
				delete temp;
				found = true;
				return found;

			}
			else
				prev = prev->getNext();

		}
		if (prev->getNext()->getItem() == value)
		{
			DeleteLast();
			found = true;

		}
		return found;
	}



};