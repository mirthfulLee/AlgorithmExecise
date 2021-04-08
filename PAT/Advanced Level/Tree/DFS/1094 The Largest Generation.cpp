//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/8.
//
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	vector<int> kids;
};

int N, M, k, cur, tmp, cnt[110], largest;
Node tree[100];

void dfs(int cur, int curLevel) {
	cnt[curLevel]++;
	if (tree[cur].kids.size() == 0) {
		return;
	}
	for (auto kid : tree[cur].kids) dfs(kid, curLevel + 1);
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> cur >> k;
		for (int j = 0;j < k;j++) {
			cin >> tmp;
			tree[cur].kids.push_back(tmp);
		}
	}
	dfs(1, 1);
	largest = 1;
	for (int i = 2;i < 110;i++) {
		if (cnt[i] > cnt[largest]) largest = i;
	}
	printf("%d %d", cnt[largest], largest);
}