//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/10.
//
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Node
{
	vector<int> kids;
	int num;
};

int N, temp, root, maxLevel, cnt, k;
double P, r, total;
Node tree[100100];
void dfs(int cur, int curLevel) {
	if (tree[cur].kids.size() == 0) {
		total += pow(r, curLevel) * P * tree[cur].num;
	}
	else {
		for (auto kid : tree[cur].kids) {
			dfs(kid, curLevel + 1);
		}
	}
}

int main() {
	cin >> N >> P >> r;
	r = (100 + r) / 100;
	for (int i = 0;i < N;i++) {
		scanf("%d", &k);
		if (k) {
			for (int j = 0;j < k;j++) {
				scanf("%d", &temp);
				tree[i].kids.push_back(temp);
			}
		}
		else {
			scanf("%d", &temp);
			tree[i].num = temp;
		}
	}
	dfs(root, 0);
	printf("%.1f", total);
}