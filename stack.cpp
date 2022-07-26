#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#pragma warning (disable : 4996)

//counting sort
//숫자 범위가 주어졌을 때, 가장 빠른 알고리즘
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