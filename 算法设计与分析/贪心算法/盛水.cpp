#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> a = { 1, 5, 8, 4, 2, 9, 7, 3, 4, 3 };
	vector<int> inc, dec;
	int maxL = 0, maxR = 0, maxV = 0;
	int l, r, V;
	int curMax = 0, curMin = a.size() - 1;
	inc.push_back(curMax);
	dec.push_back(curMin);
	for (int i = 1;i < a.size();i++) {
		if (a[i] > a[curMax]) {
			curMax = i;
			inc.push_back(curMax);
		}
	}
	for (int i = a.size() - 2;i >= 0;i--) {
		if (a[i] > a[curMin]) {
			curMin = i;
			dec.push_back(curMin);
		}
	}

	for (int i = 0;i < inc.size();i++) {
		l = inc[i];
		for (int j = 0;j < dec.size();j++) {
			r = dec[j];
			V = min(a[l], a[r]) * (r - l);
			if (V > maxV) {
				maxL = l;
				maxR = r;
				maxV = V;
			}
		}
	}
	printf("最大的盛水方式为:\n");
	printf("l = %d   a[l] =%d\n", maxL, a[maxL]);
	printf("r = %d   a[r] =%d\n", maxR, a[maxR]);
	printf("最大盛水体积为:%d\n", maxV);

	return 0;
}
