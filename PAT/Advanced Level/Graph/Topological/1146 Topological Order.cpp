#include<iostream>
#include<vector>
using namespace std;

vector<int> e[1010], indegree(1010), cur, ans, order(1010);
int N, M, K, p, q;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0;i < M;i++) {
		scanf("%d %d", &p, &q);
		e[p].push_back(q);
		indegree[q]++;
	}
	scanf("%d", &K);
	for (int i = 0;i < K;i++) {
		cur = indegree;
		for (int j = 0;j < N;j++) scanf("%d", &order[j]);
		for (int j = 0;j < N;j++) {
			if (cur[order[j]] > 0) {
				ans.push_back(i);
				break;
			}
			for (int t : e[order[j]]) cur[t]--;
		}
	}
	for (int i = 0;i < ans.size() - 1;i++) cout << ans[i] << ' ';
	cout << ans[ans.size() - 1];
	return 0;
}