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
	//(원소를 맨 앞으로 삽입)
	void push_front(int val) 
	{
		auto new_node = new node{ val, NULL };

		if (head != NULL)
		{
			new_node->next = head; // 리스트가 비어있지 않다면
		}
		head = new_node; // 새 노드가 head가 된다.
	}

	//(맨 앞 원소 삭제)
	void pop_front() 
	{
		auto first = head;

		if (head) 
		{ 
			head = head->next;
			delete first;
		}
	}

	// 리스트 반복자 정의
	struct singly_ll_iterator 
	{
	private:
		node_ptr ptr;

	public:
		// 생성자 정의(멤버변수 ptr을 p로 초기화)
		singly_ll_iterator(node_ptr p) : ptr(p) {}

		// *연산자 사용시 ptr->data을 리턴하도록 함
		int& operator*() { return ptr->data; }

		// 사용자 정의 메서드 get으로 ptr을 반환하도록 함
		node_ptr get() { return ptr; }

		// 선행, 후행 연산자 정의
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

		// == 연산자 정의 
		friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right) 
		{
			return left.ptr == right.ptr;
		}
		friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right) 
		{
			return left.ptr != right.ptr;
		}
	};

	// begin(), end() 연산자 정의 - const인것과 const 아닌 것 따로 정의
	singly_ll_iterator begin() { return singly_ll_iterator(head); }
	singly_ll_iterator end() { return singly_ll_iterator(NULL); }
	singly_ll_iterator begin() const { return singly_ll_iterator(head); }
	singly_ll_iterator end() const { return singly_ll_iterator(NULL); }

	singly_ll() = default; // 기본 생성자 정의

	// 매개변수로 other(리스트)을 받아왔을 때 head를 NULL로 초기화 해준 뒤 other의 데이터 값으로 깊은 복사를 해준다.
	singly_ll(const singly_ll& other) : head(NULL) 
	{
		if (other.head) 
		{
			head = new node{ 0, NULL };

			auto cur = head;
			auto it = other.begin();

			while (true) 
			{
				cur->data = *it; //매개변수로 들어온 리스트의 n번째 원소 데이터 값 
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

	// 초기화 리스트 생성자 정의
	singly_ll(const initializer_list<int>& ilist) : head(NULL) 
	{
		for (auto it = rbegin(ilist); it != rend(ilist); it++) push_front(*it);
	}

};

int main() 
{
	singly_ll sll = { 1,2,3 };
	sll.push_front(0);

	cout << "첫 번째 리스트: ";
	for (auto i : sll) 
	{
		cout << i << " ";
	}
	cout << endl;


	auto sll2 = sll;
	sll2.push_front(-1);

	cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";

	for (auto i : sll2) 
	{
		cout << i << ' ';
	}
	cout << endl;


	cout << "깊은 복사 후 첫 번째 리스트: ";
	for (auto i : sll) 
	{
		cout << i << ' ';
	}
	cout << endl;
}