// node index numbered from 1 to N
// using only their degrees to judge
// 必须判断是否为连通图
#include<iostream>
#include<vector>
using namespace std;
int N, M, p, q, odd, cnt;
vector<int> adj[510];
vector<bool> v(500);
void dfs(int cur) {
	v[cur] = true;
	cnt++;
	for (int a : adj[cur])
		if (!v[a]) dfs(a);
}
int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> p >> q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	for (int i = 1;i < N;i++) {
		cout << adj[i].size() << ' ';
	}
	cout << adj[N].size() << endl;
	dfs(1);
	if (cnt != N) {
		cout << "Non-Eulerian";
	}
	else {
		odd = 0;
		for (int i = 1;i <= N;i++) {
			if (adj[i].size() % 2) odd++;
		}
		if (odd == 0)cout << "Eulerian";
		else if (odd == 2)cout << "Semi-Eulerian";
		else cout << "Non-Eulerian";
	}

	return 0;
}