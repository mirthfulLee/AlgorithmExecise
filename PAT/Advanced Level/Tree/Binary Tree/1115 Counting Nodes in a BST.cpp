//
// Created by Ä¾×ÓÓÖÇ· on 2021/3/31.
//

#include<iostream>

using namespace std;

struct BinNode
{
	int value;
	BinNode* left, * right;
	BinNode(int v) :value(v), left(NULL), right(NULL) {}
};

int N, input[1009], cnt[1009], depth;
BinNode* root;

BinNode* build(BinNode* root, int v) {
	if (root == NULL) {
		return new BinNode(v);
	}
	else {
		if (v <= root->value) {
			root->left = build(root->left, v);
		}
		else {
			root->right = build(root->right, v);
		}
	}
	return root;
}

void dfs(BinNode* cur, int level) {
	if (cur == NULL) return;
	if (level > depth) depth = level;
	cnt[level]++;
	dfs(cur->left, level + 1);
	dfs(cur->right, level + 1);
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) cin >> input[i];
	root = new BinNode(input[0]);
	for (int i = 1;i < N;i++) build(root, input[i]);
	dfs(root, 1);
	printf("%d + %d = %d", cnt[depth], cnt[depth - 1],
		cnt[depth] + cnt[depth - 1]);
	return 0;
}
