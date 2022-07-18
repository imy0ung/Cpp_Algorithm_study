#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable : 4996)

using namespace std;

int arr[10001];
int number;

void heapify(int i) {
	int c = 2 * i + 1;

	if (arr[c] < arr[c + 1] && c < number) {
		c++;
	}

	if (arr[i] < arr[c]) {
		int temp = arr[i];
		arr[i] = arr[c];
		arr[c] = temp;
	}

	if (c <= number / 2)
		heapify(c);
}

int main(void) {
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> arr[i];
	}

	for (int i = number/2; i >= 0; i--) {
		heapify(i);
	} // heapify

	for (int i = 0; i < number; i++)
		cout << arr[i] << ' ';
	printf("\n");

	for (int i = number - 1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		// 가장 큰 값을 맨 뒤로 계속 보내주기
		int root = 0;
		int child = 1;
		do {
			child = 2 * root + 1;
			// 자식 중에 더 큰 값을 찾기
			if (arr[child] < arr[child + 1] && child < i - 1) {
				child++;
			}

			if (arr[root] < arr[child] && child < i) {
				temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			root = child;
		} while (child < i);
	}
}