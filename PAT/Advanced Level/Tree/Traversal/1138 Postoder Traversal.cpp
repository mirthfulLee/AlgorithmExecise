//
// Created by Ä¾×ÓÓÖÇ· on 2021/3/26.
//
#include<iostream>
using namespace std;
int pre[50009], in[50009], N;

int pos(int x, int p, int q) {
	for (int i = p;i <= q;i++) {
		if (x == in[i]) return i;
	}
	return -1;
}
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0;i < N;i++) {
		scanf("%d", &in[i]);
	}
	int i = 0, p = 0, q = N - 1, t;
	while (p < q) {
		t = pos(pre[i], p, q);
		if (p < t) {
			q = t - 1;
		}
		else {
			p = t + 1;
		}
		i++;
	}
	printf("%d", in[p]);

	return 0;
}