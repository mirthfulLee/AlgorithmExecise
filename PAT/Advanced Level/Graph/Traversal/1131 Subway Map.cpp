#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N, M, K, temp, sour, dest, minLen, minTime;
vector<int> pre(10000), singleLine, bestPath, curPath(10000);
map<int, map<int, int>> adj;
vector<bool> v(10000);
void dfs(int cur, int curLen, int curLine, int transferTime) {
	curPath[curLen] = cur;
	if (cur == dest) {
		if (curLen < minLen || (curLen == minLen && transferTime < minTime)) {
			minLen = curLen;
			minTime = transferTime;
			bestPath = curPath;
		}
		return;
	}
	if (curLen >= minLen) return;
	v[cur] = true;
	for (auto it : adj[cur]) {
		if (!v[it.first]) {
			dfs(it.first, curLen + 1, it.second, curLine == it.second ? transferTime : transferTime + 1);
		}
	}
	v[cur] = false;
}
int main() {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &M);
		singleLine.assign(M, 0);
		for (int j = 0;j < M;j++) {
			scanf("%d", &singleLine[j]);
		}
		for (int j = 1;j < M;j++) {
			adj[singleLine[j - 1]][singleLine[j]] = i;
			adj[singleLine[j]][singleLine[j - 1]] = i;
		}
	}
	scanf("%d", &K);
	for (int t = 0;t < K;t++) {
		scanf("%d %d", &sour, &dest);
		minLen = 9999999;
		minTime = 9999999;
		curPath[0] = sour;
		for (auto it : adj[sour]) {
			dfs(it.first, 1, it.second, 0);
		}
		printf("%d\n", minLen);
		int l = 0, r = 1, curLine;
		while (l < minLen) {
			curLine = adj[bestPath[l]][bestPath[l + 1]];
			while (r < minLen && adj[bestPath[r]][bestPath[r + 1]] == curLine)
				r++;
			printf("Take Line#%d from %04d to %04d.\n", curLine, bestPath[l], bestPath[r]);
			l = r; r = l + 1;
		}
	}
	return 0;
}