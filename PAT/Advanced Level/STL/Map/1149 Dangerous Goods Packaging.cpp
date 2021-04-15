//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/15.
//
#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, vector<int>> m;
int N, M, a, b, k;

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		scanf("%d %d", &a, &b);
		m[a].push_back(b);
		m[b].push_back(a);
	}
	for (int t = 0;t < M;t++) {
		cin >> k;
		vector<int> g(k);
		vector<int> p(100000, 0);
		bool legal = true;
		for (int i = 0;i < k;i++) {
			scanf("%d", &g[i]);
			p[g[i]] = 1;
		}
		for (int i = 0;i < k;i++) {
			for (auto t : m[g[i]]) {
				if (p[t]) {
					legal = false;
					break;
				}
			}
			if (!legal) break;
		}
		printf("%s\n", legal ? "Yes" : "No");
	}
}
