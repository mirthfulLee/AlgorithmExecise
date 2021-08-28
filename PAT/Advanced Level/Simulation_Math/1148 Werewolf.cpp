#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> p(100);

bool tellingTruth(int a, int b, int t) {
	return (abs(p[t]) != a && abs(p[t]) != b && p[t] > 0) || (p[t] == -a || p[t] == -b);
}

// a, b are wolf, 
// assume a, b don't point at themselves
// a tell a truth, b tell a lie
bool legal(int a, int b) {
	int cnt = 0;
	if (tellingTruth(a, b, a) && !tellingTruth(a, b, b)) {
		for (int k = 1;k <= N;k++) {
			if (k != b && !tellingTruth(a, b, k)) {
				cnt++;
			}
		}
		if (cnt == 1) return true;
	}
	return false;
}

// positive for human and negtive for wolf
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1;j <= N;j++) {
			if (legal(i, j) || legal(j, i)) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	cout << "No Solution";
	return 0;
}