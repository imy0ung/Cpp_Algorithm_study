#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#pragma warning (disable : 4996)

//Merge_Sort
//O(N * logN)�� �ð����⵵
//�ϴ� ������ �ɰ��� ���߿� ��ġ��

using namespace std;

int number = 8;
int sorted[8]; // ���� �迭�� ������ ���������� �ؾ���

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	// ���� ������� �迭�� ����
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// ���� ������ ����

	if (i > middle) { //i�� ���� ������, ���� j ����
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else { // j�� ���� ������, ���� i ����
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	if (m < n) { // ũ�Ⱑ 1���� ū ���
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
} // ��ġ�� 

int main(void) {
	int arr[] = { 7,6,5,8,3,4,9,1 };
	mergeSort(arr, 0, number - 1);
	for (int i = 0; i < number; i++)
		cout << arr[i] << ' ';
}