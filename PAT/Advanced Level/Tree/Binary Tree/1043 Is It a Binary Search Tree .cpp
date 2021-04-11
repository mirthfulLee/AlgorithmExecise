//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/11.
//

#include <iostream>
#include<vector>
using namespace std;

bool isMirror = false;
int N;
vector<int> pre, post;

void getPost(int root, int tail) {
	if (root > tail) return;
	int i = root + 1, j = tail;
	if (!isMirror) {
		while (i <= tail && pre[root] > pre[i]) i++;
		while (j > root && pre[root] <= pre[j]) j--;
	}
	else {
		while (i <= tail && pre[root] <= pre[i]) i++;
		while (j > root && pre[root] > pre[j]) j--;
	}
	if (i - j != 1) return;
	getPost(root + 1, j);
	getPost(i, tail);
	post.push_back(pre[root]);
}


int main() {
	cin >> N;
	pre.resize(N);
	for (int i = 0;i < N;i++) cin >> pre[i];
	getPost(0, N - 1);
	if (post.size() != N) {
		isMirror = true;
		post.clear();
		getPost(0, N - 1);
	}
	if (post.size() == N) {
		printf("YES\n%d", post[0]);
		for (int i = 1;i < post.size();i++) {
			printf(" %d", post[i]);
		}
	}
	else {
		printf("NO");
	}
}