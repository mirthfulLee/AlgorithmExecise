//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/12.
//
#include<iostream>
#include<string>
using namespace std;

int K, L, lo;

int isPrime(int k) {
	for (int i = 2;i * i < k;i++) {
		if (k % i == 0) return 0;
	}
	return 1;
}

int main() {
	string s;
	cin >> L >> K >> s;
	for (int i = 0;i <= L - K;i++) {
		string t = s.substr(i, K);
		int num = stoi(t);
		if (isPrime(num)) {
			cout << t;
			return 0;
		}
	}
	cout << "404\n";
}