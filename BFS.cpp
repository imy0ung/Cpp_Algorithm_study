#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

//BFS(Breadth First Search)
//�ʺ� �켱���� 
//1���� �Ÿ��� ���� ����� �� ���� Ž���ϴ� �˰���

/*
* ť���� �ϳ��� ��带 ������,
* �ش� ��忡 ����� ��� �� �湮���� ���� ��带 �湮�ϰ� ť�� ����
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
			if (!c[y]) { // �湮ó���� �ȵȰŶ��, �湮ó�����ְ� push
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