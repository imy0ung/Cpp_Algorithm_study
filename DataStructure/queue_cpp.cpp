#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#pragma warning (disable : 4996)

using namespace std;

const int MX = 100001;
int dat[MX];
int front = 0;
int rear = 0;
 
void push(int x) {
	dat[rear++] = x;
	if (rear >= MX)
		rear = 0;
}

void pop() {
	front++;
	if (front >= MX)
		front = 0;
}

int fronter() {
	return dat[front];
}

int rearer() {
	return dat[rear - 1];
}

bool empty() {
	return front == rear;
}

bool full() {
	return ((rear + 1) % MX == front);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	push(10);
	push(20);
	push(30);
	push(40);
	pop();
	pop();

	for (int i = front; i < rear; i++)
		cout << dat[i] << '\n';
}