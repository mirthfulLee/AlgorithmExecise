//
// Created by Ä¾×ÓÓÖÇ· on 2021/3/30.
//

#include<iostream>
#include<queue>
using namespace std;
struct BinNode
{
	int value;
	BinNode* left, * right;
	BinNode(int v) :value(v), left(NULL), right(NULL) {}
};
int N, pre[40], post[40];
BinNode* root;
queue<int> in;
bool isUnique = true;

void traverse(BinNode* root, int preLeft, int preRight, int postLeft, int postRight) {
	if (preLeft > preRight) return;
	if (pre[preLeft] == post[postRight]) {
		isUnique = false;
		BinNode* r = new BinNode(post[postRight]);
		root->right = r;
		traverse(r, preLeft + 1, preRight, postLeft, postRight - 1);
		return;
	}
	int p = preLeft + 1, q = postRight - 1;
	BinNode* l = new BinNode(pre[preLeft]);
	BinNode* r = new BinNode(post[postRight]);

	root->left = l;
	root->right = r;

	while (pre[p] != post[postRight])p++;
	while (post[q] != pre[preLeft]) q--;

	traverse(l, preLeft + 1, p - 1, postLeft, q - 1);
	traverse(r, p + 1, preRight, q + 1, postRight - 1);
}

void getInorder(BinNode* x) {
	if (x == NULL) return;
	getInorder(x->left);
	in.push(x->value);
	getInorder(x->right);
}

int main() {
	root = (BinNode*)malloc(sizeof(BinNode));
	cin >> N;
	for (int i = 0;i < N;i++) cin >> pre[i];
	for (int i = 0;i < N;i++) cin >> post[i];
	root->value = pre[0];
	traverse(root, 1, N - 1, 0, N - 2);
	getInorder(root);

	printf("%s\n%d", isUnique ? "Yes" : "No", in.front());
	in.pop();
	while (!in.empty()) {
		printf(" %d", in.front());
		in.pop();
	}
	printf("\n");
	return 0;
}

