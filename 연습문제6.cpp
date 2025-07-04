#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int>list1 = { 1,2,3,4,5 };
	list1.push_back(6);
	list1.insert(next(list1.begin()), 0);
	list1.insert(list1.end(), 7);

	list1.pop_back();

	cout << "삽입 & 삭제 후 리스트: ";

	for (auto i : list1)
	{
		cout << i << " ";
	}
	cout << endl;


	list<int>list2 = { 11,15,17,3,29,57 };

	// 2 리스트의 교체
	list1.swap(list2);
	for (auto i : list1)
	{
		cout << i << " ";
	}
	cout << endl;

	for (auto i : list2)
	{
		cout << i << " ";
	}
	cout << endl;

	//정렬
	list1.sort();
	for (auto i : list1)
	{
		cout << i << " ";
	}
	cout << endl;
}