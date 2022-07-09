#include<iostream>
#include<string>
using namespace std;

string s = "acbcdkcdk";
string p = "a*cd?";
int n = s.length();
int m = p.length();

int main() {
	bool match[20][20];
	bool result;
	memset(match, false, 20 * 20);

	cout << "s = " << s << endl;
	cout << "p = " << p << endl;

	match[0][0] = true;
	if (p[0] == '*') {
		for (int j = 1;j < m;j++) {
			match[0][j] = true;
		}
	}
	else {
		for (int j = 1;j < m;j++) {
			match[0][j] = false;
		}
	}
	for (int i = 1;i < n;i++) {
		match[i][0] = false;
		for (int j = 1;j < m;j++) {
			if (p[j - 1] == '*') {
				match[i][j] = match[i - 1][j] || match[i][j - 1];
			}
			else {
				match[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && match[i - 1][j - 1];
			}
		}
	}
	result = match[n - 1][m - 1];
	cout << "Æ¥Åä½á¹ûÎª£º" << (result ? "true" : "false") << endl;

	return 0;
}