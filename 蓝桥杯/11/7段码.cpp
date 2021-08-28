//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/17.
//
#include<iostream>
#include<vector>
using namespace std;
vector<int> v[7] = { {1,2},{0,3,4},{0,3,5},{1,2,4,5},{1,3,6},{2,3,6},{4,5} }, s;
bool adj[7][7], open[7];
int total = 0;
int find(int x) { while (x != s[x]) x = s[x];	return x; }
void check() {
	s = { 0,1,2,3,4,5,6 };
	for (int i = 0;i < 7;i++) {
		if (open[i]) {
			int s1 = find(i);
			for (int j = i + 1;j < 7;j++) {
				if (open[j]) {
					if (adj[i][j]) {
						int s2 = find(j);
						s1 < s2 ? s[s2] = s[s1] : s[s1] = s[s2];
					}
				}
			}
		}
	}
	int t = 0;
	for (int i = 0;i < 7;i++) if (open[i] && s[i] == i) t++;
	if (t == 1) total++;
}
void attempt(int cur) {
	if (cur == 7) {
		check();
		return;
	}
	open[cur] = true;
	attempt(cur + 1);
	open[cur] = false;
	attempt(cur + 1);
}
int main() {
	for (int i = 0;i < 7;i++) {
		for (auto k : v[i]) adj[i][k] = true;
	}
	attempt(0);
	printf("%d", total);
}