//
// Created by Ä¾×ÓÓÖÇ· on 2021/4/15.
//
#include<iostream>
#include<set>
using namespace std;

set<int> s;
int n, a, t = 1;

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		scanf("%d", &a);
		s.insert(a);
	}
	while (s.find(t) != s.end()) t++;
	printf("%d", t);
}