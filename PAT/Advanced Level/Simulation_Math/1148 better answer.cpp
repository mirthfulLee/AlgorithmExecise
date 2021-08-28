#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> s;
int main() {
	int m, n, u, v, a;
	scanf("%d %d", &m, &n);
	vector<int> pre(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
		s.insert(pre[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		for (int j = 0; j < n; j++) {
			a = pre[j];
			if ((a >= u && a <= v) || (a >= v && a <= u)) break;
		}
		if (s.find(u) == s.end() && s.find(v) == s.end())
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if (s.find(u) == s.end() || s.find(v) == s.end())
			printf("ERROR: %d is not found.\n", s.find(u) == s.end() ? u : v);
		else if (a == u || a == v)
			printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
		else
			printf("LCA of %d and %d is %d.\n", u, v, a);
	}
	return 0;
}