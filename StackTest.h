#pragma once

#include <iostream>
#include "LinkedList.h"

using namespace std;

class StackTest : public List
{
public:
	void Push(int value)
	{
		addFirst(value); 
	}

	void Pop()
	{
		if (Head->nextnode == NULL)
		{
			cout << "Stack�� �������" << endl;
		}
		else
		{
			deleteFirst();
		}
	}

	int Peek()
	{
		if (Head->nextnode != NULL)
		{
			return Head->nextnode->data;
		}
		else
		{
			cout << "Stack�� �������" << endl;
		}
	}

	void show()
	{
		cout << "���� �� ������ = ";
		traverse();
	}

	bool isEmpty()
	{
		Node* stackDate = Head;

		if (stackDate->nextnode == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
