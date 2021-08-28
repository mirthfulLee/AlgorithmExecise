#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> pre(10010), father(10010);
int N, M, U, V, root, x, y, flagU, flagV;

void traverse(int f, int lo, int hi)
{
	if (lo > hi) return;
	father[lo] = f;
	if (lo == hi) return;
	int p = lo + 1;
	while (pre[p] < pre[lo] && p < hi) p++;
	traverse(lo, lo + 1, p - 1);
	traverse(lo, p, hi);
}

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> pre[i];
	}
	traverse(0, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V;
		flagU = 0; flagV = 0;
		for (int j = 0; j < N; j++)
		{
			if (pre[j] == U) {
				x = j; flagU = 1;
			}
			if (pre[j] == V) {
				y = j; flagV = 1;
			}
		}

		if (!flagU && !flagV) {
			printf("ERROR: %d and %d are not found.\n", U, V);
		}
		else if (!flagU) {
			printf("ERROR: %d is not found.\n", U);
		}
		else if (!flagV) {
			printf("ERROR: %d is not found.\n", V);
		}
		else {
			int a = x, b = y, LCA;
			stack<int> s1, s2;
			while (a != father[a]) {
				s1.push(pre[a]);
				a = father[a];
			}
			while (b != father[b]) {
				s2.push(pre[b]);
				b = father[b];
			}
			LCA = pre[0];
			while (!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
				LCA = s1.top();
				s1.pop(); s2.pop();
			}
			if (s1.empty()) {
				printf("%d is an ancestor of %d.\n", U, V);
			}
			else if (s2.empty()) {
				printf("%d is an ancestor of %d.\n", V, U);
			}
			else {
				printf("LCA of %d and %d is %d.\n", U, V, LCA);
			}
		}
	}
	return 0;
}