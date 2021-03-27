//
// Created by д╬вссжг╥ on 2021/3/26.
//
#include<iostream>
#include<vector>
using namespace std;

int N, a[1000], type, path[1000];
void traversal(int x, int t) {
	path[x] = a[t];
	if (2 * t + 1 >= N) {
		for (int i = 0;i < x;i++)
			printf("%d ", path[i]);
		printf("%d\n", path[x]);
	}
	else if (2 * t + 2 < N) {
		traversal(x + 1, 2 * t + 2);
		traversal(x + 1, 2 * t + 1);
	}
	else {
		traversal(x + 1, 2 * t + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) cin >> a[i];
	// 1:max heap   -1:min heap  0:not heap
	if (a[0] > a[1]) type = 1;
	else type = -1;
	for (int i = N - 1;i >= 1;i--)
		if ((type == 1 && a[i] > a[(i - 1) / 2]) ||
			(type == -1 && a[i] < a[(i - 1) / 2])) {
			type = 0;
			break;
		}
	traversal(0, 0);
	printf("%s", type == 1 ? "Max Heap" : (type == -1 ? "Min Heap" : "Not Heap"));
	return 0;
}