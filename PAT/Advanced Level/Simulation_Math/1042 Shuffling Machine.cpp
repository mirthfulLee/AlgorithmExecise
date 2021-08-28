#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
	int K;
	string s;
	cin >> K;
	vector<string> per(60), cur(60);
	vector<int> a(60);
	for (int i = 1;i <= 13;i++) per[i] = "S" + to_string(i);
	for (int i = 1;i <= 13;i++) per[13 + i] = "H" + to_string(i);
	for (int i = 1;i <= 13;i++) per[26 + i] = "C" + to_string(i);
	for (int i = 1;i <= 13;i++) per[39 + i] = "D" + to_string(i);
	per[53] = "J1"; per[54] = "J2";
	for (int i = 1;i <= 54;i++) {
		cin >> a[i];
	}
	for (int t = 0;t < K;t++) {
		for (int i = 1;i <= 54;i++) {
			cur[a[i]] = per[i];
		}
		for (int i = 1;i <= 54;i++) {
			per[i] = cur[i];
		}
	}
	for (int i = 1;i < 54;i++) {
		cout << per[i] << ' ';
	}
	cout << per[54];

}