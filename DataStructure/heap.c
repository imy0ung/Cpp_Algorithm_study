#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma warning (disable : 4996)
// heap_sort

int heap[1001];
int sz = 0;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1) {
		int par = idx / 2;
		if (heap[par] <= heap[idx]) break;
		swap(&heap[par], &heap[idx]);
		idx = par;
	}
}

int top() {
	return heap[1];
}

void pop() {
	heap[1] = heap[sz--];
	int idx = 1;

	while (2 * idx <= sz) {
		int lc = 2 * idx; int rc = 2 * idx + 1;
		int min_child = lc;
		if (rc <= sz && heap[rc] < heap[lc])
			min_child = rc;
		if (heap[idx] < heap[min_child]) break;
		swap(&heap[min_child], &heap[idx]);
		idx = min_child;
	}
}

int main(void) {
	int n = 10;
	while (n--) {
		int x;
		scanf("%d", &x); push(x);
	}
	
	for (int i = 1; i <= 10; i++)
		printf("%d ", heap[i]);
	printf("\n");
	for (int i = 1; i <= 10; i++) {
		printf("%d ", top());
		pop(); 
	}
}