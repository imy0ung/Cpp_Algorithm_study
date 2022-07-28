#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]); // 뿌리노드까지 가는 개념
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a; // 두 노드의 부모 중 가장 작은 값이 부모
	else parent[a] = b;
} // 노드를 연결해주는 알고리즘

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
} // 같은 부모를 갖는지 확인하는 알고리즘

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
}