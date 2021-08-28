#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	int N, K, p, m;
	string s;
	cin >> N >> K;
	map<string, vector<int>> stuMap;
	for (int i = 0;i < K;i++) {
		cin >> p >> m;
		for (int j = 0;j < m;j++) {
			cin >> s;
			stuMap[s].push_back(p);
		}
	}
	for (int i = 0;i < N;i++) {
		cin >> s;
		cout << s << ' ' << stuMap[s].size();
		sort(stuMap[s].begin(), stuMap[s].end());
		for (int t : stuMap[s]) cout << ' ' << t;
		cout << endl;

	}
}