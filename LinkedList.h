#pragma once
#include <iostream>

using namespace std;

class List
{
protected:
	struct Node
	{
		int data;
		Node* nextnode;
	};
	int count; //����Ʈ ũ�� ����
	Node* Head = new Node;

public:
	List()
	{
		Head->data = NULL;
		Head->nextnode = NULL;
		count = 0;
	}

	// �� ����� �����͸� ���������� ���
	void traverse()
	{
		Node* test = Head->nextnode;

		while (test != NULL)
		{
			cout << test->data << endl;
			test = test->nextnode;
		}
	}

	// �� �տ� ���ο� ��� �߰�
	void addFirst(int data)
	{
		Node* temp = Head;
		Node* newnode = new Node;

		newnode->data = data;
		newnode->nextnode = NULL;

		if (temp->nextnode == NULL)
		{
			temp->nextnode = newnode;
		}
		else
		{
			newnode->nextnode = temp->nextnode;

			temp->nextnode = newnode;
		}

		count++;
	}

	// �� �ڿ� ���ο� ��� �߰�
	void addLast(int data)
	{
		Node* newnode = new Node;

		newnode->data = data;
		newnode->nextnode = NULL;

		if (Head->nextnode == NULL)
		{
			Head->nextnode = newnode;
		}
		else
		{
			Node* temp = Head->nextnode;
			while (temp->nextnode != NULL)
			{
				temp = temp->nextnode;
			}
			temp->nextnode = newnode;
		}

		count++;
	}

	// List�� ����
	int size()
	{
		return count;
	}

	// �� ù ��° ��� ����
	void deleteFirst()
	{
		Node* remove = Head->nextnode;

		if (remove == NULL)
		{
			cout << "�� ����Ʈ�� ����ֽ��ϴ�" << endl;
			return;
		}

		Head->nextnode = remove->nextnode;
		remove->nextnode = NULL;

		delete remove;

		count--;
	}

	// �� ������ ��� ����
	void deleteLast()
	{
		Node* temp = Head;
		Node* remove = Head->nextnode;

		if (remove == NULL)
		{
			cout << "�� ����Ʈ�� ����ֽ��ϴ�" << endl;
			return;
		}
		else if (remove->nextnode == NULL)
		{
			delete remove;
			Head->nextnode = NULL;
		}
		else
		{
			while (remove->nextnode != NULL)
			{
				temp = remove;
				remove = remove->nextnode;
			}
			temp->nextnode = NULL;

			delete remove;
		}

		count--;
	}

	void reverse() {
		Node* prev = NULL;
		Node* curr = Head;
		Node* next = NULL;

		while (curr != NULL) {
			next = curr->nextnode;     // ���� ��� ���
			curr->nextnode = prev;     // ���� ������
			prev = curr;           // ���� ��� �̵�
			curr = next;           // ���� ��� �̵�
		}
		Head = prev; // �� head ����
	}

	bool isEmpty()
	{
		Node* temp = Head;

		if (temp->nextnode == NULL)
		{
			cout << "�� ����Ʈ�� �������" << endl;
			return true;
		}
		else
		{
			cout << "�� ����Ʈ�� ���� �Ҵ�Ǿ� ����" << endl;
			return false;
		}
	}
};