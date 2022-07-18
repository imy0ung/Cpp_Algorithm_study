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
	// 먼저 전체 트리 구조를 최대 힙 구조로 만들어 주자.
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2; // 자기 자신 부모의 노드
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	// 크기를 줄여가며 반복적으로 힙을 구성

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	} // 배열을 힙정렬로 만들기 n * log n

	printf("\n");

	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0]; // 가장 큰 값을 맨 뒤로 보내주기
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1; // 자식 중에 더 큰 값 찾기

			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}

			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i); // 단말 노드를 만날때까지
	}

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}