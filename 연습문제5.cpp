#include <iostream>
#include <algorithm>

using namespace std;

struct singly_ll_node 
{
	int data;
	singly_ll_node* next;
};

class singly_ll {
public:
	using node = singly_ll_node;
	using node_ptr = node*;

private:
	node_ptr head;

public:
	//(���Ҹ� �� ������ ����)
	void push_front(int val) 
	{
		auto new_node = new node{ val, NULL };

		if (head != NULL)
		{
			new_node->next = head; // ����Ʈ�� ������� �ʴٸ�
		}
		head = new_node; // �� ��尡 head�� �ȴ�.
	}

	//(�� �� ���� ����)
	void pop_front() 
	{
		auto first = head;

		if (head) 
		{ 
			head = head->next;
			delete first;
		}
	}

	// ����Ʈ �ݺ��� ����
	struct singly_ll_iterator 
	{
	private:
		node_ptr ptr;

	public:
		// ������ ����(������� ptr�� p�� �ʱ�ȭ)
		singly_ll_iterator(node_ptr p) : ptr(p) {}

		// *������ ���� ptr->data�� �����ϵ��� ��
		int& operator*() { return ptr->data; }

		// ����� ���� �޼��� get���� ptr�� ��ȯ�ϵ��� ��
		node_ptr get() { return ptr; }

		// ����, ���� ������ ����
		singly_ll_iterator& operator++() 
		{
			ptr = ptr->next;
			return *this;
		}

		singly_ll_iterator operator++(int) 
		{
			singly_ll_iterator result = *this;
			++(*this);
			return result;
		}

		// == ������ ���� 
		friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right) 
		{
			return left.ptr == right.ptr;
		}
		friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right) 
		{
			return left.ptr != right.ptr;
		}
	};

	// begin(), end() ������ ���� - const�ΰͰ� const �ƴ� �� ���� ����
	singly_ll_iterator begin() { return singly_ll_iterator(head); }
	singly_ll_iterator end() { return singly_ll_iterator(NULL); }
	singly_ll_iterator begin() const { return singly_ll_iterator(head); }
	singly_ll_iterator end() const { return singly_ll_iterator(NULL); }

	singly_ll() = default; // �⺻ ������ ����

	// �Ű������� other(����Ʈ)�� �޾ƿ��� �� head�� NULL�� �ʱ�ȭ ���� �� other�� ������ ������ ���� ���縦 ���ش�.
	singly_ll(const singly_ll& other) : head(NULL) 
	{
		if (other.head) 
		{
			head = new node{ 0, NULL };

			auto cur = head;
			auto it = other.begin();

			while (true) 
			{
				cur->data = *it; //�Ű������� ���� ����Ʈ�� n��° ���� ������ �� 
				auto tmp = it;
				++tmp;
				if (tmp == other.end()) 
					break;

				cur->next = new node{ 0, NULL };
				cur = cur->next;
				it = tmp;
			}
		}
	}

	// �ʱ�ȭ ����Ʈ ������ ����
	singly_ll(const initializer_list<int>& ilist) : head(NULL) 
	{
		for (auto it = rbegin(ilist); it != rend(ilist); it++) push_front(*it);
	}

};

int main() 
{
	singly_ll sll = { 1,2,3 };
	sll.push_front(0);

	cout << "ù ��° ����Ʈ: ";
	for (auto i : sll) 
	{
		cout << i << " ";
	}
	cout << endl;


	auto sll2 = sll;
	sll2.push_front(-1);

	cout << "ù ��° ����Ʈ�� ������ ��, �� �տ� -1�� �߰�: ";

	for (auto i : sll2) 
	{
		cout << i << ' ';
	}
	cout << endl;


	cout << "���� ���� �� ù ��° ����Ʈ: ";
	for (auto i : sll) 
	{
		cout << i << ' ';
	}
	cout << endl;
}