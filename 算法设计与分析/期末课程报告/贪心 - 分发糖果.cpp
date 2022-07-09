#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> s = { 1, 2, 0, 3, 2, 1, 2, 0, 1 };
	vector<int> c(20);
	int n = s.size();
	int cnt = 0;

	printf("学生分数为：");
	for (int i = 0;i < n;i++) {
		printf(" %d", s[i]);
	}
	printf("\n");


	// 从左往右进行计算
	c[0] = 1;
	for (int i = 1;i < n;i++) {
		if (s[i] > s[i - 1]) {
			c[i] = c[i - 1] + 1;
		}
		else {
			c[i] = 1;
		}
	}

	// 从左往右进行计算
	for (int i = n - 2;i >= 0;i--) {
		if (s[i] > s[i + 1]) {
			c[i] = c[i + 1] + 1;
		}
	}

	// 计算总的糖果个数
	for (int i = 0;i < n;i++) {
		cnt += c[i];
	}

	printf("所需最少的糖果个数为：%d 个\n", cnt);
	printf("得糖情况为：");
	for (int i = 0;i < n;i++) {
		printf(" %d", c[i]);
	}


	return 0;
}