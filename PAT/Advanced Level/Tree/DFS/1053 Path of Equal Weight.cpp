//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/11.
//

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Node
{
	int weight;
	vector<int> kids;
};

Node tree[100];
int N, M, S, a, k;
string input;
vector<int> cur;

bool cmp(int a, int b) {
	return tree[a].weight > tree[b].weight;
}

void dfs(int curNode, int curLevel, int curSum) {
	if (tree[curNode].kids.size() == 0 && curSum == S) {
		for (int i = 0;i < curLevel;i++) {
			printf("%d ", cur[i]);
		}
		printf("%d\n", cur[curLevel]);
		return;
	}
	else if (curSum > S) return;
	for (auto kid : tree[curNode].kids) {
		cur[curLevel + 1] = tree[kid].weight;
		dfs(kid, curLevel + 1, curSum + tree[kid].weight);
	}
}

int main() {
	cur.resize(100);
	cin >> N >> M >> S;
	for (int i = 0;i < N;i++) {
		cin >> input;
		tree[i].weight = stoi(input);
	}
	for (int i = 0;i < M;i++) {
		cin >> input >> k;
		a = stoi(input);
		for (int j = 0;j < k;j++) {
			cin >> input;
			tree[a].kids.push_back(stoi(input));
		}
		sort(tree[a].kids.begin(), tree[a].kids.end(), cmp);
	}
	cur[0] = tree[0].weight;
	dfs(0, 0, tree[0].weight);
}