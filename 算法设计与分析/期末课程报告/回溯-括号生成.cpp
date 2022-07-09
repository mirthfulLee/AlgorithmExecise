#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> x(20);
int n = 2;
int cnt = 0;

int max(int a, int b) {
	return a > b ? a : b;
}

void printResult() {
	cnt++;
	string s = "";
	for (int i = 0;i < 2 * n;i++) {
		s += '(';
	}
	for (int i = 0;i < n;i++) {
		s[x[i]] = ')';
	}
	cout << s << endl;
}

void attempt(int t) {
	if (t == n) {
		printResult();
		return;
	}
	if (t == 0) {
		for (int i = 1;i <= n;i++) {
			x[t] = i;
			attempt(t + 1);
		}
	}
	else {
		for (int i = max(x[t - 1] + 1, 2 * t + 1);i <= n + t;i++) {
			x[t] = i;
			attempt(t + 1);
		}
	}
}


int main() {
	printf("n=%d\n", n);
	attempt(0);
	printf("共有%d种可能", cnt);

	return 0;
}