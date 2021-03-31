//
// Created by Ä¾×ÓÓÖÇ· on 2021/3/31.
//

#include<iostream>
#include<queue>
using namespace std;

int N, pre[40], post[40];
queue<int> in;
bool isUnique = true;

void traverse(int preLeft, int preRight, int postLeft, int postRight) {
	if (preLeft == preRight) {
		in.push(pre[preLeft]);
		return;
	}

	if (pre[preLeft + 1] == post[postRight - 1]) {
		isUnique = false;
		in.push(pre[preLeft]);
		traverse(preLeft + 1, preRight, postLeft, postRight - 1);
		return;
	}
	int i = preLeft;
	while (pre[i] != post[postRight - 1]) i++;
	traverse(preLeft + 1, i - 1, postLeft, postLeft + i - preLeft - 2);
	in.push(pre[preLeft]);
	traverse(i, preRight, postRight - preRight + i - 1, postRight - 1);
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) cin >> pre[i];
	for (int i = 0;i < N;i++) cin >> post[i];
	traverse(0, N - 1, 0, N - 1);

	printf("%s\n%d", isUnique ? "Yes" : "No", in.front());
	in.pop();
	while (!in.empty()) {
		printf(" %d", in.front());
		in.pop();
	}
	printf("\n");
	return 0;
}

