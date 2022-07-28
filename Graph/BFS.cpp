#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

//BFS(Breadth First Search)
//너비를 우선으로 
//1부터 거리가 가장 가까운 거 부터 탐색하는 알고리즘

/*
* 큐에서 하나의 노드를 꺼내고,
* 해당 노드에 연결된 노드 중 방문하지 않은 노드를 방문하고 큐에 삽입
*/

using namespace std;

int number = 7;
int c[7]; // checked 
vector<int> a[8];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!c[y]) { // 방문처리가 안된거라면, 방문처리해주고 push
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);
	return 0;
}
