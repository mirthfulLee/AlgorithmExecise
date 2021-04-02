//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/2.
//
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct BinNode {
	int value, l, r;
};

BinNode node[110];
int N, root, input[110], index;
vector<int> levelTra;

void bfs(int root) {
	queue<int> q;
	q.push(root);
	int cur;
	while (q.size()) {
		cur = q.front(); q.pop();
		if (node[cur].l != -1) q.push(node[cur].l);
		levelTra.push_back(node[cur].value);
		if (node[cur].r != -1) q.push(node[cur].r);
	}
}

void dfs(int cur) {
	if (node[cur].l != -1) dfs(node[cur].l);
	node[cur].value = input[index++];
	if (node[cur].r != -1) dfs(node[cur].r);
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> node[i].l >> node[i].r;
	}
	for (int i = 0;i < N;i++) {
		cin >> input[i];
	}
	sort(input, input + N);
	dfs(0);
	bfs(0);
	printf("%d", levelTra[0]);
	for (int i = 1;i < N;i++) {
		printf(" %d", levelTra[i]);
	}
}
