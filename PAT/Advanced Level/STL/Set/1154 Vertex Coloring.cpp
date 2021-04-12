//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/12.
//
#include<iostream>
#include<set>
#include<vector>
using namespace std;

struct edge
{
	int v1, v2;
};
int N, M, k;

int main() {
	cin >> N >> M;
	vector<edge> e(M);
	for (int i = 0;i < M;i++) {
		cin >> e[i].v1 >> e[i].v2;
	}
	cin >> k;
	set<int> cnt;
	vector<int> color(N);
	while (k--) {
		bool proper = true;
		for (int i = 0;i < N;i++) {
			scanf("%d", &color[i]);
			cnt.insert(color[i]);
		}
		for (auto pair : e) {
			if (color[pair.v1] == color[pair.v2]) {
				proper = false;
				break;
			}
		}
		if (proper) {
			printf("%d-coloring\n", cnt.size());
		}
		else {
			printf("No\n");
		}
		cnt.clear();
	}
}

