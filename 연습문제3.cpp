#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

// 시민 구조체 정의
struct citizen
{
	string name;
	int age;
};

// 출력 연산자 형식 정의
ostream& operator<<(ostream& os, const citizen& c)
{
	return (os << "[" << c.name << "," << c.age << "]");
}

// 아이스크림 구조체 정의
struct icecream
{
	string name;
	int price;
};

// 새로운 예제 출력 연산자 형식 정의
ostream& operator<<(ostream& os, const icecream& i)
{
	return (os << "[" << i.name << "," << i.price << "]");
}

void main()
{
	// 시민 구조체 리스트 데이터 값 할당
	forward_list<citizen> citizens = {
		{"Kim", 22},{"Lee", 25},{"Park", 18},{"Jin", 16}
	};

	// 깊은 복사
	auto citizen_copy = citizens;

	// citizens에 있는 데이터들 출력
	cout << "전체 시민들:";

	for (const auto& c : citizens)
	{
		cout << c << " ";
	}

	cout << endl;

	// 나이가 19세보다 작으면 리스트에서 제거
	citizens.remove_if([](const citizen& c)
		{
			return (c.age < 19);
		});

	cout << "투표권이 있는 시민들 :";

	for (const auto& c : citizens)
	{
		cout << c << " ";
	}

	cout << endl;

	// 내년에 투표권이 생기는 사람들
	citizen_copy.remove_if([](const citizen& c)
		{
			return (c.age != 18);
		});

	cout << " 내년에 투표권이 생기는 시민들 :";

	for (const auto& c : citizen_copy)
	{
		cout << c << " ";
	}

	cout << endl;
	
	// forward_list의 remove_if 함수 활용

	// 변수 할당
	int number;

	cin >> number;

	// 동적 구조체 배열
	icecream* ice = new icecream[number];

	// list 할당
	forward_list<icecream> icecreams;

	// 값 입력
	for (int i = 0;i < number;i++)
	{
		cin >> ice[i].name;
		cin >> ice[i].price;

		// list에 값 저장
		icecreams.push_front(ice[i]);
	}

	// remove_if를 활용한 특정 데이터 제거
	icecreams.remove_if([](const icecream & i)
	{
			return (i.price > 2000);
	});

	// 출력
	cout << " 저렴한 아이스크림들 :";

	for (const auto& i : icecreams)
	{
		cout << i << " ";
	}

	cout << endl;
}