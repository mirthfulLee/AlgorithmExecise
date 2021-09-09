// Vetices numbered from 1 to N
#include<iostream>
#include<algorithm>
using namespace std;

// 数组a开小了最后一个点会报答案错误, 误导!
int N, M, K, p, q, num, a[2000];
bool adj[250][250], v[250];
bool isHamiltonian() {
	if (num != N + 1) return false;
	for (int i = 1;i < num;i++) {
		if (!adj[a[i - 1]][a[i]]) return false;
	}
	for (int i = 1;i <= N;i++) {
		if (!v[i]) return false;
	}
	return a[0] == a[N];
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> p >> q;
		adj[p][q] = adj[q][p] = true;
	}
	cin >> K;
	for (int t = 0;t < K;t++) {
		cin >> num;
		fill(v, v + 250, false);
		for (int i = 0;i < num;i++) {
			cin >> a[i];
			v[a[i]] = true;
		}
		if (isHamiltonian())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}