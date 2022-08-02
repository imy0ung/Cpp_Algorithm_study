#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;
#define X first
#define Y second
string board[102];
int dist[102][102];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0 ,1 ,0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1); // visit ��� dist�� ����ؼ� �Ÿ�����
	queue<pair<int, int>> Q; // �������� bfs ����
	Q.push({ 0,0 }); // ������ �ְ�
	dist[0][0] = 0; // dist �ʰ� �� �ϰ�!
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop(); // auto�� �ڵ� ����ȯ ���
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir]; // ������ �̵�����
			int ny = cur.Y + dy[dir]; // ���� �̵�����
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // ���� �ʰ� ����ְ�
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; // 0�� ���̰ų� �̹� �湮�� ��忡 ������ ����
			dist[nx][ny] = dist[cur.X][cur.Y] + 1; // �Ÿ�����..
			Q.push({ nx,ny }); // �� �ٽ� �־��ְ�
		}
	}
	cout << dist[n - 1][m - 1] + 1; // ������ Ư���� �Ÿ� + 1�� ����
}