#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

char name[40010][5];

bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}

int main() {
	int N, K, p, m;
	cin >> N >> K;
	vector<int> courMap[2510];
	for (int i = 0;i < N;i++) {
		scanf("%s %d", name[i], &m);
		for (int j = 0;j < m;j++) {
			scanf("%d", &p);
			courMap[p].push_back(i);
		}
	}
	for (int i = 1;i <= K;i++) {
		printf("%d %d\n", i, courMap[i].size());
		sort(courMap[i].begin(), courMap[i].end(), cmp);
		for (int id : courMap[i]) {
			printf("%s\n", name[id]);
		}
	}
	return 0;
}