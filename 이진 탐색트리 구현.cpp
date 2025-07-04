// 이진 탐색트리 구현.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

// 각 노드 기본 구조
struct node
{
    int data;
    node* left;
    node* right;
};

//탐색 구조체
struct bst
{
    node* root = NULL;

    node* find(int value)
    {
        return find_impl(root, value);
    }

private:
    // 해당하는 값을 가지는 노드 찾는 함수
    node* find_impl(node* current, int value)
    {
        if (!current)
        {
            cout << endl;
            return NULL;
        }

        if (current->data == value)
        {
            cout << value << "을 찾았습니다" << endl;
            return current;
        }
        else if (value < current->data) // value값이 현재 노드 왼쪽에 있는 경우
        {
            cout << current->data << "왼쪽으로 이동: ";
            return find_impl(current->left,value);
        }
        else if (current->data < value) // value값이 현재 노드 오른쪽에 있는 경우
        {
            cout << current->data << "오른쪽으로 이동: ";
            return find_impl(current->right,value);
        }
    }

public:
    void insert(int value)
    {
        if (!root)
        {
            root = new node{ value,NULL,NULL };
        }
        else
        {
            insert_impl(root, value);
        }
    }

private:
    // 새로운 값을 추가하는 함수
    void insert_impl(node* current, int value)
    {
        if (value < current->data)
        {
            if (!current->left)
                current->left = new node{ value,NULL,NULL };
            else
                insert_impl(current->left, value);
        }
        else
        {
            if (!current->right)
                current->right = new node{ value,NULL,NULL };
            else
                insert_impl(current->right, value);
        }
    }

public:
    void inorder()
    {
        inorder_impl(root);
    }
private:
    // 중위 순회 함수(값들이 정렬된 채로 출력되야 정상)
    void inorder_impl(node* start)
    {
        if (!start)
            return;

        inorder_impl(start->left);
        cout << start->data << " ";
        inorder_impl(start->right);
    }

public:
    // 후손 노드를 찾는 함수(오른쪽 서브 트리 중 가장 작은 값)
    node* successor(node* start)
    {
        auto current = start->right;

        while (current && current->left)
        {
            current = current->left;
        }
        return current;
    }

    // 후손을 반대로 찾는 함수 추가(왼쪽 서브 트리 중 가장 큰 값)
    node* reverseSuccessor(node* start)
    {
        auto current = start->left;

        while (current && current->right)
        {
            current = current->right;
        }
        return current;
    }

    void deleteValue(int value)
    {
        root = delete_impl(root, value);
    }

private:
    // 해당 노드를 삭제하는 함수
    node* delete_impl(node* start, int value)
    {
        if (!start)
            return NULL;

        if (value < start->data)
        {
            start->left = delete_impl(start->left, value);
        }
        else if (value > start->data)
        {
            start->right = delete_impl(start->right, value);
        }
        else
        {
            // 자식 노드가 전혀 없거나 왼쪽 자식 노드만 없는 경우
            if (!start->left)
            {
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            // 오른쪽 자식 노드만 없는 경우
            if (!start->right)
            {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            // 자식 노드 둘다 있는 경우
            // succNode = 후속 노드
            auto succNode = successor(start);
            //auto succNode = reverseSuccessor(start);
            start->data = succNode->data;

            // 오른쪽 서브트리에서 후속을 찾아 삭제
            start->right = delete_impl(start->right, succNode->data);
        }

        return start;
    }
};

int main()
{
    bst tree;

    tree.insert(14);
    tree.insert(13);
    tree.insert(19);
    tree.insert(4);
    tree.insert(7);
    tree.insert(11);
    tree.insert(29);
    tree.insert(6);
    tree.insert(2);

    cout << "중위 순회 = ";
    tree.inorder();
    cout << endl;

    tree.deleteValue(13);
    cout << "13을 삭제하고 난 후 중위순회 = ";
    tree.inorder();
    cout << endl;

    if (tree.find(13))
    {
        cout << "원소 13이 트리에 있습니다" << endl;
    }
    else
    {
        cout << "원소 13이 트리에 없습니다" << endl;
    }
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
