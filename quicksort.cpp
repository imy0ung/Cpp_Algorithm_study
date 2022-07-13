#include <iostream>
#include <algorithm>

using namespace std;

// O(N*logN)를 가지는 퀵정렬
// "특정한 값을 기준으로 큰 숫자와 작은 숫자를 나누면 어떨까?"
// 분할정복

int number = 10;
int arr[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quicksort(int *data, int start, int end) {
	if (start >= end) {
		return;
	} // 하나만 남았을 때 함수 종료

	int pivot = start; // pivot 값 설정
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && data[pivot] >= data[i]) {
			i++;
		} // 오른쪽으로 이동하면서 pivot보다 큰수를 찾기

		while (j > start && data[pivot] <= data[j]) {
			j--;
		} // 왼쪽으로 이동하면서 pivot보다 작은수 찾기
		// j > start 의 주목, pivot값을 추월하지 못하게 해야함

		if (i > j) {
			temp = data[pivot];
			data[pivot] = data[j];
			data[j] = temp;
		} // 엇갈릴 경우 pivot를 바꿔주기
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		} // 엇갈리지 않을 경우 

		// 재귀를 이용해서, j를 기준으로 왼쪽 오른쪽으로 정렬
		quicksort(data, start, j - 1); //
		quicksort(data, j + 1, end);
	} // 엇갈릴때까지 반복
}

int main(void) {
	quicksort(arr, 0, number - 1);
	for (int i = 0; i < number - 1; i++)
		printf("%d ", arr[i]);
}