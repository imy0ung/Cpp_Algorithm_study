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
int arr[8] = { 6,-8,1,12,8,3,7,-7 };

void quick_sort(int st, int en) {
	if (en <= st+1) return;
	int pivot = arr[st]; // pivot 값은 자유
	int l = st + 1; // 왼쪽
	int r = en; // 오른쪽
	while (1) {
		while (l <= r && arr[l] <= pivot) l++; // 교차될때까지 증가
		while (l <= r && arr[r] >= pivot) r--; // 교차될때까지 감소
		if (l > r) break; // 교차되면 종료
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]); // 교차된 값과 스왑값 교체
	quick_sort(st, r); // 퀵솔트 재귀1
	quick_sort(r + 1, en); // 퀵솔트 재귀2
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	quick_sort(0, 7); // 퀵소트 과정
	for (int i = 0; i < 8; i++)
		cout << arr[i] << ' ';
}