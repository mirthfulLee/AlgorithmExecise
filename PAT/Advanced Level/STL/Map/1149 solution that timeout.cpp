//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/15.
//
#include<iostream>
#include<set>
#include<map>
using namespace std;

map<int, set<int>> m;
int g[1000];
int N, M, a, b, k;

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		scanf("%d %d", &a, &b);
		m[a].insert(b);
		m[b].insert(a);
	}
	for (int t = 0;t < M;t++) {
		cin >> k;
		bool legal = true;
		for (int i = 0;i < k;i++) {
			scanf("%d", &g[i]);
		}
		// the following nested loop is O(k^2) 
		// (neglecting the time of set.find operation which is O(log K) )
		// the worse thing is that there are M cases, 
		// which means the time complexity is O(M*k*k)!
		// so that there is one sample result timeout.
		for (int i = 0;i < k;i++) {
			if (legal) {
				for (int j = 0;j < i;j++) {
					if (m[g[i]].find(g[j]) != m[g[i]].end()) {
						legal = false;
						break;
					}
				}
			}
			else break;
		}
		if (legal) printf("Yes\n");
		else printf("No\n");
	}
}
