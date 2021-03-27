#include<iostream>
using namespace std;

// method1: build tree, then print each level within the rule
// method2: record the level of each node in inorder
// try to use method2
int post[40], in[40], level[40], maxLevel, N, l, r, p, q, tmp;
int pos(int x) {
	for (int i = 0;i < N;i++)
		if (in[i] == x) return i;
	return 0;
}
void traverse(int l, int r, int p, int q) {
	if (l > r) return;
	for (int i = l;i <= r;i++) level[i]++;
	if (level[l] > maxLevel) maxLevel = level[l];
	int t = pos(post[q]);
	traverse(l, t - 1, p, p + t - l - 1);
	traverse(t + 1, r, q - r + t, q - 1);
}
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) scanf("%d", &in[i]);
	for (int i = 0;i < N;i++) scanf("%d", &post[i]);
	l = 0;r = N - 1;p = 0;q = N - 1;
	traverse(l, r, p, q);
	printf("%d", post[N - 1]);
	for (int i = 2;i <= maxLevel;i++)
		if (i % 2) {
			for (int j = N - 1;j >= 0;j--) {
				if (level[j] == i) printf(" %d", in[j]);
			}
		}
		else {
			for (int j = 0;j < N;j++) {
				if (level[j] == i) printf(" %d", in[j]);
			}
		}
}