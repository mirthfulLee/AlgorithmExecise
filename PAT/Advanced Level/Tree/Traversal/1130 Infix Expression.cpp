// node index from 1-N
// 加入括号表示优先级：
// 除了root外的运算符节点（除了叶子节点和根节点），遍历左子树之前输出（， 遍历右子树之后输出）
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node
{
	string data;
	int left, right, indegree;
};
// 用是否为叶子结点来判断更好
bool isOperator(string s) {
	vector<string> operators = { "*","+","-","/","%","&","^" };
	for (string o : operators) if (s == o) return true;
	return false;
}

node treeNode[30];
int N, root;
void printInfix(int cur) {
	if (cur < 0) return;
	if (isOperator(treeNode[cur].data)) {
		cout << '(';
		printInfix(treeNode[cur].left);
		cout << treeNode[cur].data;
		printInfix(treeNode[cur].right);
		cout << ')';
	}
	else {
		cout << treeNode[cur].data;
	}
}
int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> treeNode[i].data >> treeNode[i].left >> treeNode[i].right;
		if (treeNode[i].left > 0)
			treeNode[treeNode[i].left].indegree++;
		if (treeNode[i].right > 0)
			treeNode[treeNode[i].right].indegree++;
	}

	for (int i = 1;i <= N;i++) {
		if (treeNode[i].indegree == 0) root = i;
	}
	printInfix(treeNode[root].left);
	cout << treeNode[root].data;
	printInfix(treeNode[root].right);
	return 0;
}
