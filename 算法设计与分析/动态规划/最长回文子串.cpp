#include<iostream>
#include<string>
using namespace std;

int main() {
	//string s = "babad";
	string s = "ssahhhhassgjiwnnsllllsnwij";
	int l = s.length();
	int pld[100][100] = { 0 };
	// ≥ı ºªØ
	pld[0][0] = 1;
	for (int i = 1;i < l;i++) {
		pld[i][i] = 1;
		if (s[i] == s[i - 1]) pld[i - 1][i] = 2;
	}
	int maxI, maxJ, longest = 0;
	for (int j = 2;j < l;j++) {
		for (int i = j - 2;i >= 0;i--) {
			int p = j - pld[i][j - 1] - 1;
			if (p >= i && s[j] == s[p])
				pld[i][j] = max(pld[i][j - 1] + 2, pld[i + 1][j]);
			else pld[i][j] = pld[i + 1][j];
			if (pld[i][j] > longest) {
				longest = pld[i][j];
				maxI = i;
				maxJ = j;
			}
		}
	}
	cout << "maxI, maxJ:" << maxI << ' ' << maxJ << endl;
	cout << "longest substr is:" << s.substr(maxI, maxJ - maxI + 1) << endl;
	return 0;
}