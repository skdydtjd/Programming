#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

// �ù� ����ü ����
struct citizen
{
	string name;
	int age;
};

// ��� ������ ���� ����
ostream& operator<<(ostream& os, const citizen& c)
{
	return (os << "[" << c.name << "," << c.age << "]");
}

// ���̽�ũ�� ����ü ����
struct icecream
{
	string name;
	int price;
};

// ���ο� ���� ��� ������ ���� ����
ostream& operator<<(ostream& os, const icecream& i)
{
	return (os << "[" << i.name << "," << i.price << "]");
}

void main()
{
	// �ù� ����ü ����Ʈ ������ �� �Ҵ�
	forward_list<citizen> citizens = {
		{"Kim", 22},{"Lee", 25},{"Park", 18},{"Jin", 16}
	};

	// ���� ����
	auto citizen_copy = citizens;

	// citizens�� �ִ� �����͵� ���
	cout << "��ü �ùε�:";

	for (const auto& c : citizens)
	{
		cout << c << " ";
	}

	cout << endl;

	// ���̰� 19������ ������ ����Ʈ���� ����
	citizens.remove_if([](const citizen& c)
		{
			return (c.age < 19);
		});

	cout << "��ǥ���� �ִ� �ùε� :";

	for (const auto& c : citizens)
	{
		cout << c << " ";
	}

	cout << endl;

	// ���⿡ ��ǥ���� ����� �����
	citizen_copy.remove_if([](const citizen& c)
		{
			return (c.age != 18);
		});

	cout << " ���⿡ ��ǥ���� ����� �ùε� :";

	for (const auto& c : citizen_copy)
	{
		cout << c << " ";
	}

	cout << endl;
	
	// forward_list�� remove_if �Լ� Ȱ��

	// ���� �Ҵ�
	int number;

	cin >> number;

	// ���� ����ü �迭
	icecream* ice = new icecream[number];

	// list �Ҵ�
	forward_list<icecream> icecreams;

	// �� �Է�
	for (int i = 0;i < number;i++)
	{
		cin >> ice[i].name;
		cin >> ice[i].price;

		// list�� �� ����
		icecreams.push_front(ice[i]);
	}

	// remove_if�� Ȱ���� Ư�� ������ ����
	icecreams.remove_if([](const icecream & i)
	{
			return (i.price > 2000);
	});

	// ���
	cout << " ������ ���̽�ũ���� :";

	for (const auto& i : icecreams)
	{
		cout << i << " ";
	}

	cout << endl;
}