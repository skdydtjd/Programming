// 자료구조 연습문제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

template <typename T>

class dynamic_array {
	T* data;
	size_t n;

public:
	// 배열 크기를 인자로 받는 생성자
	dynamic_array(int n) 
	{
		this->n = n;
		data = new T[n];
	}

	// 복사 생성자
	dynamic_array(const dynamic_array<T>& other) 
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++) 
		{
			data[i] = other[i];
		}
	}

	// [] 연산자를 만드는 함수
	T& operator[](int index) 
	{
		return data[index];
	}

	const T& operator[](int index) const {
		return data[index];
	}
	// 두번씩 선언한 이유는 const 유형이 아닌 객체와 const 유형인 객체를 둘다 처리하기 위해

	T& at(int index) {
		if (index < n) 
			return data[index];
		throw 
			"Index out of range";
	}

	size_t size() const 
	{
		return n;
	}

	~dynamic_array() 
	{
		delete[] data;
	}

	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }


	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2) 
	{
		dynamic_array<T> result(arr1.size() + arr2.size());

		copy(arr1.begin(), arr1.end(), result.begin());
		copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}

	string to_string(const std::string& sep = ", ") 
	{
		if (n == 0) 
			return "";

		ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++) 
		{
			os << sep << data[i];
		}

		return os.str();
	}
};

struct student
{
	string name;
	int standard;
};

ostream& operator<<(ostream& os, const student& s) 
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
	int nStudnets;

	cout << "1반 학생 수를 입력하세요: ";
	cin >> nStudnets;

	dynamic_array<student> class1(nStudnets);

	for (int i = 0; i < nStudnets; i++) 
	{
		string name;
		int standard;

		cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		cin >> name >> standard;

		class1[i] = student{ name, standard };
	}

	try 
	{
		class1.at(nStudnets) = student{ "John", 8 }; // 예외 발생
	}
	catch (...) 
	{
		cout << "예외 발생" << endl;
	}

	auto class2 = class1;
	cout << "1반을 복사하여 2반 생성: " << class2.to_string() << endl;

	auto class3 = class1 + class2;
	cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << endl;

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
