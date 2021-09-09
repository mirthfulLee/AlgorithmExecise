#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> a(N), up(N), lo(N), ans;
	for (int i = 0;i < N;i++) {
		scanf("%d", &a[i]);
	}
	up[0] = a[0];
	for (int i = 1;i < N;i++) {
		up[i] = max(up[i - 1], a[i]);
	}
	lo[N - 1] = a[N - 1];
	for (int i = N - 2;i >= 0;i--) {
		lo[i] = min(lo[i + 1], a[i]);
	}
	for (int i = 0;i < N;i++) {
		if (lo[i] == a[i] && up[i] == a[i]) ans.push_back(a[i]);
	}
	if (ans.size()) {
		printf("%d\n%d", ans.size(), ans[0]);
		for (int i = 1;i < ans.size();i++) {
			printf(" %d", ans[i]);
		}
	}
	else
		// 这里的两个\n是试出来的，很奇怪
		printf("0\n\n");
	return 0;
}