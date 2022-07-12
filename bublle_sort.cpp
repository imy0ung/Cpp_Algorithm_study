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

int main(void) {
	int min, index, temp;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	for (int i = 0; i < 10; i++) {
		min = 9999;
		for (int j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[j] = temp;
	}
} // selection sort