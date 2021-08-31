#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
	string t;
	int value;
};
bool cmp(const node& a, const node& b) {
	return a.value != b.value ? a.value > b.value : a.t < b.t;
}
int main() {
	int n, k, order;
	string s;
	cin >> n >> k;
	vector<node> v(n), ans;
	for (int i = 0; i < n; i++)
		cin >> v[i].t >> v[i].value;
	for (int i = 1; i <= k; i++) {
		cin >> order >> s;
		printf("Case %d: %d %s\n", i, order, s.c_str());
		ans.clear();
		int cnt = 0, sum = 0;
		if (order == 1) {
			for (int j = 0; j < n; j++)
				if (v[j].t[0] == s[0]) ans.push_back(v[j]);
		}
		else if (order == 2) {
			for (int j = 0; j < n; j++) {
				if (v[j].t.substr(1, 3) == s) {
					cnt++;
					sum += v[j].value;
				}
			}
			if (cnt != 0) printf("%d %d\n", cnt, sum);
		}
		else if (order == 3) {
			unordered_map<string, int> m;
			for (int j = 0; j < n; j++)
				if (v[j].t.substr(4, 6) == s) m[v[j].t.substr(1, 3)]++;
			for (auto it : m) ans.push_back({ it.first, it.second });
		}
		sort(ans.begin(), ans.end(), cmp);
		for (int j = 0; j < ans.size(); j++)
			printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
		if (((order == 1 || order == 3) && ans.size() == 0) || (order == 2 && cnt ==
			0)) printf("NA\n");
	}
	return 0;
}