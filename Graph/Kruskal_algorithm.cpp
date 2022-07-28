#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

//Kruskal Algorithm
//가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
} // 부모 노드를 찾아주는 함수

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
} // 노드끼리 연결해주는 함수

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}
// union_find 알고리즘에서, 연결되어있는지 확인하는 함수인데,
// 크루스칼 알고리즘에서는, 이 함수를 cycle를 방지하는 함수로 사용한다.

// 간산 클래스 선언

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main(void) {
	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end()); // 최소 거리를 찾기 위해 정렬

	int parent[7];
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			// 이미 부모가 같은거면 건너떠주는 느낌(cycle 방지)
			sum += v[i].distance; // 만약 부모가 같지않다면,
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
			// 연결해준다.
		}
	}

	printf("%d\n", sum);
}