#include<iostream>
#include<string>
using namespace std;

int main() {
	//string s = "(()";
	string s = "()(()(())))()";
	int l = s.length();
	// longest valid part
	int lvp[100][100] = { 0 };
	// ≥ı ºªØ
	for (int i = 1;i < l;i++)
		if (s[i] == ')' && s[i - 1] == '(')
			lvp[i - 1][i] = 2;

	int indexI, indexJ, longest = 0;
	for (int j = 2;j < l;j++) {
		for (int i = j - 2;i >= 0;i--) {
			lvp[i][j] = lvp[i + 1][j];

			int p = j - lvp[i][j - 1] - 1;
			if (p >= i && s[j] == ')' && s[p] == '(')
				lvp[i][j] = max(lvp[i][j - 1] + 2, lvp[i][j]);

			for (int k = j - lvp[i][j];k > i;k--) {
				if (lvp[k + 1][j] == j - k)
					lvp[i][j] = max(lvp[i][j], lvp[k + 1][j] + lvp[i][k]);
			}

			if (lvp[i][j] > longest) {
				longest = lvp[i][j];
				indexI = i;
				indexJ = j;
			}
		}
	}
	cout << "indexI, indexJ:" << indexI << ' ' << indexJ << endl;
	cout << "longest valid part is:"
		<< s.substr(indexI, indexJ - indexI + 1) << endl;
	return 0;
}