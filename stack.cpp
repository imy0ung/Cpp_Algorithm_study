#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#pragma warning (disable : 4996)

//counting sort
//���� ������ �־����� ��, ���� ���� �˰���
using namespace std;

int main(void) {
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}