#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class WeightedGraph {
	int numVertex; //vertex의 수

	// pair = 두 개의 값을 묶는 구조체(struct로 표현가능)
	vector<vector<pair<int, int>>> List; // 인접	
public:
	// 생성자
	WeightedGraph(int nv) : numVertex(nv) {
		List.resize(numVertex);
	}

	// Edge 추가
	void addEdge(int u, int v, int weight);
	// Graph 내용 출력
	void printGraph();


//		
// 과제 (구현하여야 하는 멤버 함수) 
//

	/* bool isConnected(); 
	   설명: Connected Graph 인지 조사
	   Connected Graph 이면 true 아니면 false 반환 */
	
	bool isConnected()
	{
		vector<bool> visited(numVertex, false);

		queue<int> q;
		q.push(0);
		visited[0] = true;

		int visitedCount = 1;

		while (!q.empty())
		{
			int i = q.front();
			q.pop();

			for (auto& neighbor : List[i])
			{
				int v = neighbor.first;

				if (!visited[v])
				{
					visited[v] = true;
					visitedCount++;
					q.push(v);
				}
			}
		}
		return visitedCount == numVertex;
	}

	/* bool isAdjacent(int u, int v); 
	   설명 vertex u와 vertex v 가 인접한지 조사 
	   인접한 vertex 이면 true, 아니면 false 반환 */
	
	bool isAdjacent(int u, int v)
	{
		for (auto& neighbor : List[u])
		{
			int s = neighbor.first;

			if (s == v)
			{
				return true;
			}
		}
		return false;
	}

	/* void BFS(int s);
	   설명: s(시작 vertex 번호)로 부터 너비우선 탐색한 후
	   방문한 vertex 번호를 출력하는 함수 */
	
	void BFS(int s)
	{
		vector<bool> visited(numVertex, false);
		queue<int> q;
		q.push(s);

		visited[s] = true;

		while (!q.empty()) 
		{
			int u = q.front(); 
			q.pop();
			cout << u << " ";

			for (auto& neighbor : List[u]) 
			{
				int v = neighbor.first;

				if (!visited[v]) 
				{
					visited[v] = true;
					q.push(v);
				}
			}
		}
		cout << endl;
	}

	/* void DFS(int s);
	   설명: s(시작 vertex 번호)로 부터 깊이우선 탐색한 후
	   방문한 vertex 번호를 출력하는 함수 */
	
	void DFS(int s)
	{
		vector<bool> visited(numVertex, false);
		stack<int> st;

		st.push(s);

		while (!st.empty()) 
		{
			int u = st.top(); 
			st.pop();

			if (!visited[u]) 
			{
				cout << u << " ";
				visited[u] = true;

				//역순으로 push
				for (auto it = List[u].rbegin(); it != List[u].rend(); ++it) 
				{
					if (!visited[it->first]) 
					{
						st.push(it->first);
					}
				}
			}
		}
		cout << endl;
	}
	
	/* void minSpanningTree();
	   설명: prime 알고리즘을 이용하여 minimum Spanning Tree
	   찾아 Tree의 에지를 출력하는 함수*/
	
	void minSpanningTree()
	{
		vector<bool> inMST(numVertex, false);

		// 우선순위 큐: (가중치, (출발 노드, 도착 노드))
		// greater<> = 기본적으로 최대 힙을 가지는 우선순위 큐를 최소 힙으로 정렬하는 객체
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

		inMST[0] = true;

		for (auto& [v, w] : List[0])
		{
			pq.push({ w, {0, v} });
		}

		while (!pq.empty())
		{
			auto [weight, edge] = pq.top(); 
			pq.pop();
			auto [u, v] = edge;

			if (inMST[v]) 
				continue;

			inMST[v] = true;
			cout << u << " - " << v << " (weight " << weight << ")\n";

			for (auto& [next, w] : List[v])
			{
				if (!inMST[next])
				{
					pq.push({ w, {v, next} });
				}
			}
		}
	}

	/* void dijkstra(int s);
	   설명: s(시작 vertex 번호)로 다른 vertex까지의 distance 값을 
	   출력하는 함수 */

	void dijkstra(int s)
	{
		// 한 정점에서 다른 정점까지의 초기거리를 최대로 초기화 (int가 표현가능한 최대값)
		vector<int> dist(numVertex, numeric_limits<int>::max());
		dist[s] = 0;

		// greater<> = 기본적으로 최대 힙을 가지는 우선순위 큐를 최소 힙으로 정렬하는 객체
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		pq.push({ 0, s });

		while (!pq.empty()) 
		{
			auto [d, u] = pq.top(); 
			pq.pop();

			if (d > dist[u]) 
				continue;

			for (auto& [v, w] : List[u]) 
			{
				if (dist[v] > dist[u] + w) 
				{
					dist[v] = dist[u] + w;

					pq.push({ dist[v], v });
				}
			}
		}

		for (int i = 0; i < numVertex; i++) 
		{
			cout << "Distance from " << s << " to " << i << ": ";

			if (dist[i] == numeric_limits<int>::max()) 
				cout << "INF\n";
			else
				cout << dist[i] << "\n";
		}
	}
};

void WeightedGraph::addEdge(int u, int v, int weight) {
	List[u].push_back({v, weight});
	List[v].push_back({u, weight});
}

void WeightedGraph::printGraph() 
{
	cout << "Graph adjecent list with weight" << endl;
	for(int i = 0; i < numVertex; i++) {
		cout << i << ": ";
			
		for(auto& neighbor : List[i]) 
			cout << "[" << neighbor.first << ", " << neighbor.second << "]";

		cout << endl;	
	}
}


int main(int argc, char const *argv[])
{
	// 8개의 정점을 가지므로 9를 넣음
	WeightedGraph g(9);

	//자료구조_마지막_과제 상에 있는 그래프 구현 후 테스트
    g.addEdge(0, 1, 15);
    g.addEdge(0, 2, 25);

    g.addEdge(1, 4, 10);
    g.addEdge(1, 7, 5);
    g.addEdge(1, 8, 25);

	g.addEdge(2, 3, 10);
	g.addEdge(2, 4, 20);

	g.addEdge(4, 5, 10);
	g.addEdge(4, 6, 5);

	g.addEdge(7, 8, 15);

    g.printGraph();

	cout << "\nIs graph connected? " << (g.isConnected() ? "Yes" : "No") << endl;
	cout << "Is 0 adjacent to 3? " << (g.isAdjacent(0, 3) ? "Yes" : "No") << endl;
	cout << "Is 1 adjacent to 2? " << (g.isAdjacent(1, 2) ? "Yes" : "No") << endl;

	cout << "\nBFS from 0:";
	g.BFS(0);

	cout << "DFS from 0:";
	g.DFS(0);

	cout << "\nMinimum Spanning Tree:\n";
	g.minSpanningTree();

	cout << "\nDijkstra from node 0:\n";
	g.dijkstra(0);



	// Not Connected Graph 구현 및 테스트
	WeightedGraph ng(5);

	ng.addEdge(0, 1, 3);
	ng.addEdge(0, 2, 5);
	ng.addEdge(0, 3, 6);

	ng.addEdge(1, 2, 2);
	ng.addEdge(1, 3, 7);

	ng.addEdge(2, 3, 3);

	
	ng.printGraph();

	cout << "\nIs graph connected? " << (ng.isConnected() ? "Yes" : "No") << endl;
	cout << "Is 0 adjacent to 3? " << (ng.isAdjacent(0, 3) ? "Yes" : "No") << endl;
	cout << "Is 1 adjacent to 2? " << (ng.isAdjacent(1, 2) ? "Yes" : "No") << endl;

	cout << "\nIs 4 adjacent to 0? " << (ng.isAdjacent(4, 0) ? "Yes" : "No") << endl;
	cout << "Is 4 adjacent to 1? " << (ng.isAdjacent(4, 1) ? "Yes" : "No") << endl;
	cout << "Is 4 adjacent to 2? " << (ng.isAdjacent(4, 2) ? "Yes" : "No") << endl;
	cout << "Is 4 adjacent to 3? " << (ng.isAdjacent(4, 3) ? "Yes" : "No") << endl;

	cout << "\nBFS from 0:";
	ng.BFS(0);

	cout << "DFS from 0:";
	ng.DFS(0);

	cout << "\nMinimum Spanning Tree:\n" << endl;;
	ng.minSpanningTree();

	cout << "\nDijkstra from node 0:\n" << endl;;
	ng.dijkstra(0);

	return 0;
}