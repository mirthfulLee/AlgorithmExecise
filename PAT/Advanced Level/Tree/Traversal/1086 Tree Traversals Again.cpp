//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/9.
//
#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int N, temp;
stack<int> s;
string operation;
vector<int> post, in, pre;

void traverse(int preLeft, int preRight, int inLeft, int inRight) {
	if (preLeft > preRight) {
		return;
	}
	int p = inLeft;
	while (in[p] != pre[preLeft]) p++;
	traverse(preLeft + 1, preLeft + p - inLeft, inLeft, p - 1);
	traverse(preRight - inRight + p + 1, preRight, p + 1, inRight);
	post.push_back(pre[preLeft]);
}

int main() {
	cin >> N;
	for (int i = 0;i < 2 * N;i++) {
		cin >> operation;
		if (operation == "Push") {
			cin >> temp;
			s.push(temp);
			pre.push_back(temp);
		}
		else {
			in.push_back(s.top());
			s.pop();
		}
	}
	traverse(0, N - 1, 0, N - 1);
	printf("%d", post[0]);
	for (int i = 1;i < N;i++) {
		printf(" %d", post[i]);
	}
}