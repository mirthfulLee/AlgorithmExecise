//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/17.
//
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	string s;
	map<char, int> m;
	int maxn = 0, minn = 100;
	cin >> s;
	for (auto c : s) {
		m[c]++;
	}
	for (auto c : m) {
		if (c.second > maxn) maxn = c.second;
		if (c.second < minn) minn = c.second;
	}
	bool isPrime = maxn - minn > 1;
	for (int i = 2;i * i < maxn - minn;i++) {
		if ((maxn - minn) % i == 0) isPrime = false;
	}
	isPrime ? printf("%s\n%d", "Lucky Word", maxn - minn) : printf("%s\n%d", "No Answer", 0);
}