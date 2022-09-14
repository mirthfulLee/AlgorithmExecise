// 202203-5 博弈论与石子合并
// https://icode.best/i/33996048391433
#include <iostream>
#include <cstdio>
using namespace std;
#define N 100005
int n, a[N];
bool k;

void subtask1() {
	int res = 0, SIZE = (n >> 1) + 1, ans = 1e9;
	for(int i = 1; i <= n; ++i) {
		res += a[i];
		if(i >= SIZE) res -= a[i - SIZE], ans = min(ans, res);
	}
	cout << ans << endl;
}

bool check(int x) {
	int res = 0, cnt = 0;
	for(int i = 1; i <= n; ++i) {
		res += a[i];
		if(res >= x) res = 0, ++cnt;
	}
	return cnt > n / 2;
}

void subtask2() {
	int l = 1, r = 1e9, mid, ans = 0;
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	if((n & 1) ^ k) subtask1();
	else subtask2();

	return 0;
}