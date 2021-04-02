//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/2.
//
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct BinNode {
	int l, r;
};

BinNode node[100];
int N, last, root, inDegree[100];
vector<int> in, levelTra;
string a, b;

void inverted_dfs(int x) {
	if (node[x].r != -1) inverted_dfs(node[x].r);
	in.push_back(x);
	if (node[x].l != -1) inverted_dfs(node[x].l);
}

void inverted_bfs(int root) {
	queue<int> q;
	q.push(root);
	int cur;
	while (q.size()) {
		cur = q.front(); q.pop();
		if (node[cur].r != -1) q.push(node[cur].r);
		levelTra.push_back(cur);
		if (node[cur].l != -1) q.push(node[cur].l);
	}
}
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> a >> b;
		if (a == "-") node[i].l = -1;
		else {
			node[i].l = stoi(a);
			inDegree[node[i].l] = 1;
		}
		if (b == "-") node[i].r = -1;
		else {
			node[i].r = stoi(b);
			inDegree[node[i].r] = 1;
		}
	}
	while (inDegree[root]) root++;
	inverted_bfs(root);
	cout << levelTra[0];
	for (int i = 1;i < N;i++) {
		printf(" %d", levelTra[i]);
	}
	printf("\n");

	inverted_dfs(root);
	cout << in[0];
	for (int i = 1;i < N;i++) {
		printf(" %d", in[i]);
	}
}
