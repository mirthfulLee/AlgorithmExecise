#include<iostream>
#include<cmath>
using namespace std;

struct node {
	int val;
	node* left, * right;
};

int getHeight(node* root) {
	return root == NULL ? 0 : max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalanceFactor(node* root) {
	return root == NULL ? 0 : getHeight(root->left) - getHeight(root->right);
}
node* rotateLeft(node* root) {
	node* p = root->right;
	root->right = p->left;
	p->left = root;
	return p;
}
node* rotateRight(node* root) {
	node* p = root->left;
	root->left = p->right;
	p->right = root;
	return p;
}
node* rotateLeftRight(node* root) {
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}
node* rotateRightLeft(node* root) {
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}
node* treeBalancing(node* root) {
	int f = getBalanceFactor(root), l = getBalanceFactor(root->left), r = getBalanceFactor(root->right);
	if (abs(f) <= 1) return root;
	if (f > 1)
		root = l > 0 ? rotateRight(root) : rotateLeftRight(root);
	else root = r < 0 ? rotateLeft(root) : rotateRightLeft(root);
	return root;
}
node* insert(node* root, int v) {
	if (root == NULL) {
		root = new node();
		root->val = v;
		root->left = root->right = NULL;
	}
	else if (v < root->val) root->left = insert(root->left, v);
	else root->right = insert(root->right, v);
	return treeBalancing(root);
}
int N, temp;
node* root = NULL;

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		root = insert(root, temp);
	}
	cout << root->val;
}


