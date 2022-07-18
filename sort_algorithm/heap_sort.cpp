#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable : 4996)

//heap sorting
//heapify algorithm
using namespace std;

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	// ���� ��ü Ʈ�� ������ �ִ� �� ������ ����� ����.
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2; // �ڱ� �ڽ� �θ��� ���
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	// ũ�⸦ �ٿ����� �ݺ������� ���� ����

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	} // �迭�� �����ķ� ����� n * log n

	printf("\n");

	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0]; // ���� ū ���� �� �ڷ� �����ֱ�
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1; // �ڽ� �߿� �� ū �� ã��

			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}

			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i); // �ܸ� ��带 ����������
	}

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}