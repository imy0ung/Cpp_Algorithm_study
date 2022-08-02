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

	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1); // visit 대신 dist를 사용해서 거리측정
	queue<pair<int, int>> Q; // 나머지는 bfs 과정
	Q.push({ 0,0 }); // 시작점 넣고
	dist[0][0] = 0; // dist 초과 꼭 하고!
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop(); // auto는 자동 형변환 기능
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir]; // 행으로 이동할지
			int ny = cur.Y + dy[dir]; // 열로 이동할지
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 초과 잡아주고
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; // 0인 곳이거나 이미 방문한 노드에 못가게 설정
			dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 거리측정..
			Q.push({ nx,ny }); // 또 다시 넣어주고
		}
	}
	cout << dist[n - 1][m - 1] + 1; // 문제의 특성상 거리 + 1이 정답
}