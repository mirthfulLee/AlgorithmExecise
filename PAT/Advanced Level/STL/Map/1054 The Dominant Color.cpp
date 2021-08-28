#include<iostream>
#include<map>
using namespace std;


int main() {
	int M, N, temp;
	map<int, int> cnt;
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> temp;
			cnt[temp]++;
		}
	}
	for (auto it = cnt.begin();it != cnt.end();it++) {
		if (it->second > cnt[temp]) temp = it->first;
	}
	cout << temp;
	return 0;
}