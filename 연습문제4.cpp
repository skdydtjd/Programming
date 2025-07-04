#include <iostream>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

void main()
{
	// 명단
	vector<string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", " Nico Roseberg", "Sebastian Vettel", "Lewis Hamilton", 
		"Sebastian Vettel", "Sebastian Vettel", "Sebastian Vettel", "Fernado Alonso"
	};

	// 상수 시간
	auto it = vec.begin();
	cout << " 가장최근 우승자 = " << *it << endl;

	// 상수 시간
	it += 8;
	cout << "8년 전 우승자 = " << *it << endl;

	// 상수 시간
	advance(it, -3);
	cout << "그후 3년 뒤 우승자 = " << *it << endl;



	forward_list<string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	cout << " 가장최근 우승자 = " << *it1 << endl;

	advance(it1, 5);
	cout << "5년 전 우승자 = " << *it1 << endl;

	// advance(it1, -2); -> 에러 발생
	// 양방향이 가능한 vector와 달리 forward_list는 한방향으로만 이동할 수 있음
	// it1 += 2; -> 이 또한 에러 발생
	// forward_list는 무조건 연속적인 순회를 통해서만 각 인자값 접근 가능



	list<string> tl(vec.begin(), vec.end());

	auto it2 = tl.begin();
	cout << " 가장최근 우승자 = " << *it2 << endl;

	advance(it2, 4);
	cout << "4년 전 우승자 = " << *it2 << endl;

	advance(it2, -2);
	cout << "그후 2년 뒤 우승자 = " << *it2 << endl;

	// it2 += 4; -> 에러 발생
	// list는 forward_list에 비해 양방향으로 이동이 가능하지만 연속적인 순회를 통해서만 각 인자값 접근 가능
}