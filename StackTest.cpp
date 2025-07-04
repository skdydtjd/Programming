#include <iostream>
#include "StackTest.h"
#include <stack>

using namespace std;

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

bool checkWithStackTest(string input)
{
    StackTest stack;

    for (char ch : input)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.Push(ch);  // char을 int로 자동 형변환
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stack.isEmpty())
                return false;

            char topChar = stack.Peek(); // char로 받아도 int로 처리됨
            stack.Pop();

            if (!isMatching(topChar, ch))
                return false;
        }
    }

    return stack.isEmpty();
}

bool checkWithStack(string input)
{
    stack<char> stack;

    for (char ch : input)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);  // char을 int로 자동 형변환
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stack.empty())
                return false;

            char topChar = stack.top(); // char로 받아도 int로 처리됨
            stack.pop();

            if (!isMatching(topChar, ch))
                return false;
        }
    }

    return stack.empty();
}

int main()
{
	StackTest s;

	s.Push(10);
	s.Push(20);
	s.Push(15);

	s.show();

	s.Pop();
	s.show();

    cout << s.isEmpty() << endl;;

    cout << s.Peek() << endl;

    string code1 = "{ int x = (a[5] + b) }";
    string code2 = "{ int y = (c*d)";
    string code3 = "int z = e[2) - {f/(6/4)}";


    // LinkedList를 상속하여 작성한 Stack으로 테스트
    if (checkWithStackTest(code1))
        cout << "code1: 괄호 짝이 맞습니다" << endl;
    else
        cout << "code1: 괄호 오류" << endl;

    if (checkWithStackTest(code2))
        cout << "code2: 괄호 짝이 맞습니다  " << endl;
    else
        cout << "code2: 괄호 오류" << endl;

    if (checkWithStackTest(code3))
        cout << "code3: 괄호 짝이 맞습니다  " << endl;
    else
        cout << "code3: 괄호 오류" << endl;

    // Stack어댑터로 테스트
    if (checkWithStack(code1))
        cout << "code1: 괄호 짝이 맞습니다" << endl;
    else
        cout << "code1: 괄호 오류" << endl;

    if (checkWithStack(code2))
        cout << "code2: 괄호 짝이 맞습니다  " << endl;
    else
        cout << "code2: 괄호 오류" << endl;

    if (checkWithStack(code3))
        cout << "code3: 괄호 짝이 맞습니다  " << endl;
    else
        cout << "code3: 괄호 오류" << endl;

	return 0;
}