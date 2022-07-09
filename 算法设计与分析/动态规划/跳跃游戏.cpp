#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> nums = { 2,3,0,5,2,0,0,0,2,2,0,1,1 };
	int n = nums.size();
	vector<bool> reachable;
	reachable.resize(n + 10, false);
	reachable[0] = true;
	for (int i = 0;i < n;i++) {
		if (reachable[i]) {
			for (int k = 1;k <= nums[i];k++) {
				reachable[i + k] = true;
			}
		}
	}
	cout << (reachable[n - 1] ? "true" : "false");
}