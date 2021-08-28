#include<iostream>
#include<vector>
using namespace std;


int main() {
	vector<int> S(100010);
	int round, temp, N, M, p, q;
	cin >> N;
	S[1] = 0;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		S[i + 2] = S[i + 1] + temp;
	}
	round = S[N + 1];
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> p >> q;
		if (p > q) { temp = p;p = q;q = temp; }
		temp = S[q] - S[p];
		temp = (temp < round - temp) ? temp : round - temp;
		cout << temp << endl;
	}
	return 0;
}