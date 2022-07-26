#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#pragma warning (disable : 4996)

//counting sort
//���� ������ �־����� ��, ���� ���� �˰���
using namespace std;

int main(void) {
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();

	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}