#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int cnt[300];
string input, shown;

int main() {
	cin >> input >> shown;
	for (char c : shown) {
		cnt[toupper(c)]++;
	}
	for (char c : input) {
		char ch = toupper(c);
		if (!cnt[ch]) {
			cout << ch;
			cnt[ch]++;
		}
	}
	return 0;
}