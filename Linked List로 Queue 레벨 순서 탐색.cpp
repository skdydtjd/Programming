// Linked List로 Queue 레벨 순서 탐색.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

// 이진 트리의 경우 최대 2개의 자식을 가지므로 이전, 다음 노드를 가르키도록 
// 새로 node 주소를 2개 선언해준다.
struct node
{
    int number;
    node* first;
    node* second;
};

// 루트 노드
struct tree
{
    node* root;

    // 최초 루트 노드를 생성하는 함수
    static tree create_org_struture(const int pos)
    {
        tree tree;
        tree.root = new node{ pos,NULL,NULL };

        return tree;
    }

    // 해당 값을 가지는 노드를 찾아 반환하는 함수
    static node* find(node* root, const int value)
    {
        if (root == NULL)
            return NULL;

        if (root->number == value)
            return root;

        auto firstFound = tree::find(root->first, value);

        if (firstFound != NULL)
            return firstFound;

        return tree::find(root->second, value);
    }

    // 새로운 자식 노드를 추가하는 함수(상위 노드 기준)
    bool addNewChildNode(const int manager, const int sub)
    {
        auto managerNode = tree::find(root, manager);

        if (!managerNode)
        {
            cout << manager << "를 찾을 수 없습니다 : " << endl;
        }

        if (managerNode->first && managerNode->second)
        {
            cout << manager << "아래에" << sub << "를 추가할 수 없습니다" << endl;

            return false;
        }

        if (!managerNode->first)
            managerNode->first = new node{ sub,NULL,NULL };
        else
            managerNode->second = new node{ sub,NULL,NULL };

        cout << manager << "아래에" << sub << "를 추가했습니다" << endl;

        return true;
    }

    // 레벨 순서 순회 함수
    static void levelOrder(node* start)
    {
        if (!start)
            return;

        // Linked List형태로 구성된 queue는 
        // deleteFirst, LastIn을 따른다. 현재는 queue어댑터를 활용했다.
        queue<node*> q;
        q.push(start);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0;i < size;i++)
            {
                auto current = q.front();
                q.pop();

                cout << current->number << ", ";

                if (current->first)
                    q.push(current->first);
                if (current->second)
                    q.push(current->second);
            }

            cout << endl;
        }
    }
};

int main()
{

    // 트리 루트 노드 생성
    tree example = tree::create_org_struture(1);

    //자식 노드 추가
    example.addNewChildNode(1, 3);
    example.addNewChildNode(1, 4);

    example.addNewChildNode(3, 2);
    example.addNewChildNode(3, 5);
    example.addNewChildNode(4, 6);
    example.addNewChildNode(4, 7);

    example.addNewChildNode(2, 8);
    example.addNewChildNode(2, 9);
    example.addNewChildNode(5, 10);
    example.addNewChildNode(5, 11);
    example.addNewChildNode(6, 12);
    example.addNewChildNode(6, 13);
    example.addNewChildNode(7, 14);
    example.addNewChildNode(7, 15);

    // 자식 노드에 이미 값이 할당되있음
    example.addNewChildNode(2, 31);

    // 레벨 순서 순회(너비 우선 탐색 방법)진행
    example.levelOrder(example.root);
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
