#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> nums = { 1, 2, 7, 5, 5, 4, 6, 9, 3, 2, 5, 3, 6, 7, 8, 5 };
	vector<int> result;
	int N = nums.size();
	int curP, nextP, cnt, curGrad, prevGrad;
	curP = 0;
	prevGrad = 0;
	result.push_back(0);
	// 找到第一段单向波动的方向
	do {
		curP++;
		prevGrad = nums[curP] - nums[curP - 1];
	} while (prevGrad == 0 && curP < N);
	// 找到第一段单向波动的结束位置
	while (curP < N - 1 && (nums[curP + 1] - nums[curP]) * prevGrad >= 0) {
		curP++;
	}
	result.push_back(curP);
	while (curP < N - 1) {
		curGrad = -prevGrad;
		nextP = curP + 1;
		while (nextP < N - 1 && (nums[nextP + 1] - nums[nextP]) * curGrad >= 0) {
			nextP++;
		}
		if (nums[nextP] != nums[curP]) {
			result.push_back(nextP);
			prevGrad = curGrad;
		}
		curP = nextP;
	}
	cout << "最长摆动子序列的长度为：" << result.size() << endl;
	for (int i = 0;i < result.size();i++) {
		cout << nums[result[i]] << ' ';
	}
	return 0;
}