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
//O(N * logN)의 시간복잡도
//일단 반으로 쪼개고 나중에 합치자

using namespace std;

int number = 8;
int sorted[8]; // 정렬 배열은 무조건 전역변수로 해야함

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	// 작은 순서대로 배열에 삽입
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
	// 남은 데이터 삽입

	if (i > middle) { //i가 먼저 끝나면, 남은 j 삽입
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else { // j가 먼저 끝나면, 남음 i 삽입
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
	if (m < n) { // 크기가 1보다 큰 경우
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
} // 합치기 

int main(void) {
	int arr[] = { 7,6,5,8,3,4,9,1 };
	mergeSort(arr, 0, number - 1);
	for (int i = 0; i < number; i++)
		cout << arr[i] << ' ';
}