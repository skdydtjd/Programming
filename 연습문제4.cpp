#include <iostream>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

void main()
{
	// ���
	vector<string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", " Nico Roseberg", "Sebastian Vettel", "Lewis Hamilton", 
		"Sebastian Vettel", "Sebastian Vettel", "Sebastian Vettel", "Fernado Alonso"
	};

	// ��� �ð�
	auto it = vec.begin();
	cout << " �����ֱ� ����� = " << *it << endl;

	// ��� �ð�
	it += 8;
	cout << "8�� �� ����� = " << *it << endl;

	// ��� �ð�
	advance(it, -3);
	cout << "���� 3�� �� ����� = " << *it << endl;



	forward_list<string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	cout << " �����ֱ� ����� = " << *it1 << endl;

	advance(it1, 5);
	cout << "5�� �� ����� = " << *it1 << endl;

	// advance(it1, -2); -> ���� �߻�
	// ������� ������ vector�� �޸� forward_list�� �ѹ������θ� �̵��� �� ����
	// it1 += 2; -> �� ���� ���� �߻�
	// forward_list�� ������ �������� ��ȸ�� ���ؼ��� �� ���ڰ� ���� ����



	list<string> tl(vec.begin(), vec.end());

	auto it2 = tl.begin();
	cout << " �����ֱ� ����� = " << *it2 << endl;

	advance(it2, 4);
	cout << "4�� �� ����� = " << *it2 << endl;

	advance(it2, -2);
	cout << "���� 2�� �� ����� = " << *it2 << endl;

	// it2 += 4; -> ���� �߻�
	// list�� forward_list�� ���� ��������� �̵��� ���������� �������� ��ȸ�� ���ؼ��� �� ���ڰ� ���� ����
}