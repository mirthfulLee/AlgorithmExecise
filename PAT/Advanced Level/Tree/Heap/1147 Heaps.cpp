//
// Created by Ä¾×ÓÓÖÇ· on 2021/3/26.
//
#include<iostream>
#include<vector>
using namespace std;

int N, M, type, a[1009];
vector<int> path;

void traversal(int index) {
	if (index > N) return;
	traversal(index * 2);
	traversal(index * 2 + 1);
	path.push_back(a[index]);
}

int main() {
	cin >> M >> N;
	for (int p = 0;p < M;p++) {
		for (int i = 1;i <= N;i++) {
			cin >> a[i];
		}
		// type 1-max   -1-min   0-not
		if (a[1] < a[2]) type = -1;
		else type = 1;
		for (int i = 2;i <= N;i++) {
			if ((type == 1 && a[i] > a[i / 2]) ||
				(type == -1 && a[i] < a[i / 2])) {
				type = 0;
				break;
			}
		}
		printf("%s\n", type == 1 ? "Max Heap" :
			(type == 0 ? "Not Heap" : "Min Heap"));
		traversal(1);
		for (int i = 0;i < N - 1;i++) {
			printf("%d ", path[i]);
		}
		printf("%d\n", path[N - 1]);
		path.clear();
	}
	return 0;
}