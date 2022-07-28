#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

//Kruskal Algorithm
//���� ���� ������� ��� ��带 �����ϱ� ���� ����ϴ� �˰���

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
} // �θ� ��带 ã���ִ� �Լ�

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
} // ��峢�� �������ִ� �Լ�

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}
// union_find �˰��򿡼�, ����Ǿ��ִ��� Ȯ���ϴ� �Լ��ε�,
// ũ�罺Į �˰��򿡼���, �� �Լ��� cycle�� �����ϴ� �Լ��� ����Ѵ�.

// ���� Ŭ���� ����

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

	sort(v.begin(), v.end()); // �ּ� �Ÿ��� ã�� ���� ����

	int parent[7];
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			// �̹� �θ� �����Ÿ� �ǳʶ��ִ� ����(cycle ����)
			sum += v[i].distance; // ���� �θ� �����ʴٸ�,
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
			// �������ش�.
		}
	}

	printf("%d\n", sum);
}