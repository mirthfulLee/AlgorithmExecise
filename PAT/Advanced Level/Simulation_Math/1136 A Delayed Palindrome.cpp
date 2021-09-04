#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(vector<int>& v) {
	for (int i = 0;i < v.size() / 2;i++) {
		if (v[i] != v[v.size() - i - 1]) return false;
	}
	return true;
}

int main() {
	string s;
	vector<int> ans, temp;
	cin >> s;
	for (int i = s.size() - 1;i >= 0;i--) ans.push_back(s[i] - '0');
	for (int attempt = 0;attempt < 10;attempt++) {
		if (isPalindrome(ans))
			break;
		int k = ans.size();
		for (int i = k - 1;i >= 0;i--) printf("%d", ans[i]);
		printf(" + ");
		for (int i = 0;i < k;i++) printf("%d", ans[i]);
		printf(" = ");
		temp = ans;
		for (int i = 0;i < k;i++) {
			ans[i] = temp[i] + temp[k - i - 1];
		}
		for (int i = 0;i < k - 1;i++) {
			ans[i + 1] += ans[i] / 10;
			ans[i] = ans[i] % 10;
		}
		while (ans.back() >= 10) {
			ans.push_back(ans.back() / 10);
			ans[ans.size() - 2] %= 10;
		}
		for (int i = ans.size() - 1;i >= 0;i--) printf("%d", ans[i]);
		printf("\n");
	}

	if (isPalindrome(ans)) {
		for (int i = ans.size() - 1;i >= 0;i--) printf("%d", ans[i]);
		printf(" is a palindromic number.");
	}
	else {
		printf("Not found in 10 iterations.");
	}
}