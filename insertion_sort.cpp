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

// �ʿ��� ����, ��ġ�� �ٲ��ָ� ���?
// �������� �����ϸ鼭 �����ϴ� �˰���
// ���������� ����
// ���� ������ �Ǿ��ִٸ� �پ �˰���

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