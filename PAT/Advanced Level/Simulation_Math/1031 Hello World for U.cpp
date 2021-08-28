#include<string>
#include<iostream>
using namespace std;

int main() {
	string input;
	cin >> input;
	int len = input.length(), n1 = (len + 2) / 3, n2 = len + 2 - 2 * n1;
	for (int i = 0;i < n1 - 1;i++) {
		string cur = "";
		cur += input[i];
		for (int j = 0;j < n2 - 2;j++) cur += ' ';
		cur += input[len - i - 1];
		cout << cur << endl;
	}
	cout << input.substr(n1 - 1, n2);
}