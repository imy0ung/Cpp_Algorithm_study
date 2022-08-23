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
	int pivot = arr[st]; // pivot ���� ����
	int l = st + 1; // ����
	int r = en; // ������
	while (1) {
		while (l <= r && arr[l] <= pivot) l++; // �����ɶ����� ����
		while (l <= r && arr[r] >= pivot) r--; // �����ɶ����� ����
		if (l > r) break; // �����Ǹ� ����
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]); // ������ ���� ���Ұ� ��ü
	quick_sort(st, r); // ����Ʈ ���1
	quick_sort(r + 1, en); // ����Ʈ ���2
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	quick_sort(0, 7); // ����Ʈ ����
	for (int i = 0; i < 8; i++)
		cout << arr[i] << ' ';
}