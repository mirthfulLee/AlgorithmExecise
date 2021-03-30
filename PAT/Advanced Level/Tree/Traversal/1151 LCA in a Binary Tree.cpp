//
// Created by Ä¾×ÓÓÖÇ· on 2021/3/30.
//


#include<iostream>
#include<map>
using namespace std;

int N, M, in[10009], pre[10009], U, V, lo, hi;
map<int, int> father, level;

void traverse(int f, int inLeft, int inRight, int preLeft, int preRight) {
	if (inLeft > inRight) return;
	father[pre[preLeft]] = f;
	level[pre[preLeft]] = level.find(f)->second + 1;
	int root = inLeft;
	while (in[root] != pre[preLeft]) root++;
	traverse(pre[preLeft], inLeft, root - 1, preLeft + 1, preLeft + root - inLeft);
	traverse(pre[preLeft], root + 1, inRight, preRight - inRight + root + 1, preRight);
}

int main() {
	cin >> M >> N;
	for (int i = 0;i < N;i++) scanf("%d", &in[i]);
	for (int i = 0;i < N;i++) scanf("%d", &pre[i]);
	father[-10086] = 0; level[-10086] = 0;
	traverse(-10086, 0, N - 1, 0, N - 1);
	for (int i = 0;i < M;i++) {
		cin >> U >> V;
		auto u = level.find(U);
		auto v = level.find(V);
		if (u == level.end()) {
			if (v == level.end()) {
				printf("ERROR: %d and %d are not found.\n", U, V);
				continue;
			}
			else {
				printf("ERROR: %d is not found.\n", U);
				continue;
			}
		}
		else if (v == level.end()) {
			printf("ERROR: %d is not found.\n", V);
			continue;
		}

		if (level.find(U)->second > level.find(V)->second) {
			hi = U; lo = V;
		}
		else {
			lo = U;hi = V;
		}
		while (level.find(lo)->second < level.find(hi)->second) hi = father.find(hi)->second;
		if (lo == hi) {
			if (level.find(U)->second > level.find(V)->second) {
				printf("%d is an ancestor of %d.\n", V, U);
			}
			else {
				printf("%d is an ancestor of %d.\n", U, V);
			}
			continue;
		}
		while (lo != hi) {
			lo = father.find(lo)->second;
			hi = father.find(hi)->second;
		}
		printf("LCA of %d and %d is %d.\n", U, V, lo);
	}
}
