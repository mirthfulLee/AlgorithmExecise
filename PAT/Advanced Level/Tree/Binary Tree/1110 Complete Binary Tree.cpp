//
// Created by Ä¾×ÓÓÖÇ· on 2021/3/31.
//
#include<iostream>
#include<string>
using namespace std;

struct BinNode {
	int l, r;
};

BinNode node[100];
int N, last, root, inDegree[100];
bool isCBT = true;
string a, b;

void dfs(int x, int index) {
	if (index == N) last = x;
	if (index > N) isCBT = false;

	if (node[x].l != -1) dfs(node[x].l, 2 * index);
	if (node[x].r != -1) dfs(node[x].r, 2 * index + 1);
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
	dfs(root, 1);
	if (isCBT) printf("YES %d", last);
	else printf("NO %d", root);
}
