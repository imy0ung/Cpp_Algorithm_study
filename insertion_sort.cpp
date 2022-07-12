#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#pragma warning (disable : 4996)

using namespace std;

// 필요할 때만, 위치를 바꿔주면 어떨까?
// 차례차레 정렬하면서 정렬하는 알고리즘
// 순차적으로 삽입
// 만약 정렬이 되어있다면 뛰어난 알고리즘

int main(void) {
	int i, j, temp;
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 10; i++) {
		j = i;
		while (j > 0 && arr[j] > arr[j - 1]) {
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}

	for (int i = 0; i < 10; i++) {
		pritnf("%d ", arr[i]);
	}
} // insertion sort