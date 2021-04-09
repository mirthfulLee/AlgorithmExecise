//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/9.
//
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Node
{
	vector<int> kids;
};

int N, temp, root, maxLevel, cnt;
double P, r;
Node tree[100100];
void dfs(int cur, int curLevel) {
	if (curLevel > maxLevel) {
		maxLevel = curLevel;
		cnt = 1;
	}
	else if (curLevel == maxLevel) {
		cnt++;
	}
	for (auto kid : tree[cur].kids) {
		dfs(kid, curLevel + 1);
	}
}

int main() {
	cin >> N >> P >> r;
	r = (100 + r) / 100;
	for (int i = 0;i < N;i++) {
		scanf("%d", &temp);
		if (temp == -1) {
			root = i;
		}
		else {
			tree[temp].kids.push_back(i);
		}
	}
	dfs(root, 0);
	printf("%.2f %d", pow(r, maxLevel) * P, cnt);
}