#include <iostream>
#include <algorithm>

using namespace std;

// O(N*logN)�� ������ ������
// "Ư���� ���� �������� ū ���ڿ� ���� ���ڸ� ������ ���?"
// ��������

int number = 10;
int arr[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quicksort(int *data, int start, int end) {
	if (start >= end) {
		return;
	} // �ϳ��� ������ �� �Լ� ����

	int pivot = start; // pivot �� ����
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && data[pivot] >= data[i]) {
			i++;
		} // ���������� �̵��ϸ鼭 pivot���� ū���� ã��

		while (j > start && data[pivot] <= data[j]) {
			j--;
		} // �������� �̵��ϸ鼭 pivot���� ������ ã��
		// j > start �� �ָ�, pivot���� �߿����� ���ϰ� �ؾ���

		if (i > j) {
			temp = data[pivot];
			data[pivot] = data[j];
			data[j] = temp;
		} // ������ ��� pivot�� �ٲ��ֱ�
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		} // �������� ���� ��� 

		// ��͸� �̿��ؼ�, j�� �������� ���� ���������� ����
		quicksort(data, start, j - 1); //
		quicksort(data, j + 1, end);
	} // ������������ �ݺ�
}

int main(void) {
	quicksort(arr, 0, number - 1);
	for (int i = 0; i < number - 1; i++)
		printf("%d ", arr[i]);
}