//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/10.
//
#include<iostream>
#include<algorithm>
using namespace std;

int N, input[1010], tree[1010], index = 1;

void dfs(int curNode) {
	if (curNode > N) return;
	dfs(2 * curNode);
	tree[curNode] = input[index++];
	dfs(2 * curNode + 1);
}

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) cin >> input[i];
	sort(input + 1, input + N + 1);
	dfs(1);
	printf("%d", tree[1]);
	for (int i = 2;i <= N;i++)printf(" %d", tree[i]);
}