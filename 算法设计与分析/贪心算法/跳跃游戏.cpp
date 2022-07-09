#include<iostream>
#include<vector>
using namespace std;

int main() {
	// 能够到达的例子
	vector<int> a = { 2,0,1,3,1,3,0,1,4,2,3,1,0,0 };
	//无法到达的例子
	//vector<int> a = { 2,0,1,3,1,3,0,1,4,2,3,1,0,0 };
	vector<int> maxTouchablePos(20);
	int N = a.size();
	int curPos = 0, target = N - 1;

	printf("a = [");
	for (int i = 0;i < target;i++) {
		printf(" %d,", a[i]);
	}
	printf(" %d ]\n", a[target]);

	for (int i = 0;i < N;i++) {
		maxTouchablePos[i] = i + a[i];
	}
	while (maxTouchablePos[curPos] != curPos && curPos < target) {
		int nextPos = curPos + 1;
		for (int i = curPos + 2;i <= min(maxTouchablePos[curPos], target);i++) {
			if (maxTouchablePos[i] > maxTouchablePos[nextPos]) {
				nextPos = i;
			}
		}
		curPos = nextPos;
	}

	if (curPos >= target) {
		printf("能够到达\n");
	}
	else {
		printf("无法到达\n");
	}

	return 0;
}
