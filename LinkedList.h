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
	int count; //리스트 크기 변수
	Node* Head = new Node;

public:
	List()
	{
		Head->data = NULL;
		Head->nextnode = NULL;
		count = 0;
	}

	// 각 노드의 데이터를 순차적으로 출력
	void traverse()
	{
		Node* test = Head->nextnode;

		while (test != NULL)
		{
			cout << test->data << endl;
			test = test->nextnode;
		}
	}

	// 맨 앞에 새로운 노드 추가
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

	// 맨 뒤에 새로운 노드 추가
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

	// List의 길이
	int size()
	{
		return count;
	}

	// 맨 첫 번째 노드 삭제
	void deleteFirst()
	{
		Node* remove = Head->nextnode;

		if (remove == NULL)
		{
			cout << "이 리스트는 비어있습니다" << endl;
			return;
		}

		Head->nextnode = remove->nextnode;
		remove->nextnode = NULL;

		delete remove;

		count--;
	}

	// 맨 마지막 노드 삭제
	void deleteLast()
	{
		Node* temp = Head;
		Node* remove = Head->nextnode;

		if (remove == NULL)
		{
			cout << "이 리스트는 비어있습니다" << endl;
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
			next = curr->nextnode;     // 다음 노드 기억
			curr->nextnode = prev;     // 방향 뒤집기
			prev = curr;           // 이전 노드 이동
			curr = next;           // 현재 노드 이동
		}
		Head = prev; // 새 head 설정
	}

	bool isEmpty()
	{
		Node* temp = Head;

		if (temp->nextnode == NULL)
		{
			cout << "이 리스트는 비어있음" << endl;
			return true;
		}
		else
		{
			cout << "이 리스트는 값이 할당되어 있음" << endl;
			return false;
		}
	}
};