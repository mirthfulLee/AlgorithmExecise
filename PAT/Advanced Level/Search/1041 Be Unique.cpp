#include<iostream>
#include<vector>
using namespace std;


int main() {
	int N;
	vector<int> a(100010), cnt;
	cin >> N;
	cnt.assign(10010, 0);
	for (int i = 0;i < N;i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int unique = 0;
	for (int i = N - 1;i >= 0;i--) {
		if (cnt[a[i]] == 1) unique = a[i];
	}
	if (unique) cout << unique;
	else cout << "None";
	return 0;
}